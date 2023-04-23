#include "firebasesignin.h"
#include "QtCore/qjsonobject.h"
#include "QtWidgets/qgraphicsview.h"
#include "game1scene.h"

FirebaseSignIn::FirebaseSignIn(QObject *parent)
    : QObject{parent}
{
    this->networkAccessManager = new QNetworkAccessManager(this);
}

void FirebaseSignIn::signUserIn(QString username, QString password)
{
    QString signInEndPoint
        = "https://identitytoolkit.googleapis.com/v1/accounts:signInWithPassword?key="
          + this->apiKey;
    QVariantMap variantPayload;
    variantPayload["email"] = username + "@gmail.com";
    variantPayload["password"] = password;
    variantPayload["returnSecureToken"] = true;
    QJsonDocument jsonPayload = QJsonDocument::fromVariant(variantPayload);
    performPOST(signInEndPoint, jsonPayload);
}

void FirebaseSignIn::networkReplyResponse()
{
    QString reply = networkReply->readAll();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(reply.toUtf8());
    QJsonObject jsonObj = jsonDoc.object();
    qDebug() << reply;
    //If success load the user info and open a new window
    if (jsonObj.contains("kind") && jsonObj["registered"] == true) {
        qDebug() << "Login Success";
        QString localId = jsonObj["localId"].toString();
        qDebug() << localId;
        networkReply = networkAccessManager->get(QNetworkRequest(
            QUrl("https://cs6015-final-default-rtdb.firebaseio.com/User/" + localId + ".json")));

        connect(networkReply, &QNetworkReply::readyRead, this, &FirebaseSignIn::importUserInfo);

        isLogin = true;
    }

    //else show the error message
}

void FirebaseSignIn::importUserInfo()
{
    QString databaseReply = networkReply->readAll();
    qDebug() << databaseReply;
    QJsonDocument userJsonDoc = QJsonDocument::fromJson(databaseReply.toUtf8());
    QJsonObject userJsonObj = userJsonDoc.object();
    this->user->username = userJsonObj["username"].toString();
    this->user->firstName = userJsonObj["firstname"].toString();
    this->user->lastName = userJsonObj["lastname"].toString();
    this->user->score = userJsonObj["score"].toInt();
    this->user->imageURL = userJsonObj["imageURL"].toString();
    this->user->birthday = userJsonObj["birthday"].toString();

    emit finishedImportUserInfo();
    //    QGraphicsView *mainView = new QGraphicsView();

    //    game1scene *scene1 = new game1scene(user);
    //    mainView->setScene(scene1);
    //    mainView->setFixedSize(910, 512);
    //    mainView->setHorizontalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    //    mainView->setVerticalScrollBarPolicy((Qt::ScrollBarAlwaysOff));

    //    mainView->show();

    //Add more info here
    networkReply->deleteLater();
}

void FirebaseSignIn::performPOST(QString &url, QJsonDocument &payload)
{
    QNetworkRequest newRequest((QUrl(url)));
    newRequest.setHeader(QNetworkRequest::ContentTypeHeader, QString("application/json"));
    networkReply = networkAccessManager->post(newRequest, payload.toJson());
    connect(networkReply, &QNetworkReply::readyRead, this, &FirebaseSignIn::networkReplyResponse);
}
