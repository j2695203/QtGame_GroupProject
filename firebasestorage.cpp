#include "firebasestorage.h"
#include <QCoreApplication>
#include "QtCore/qjsonobject.h"

FirebaseStorage::FirebaseStorage(QObject *parent)
    : QObject{parent}
{
    networkManager = new QNetworkAccessManager(this);
}

void FirebaseStorage::uploadToStorage(QByteArray fileData, QString fileType)
{
    QNetworkRequest networkRequest((QUrl("https://firebasestorage.googleapis.com/v0/b/" + bucketName
                                         + "/o/" + this->user->username + "." + fileType)));
    networkRequest.setHeader(QNetworkRequest::ContentTypeHeader, "image." + fileType);
    networkReply = networkManager->post(networkRequest, fileData);

    connect(networkReply, &QNetworkReply::readyRead, this, [fileType, this]() {
        networkReplyFromServer(fileType);
    });
}

void FirebaseStorage::networkReplyFromServer(QString fileType)
{
    if (networkReply->error() == QNetworkReply::NoError) {
        QString response = networkReply->readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(response.toUtf8());
        QJsonObject jsonObj = jsonDoc.object();
        //https://firebasestorage.googleapis.com/v0/b/cs6015-final.appspot.com/o/example.png?alt=media&token=9fa18a61-6665-4617-9a77-9555d9834882
        this->user->imageURL
            = "https://firebasestorage.googleapis.com/v0/b/cs6015-final.appspot.com/o/"
              + this->user->username + "." + fileType
              + "?alt=media&token=" + jsonObj["downloadTokens"].toString();
        qDebug() << "File uploaded successfully. Response:" << response;
    } else {
        qDebug() << "Failed to upload file. Error:" << networkReply->errorString();
    }
    networkReply->deleteLater();
}
