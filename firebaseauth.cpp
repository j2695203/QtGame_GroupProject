#include "firebaseauth.h"
#include "QtCore/qjsonobject.h"
#include "signuppage.h"

FirebaseAuth::FirebaseAuth(QObject *parent)
    : QObject{parent}
{
    networkAccessManager = new QNetworkAccessManager(this);
}

void FirebaseAuth::signUserUp(QString emailAddress, QString password)
{
    QString signUpEndpoint = "https://identitytoolkit.googleapis.com/v1/accounts:signUp?key="
                             + this->apiKey;
    QVariantMap variantPayload;
    variantPayload["email"] = emailAddress;
    variantPayload["password"] = password;
    variantPayload["returnSecureToken"] = true;
    QJsonDocument jsonPayload = QJsonDocument::fromVariant(variantPayload);
    performPOST(signUpEndpoint, jsonPayload);
}

void FirebaseAuth::networkReplyResponse()
{
    QString reply = networkReply->readAll();
    qDebug() << reply;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(reply.toUtf8());
    QJsonObject jsonObj = jsonDoc.object();

    if (jsonObj.contains("error")) {
        qDebug() << "The username exist & code: 400";
        reply = "";
        emit isUsernameExist(true);
    }

    if (jsonObj.contains("kind")) {
        this->user->localID = jsonObj["localId"].toString();
        qDebug() << this->user->localID;
        emit isUsernameExist(false);
    }
    networkReply->deleteLater();
}

void FirebaseAuth::performPOST(QString &url, QJsonDocument &payload)
{
    QNetworkRequest newRequest((QUrl(url)));
    newRequest.setHeader(QNetworkRequest::ContentTypeHeader, QString("application/json"));
    networkReply = networkAccessManager->post(newRequest, payload.toJson());
    connect(networkReply, &QNetworkReply::readyRead, this, &FirebaseAuth::networkReplyResponse);
}
