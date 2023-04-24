#include "firebasedbhelper.h"
#include "QtCore/qjsonobject.h"
FirebaseDBHelper::FirebaseDBHelper(QObject *parent)
    : QObject{parent}
{
    networkManager = new QNetworkAccessManager(this);
}

void FirebaseDBHelper::uploadToDatabase(User *user)
{
    QVariantMap userChildDetail;
    QVariantList userRankScore;

    //    foreach (auto score, user->rankScore) {
    userRankScore.append("");
    //    }
    userChildDetail["firstname"] = user->firstName;
    userChildDetail["lastname"] = user->lastName;
    userChildDetail["username"] = user->username;
    userChildDetail["score"] = user->score;
    userChildDetail["imageUrl"] = user->imageURL;
    userChildDetail["birthday"] = user->birthday;
    userChildDetail["rankHistory"] = userRankScore;

    QVariantMap userParent;
    userParent[user->localID] = userChildDetail;
    QJsonDocument jsonDoc = QJsonDocument::fromVariant(userParent);

    QNetworkRequest userRequest(QUrl("https://cs6015-final-default-rtdb.firebaseio.com/User.json"));
    userRequest.setHeader(QNetworkRequest::ContentTypeHeader, QString("application/json"));
    qDebug() << jsonDoc.toJson().toStdString();

    this->networkManager->sendCustomRequest(userRequest, "PATCH", jsonDoc.toJson());
}

QMap<QString, int> FirebaseDBHelper::sortRankScore()
{
    QMap<QString, int> rankList;
    QEventLoop loop;
    networkReply = networkManager->get(
        QNetworkRequest(QUrl("https://cs6015-final-default-rtdb.firebaseio.com/User.json")));
    connect(networkReply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    QString databaseReply = networkReply->readAll();
    //        //        qDebug() << databaseReply;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(databaseReply.toUtf8());
    QJsonObject jsonObj = jsonDoc.object();
    foreach (QString key, jsonObj.keys()) {
        QString username = jsonObj.value(key).toObject().value("username").toString();
        int score = jsonObj.value(key).toObject().value("score").toInt();
        //        rankList.append(score);
        rankList.insert(username, score);
    }

    return rankList;
}

void FirebaseDBHelper::setScore(User *user, int score)
{
    if (user->username != "") {
        QVariantMap userNewScore;
        userNewScore["score"] = score;

        QJsonDocument jsonDoc = QJsonDocument::fromVariant(userNewScore);

        QNetworkRequest userRequest(QUrl("https://cs6015-final-default-rtdb.firebaseio.com/User/"
                                         + user->localID + ".json"));
        userRequest.setHeader(QNetworkRequest::ContentTypeHeader, QString("application/json"));

        this->networkManager->sendCustomRequest(userRequest, "PATCH", jsonDoc.toJson());
    }
}

void FirebaseDBHelper::addHistoryScore(User *user, int score)
{
    if (user->username != "") {
        QVariantMap userAddRankNewScore;
        user->rankScore.append(score);
        userAddRankNewScore["rankHistory"] = user->rankScore;

        QJsonDocument jsonDoc = QJsonDocument::fromVariant(userAddRankNewScore);

        QNetworkRequest userRequest(QUrl("https://cs6015-final-default-rtdb.firebaseio.com/User/"
                                         + user->localID + ".json"));
        userRequest.setHeader(QNetworkRequest::ContentTypeHeader, QString("application/json"));

        this->networkManager->sendCustomRequest(userRequest, "PATCH", jsonDoc.toJson());
    }
}
