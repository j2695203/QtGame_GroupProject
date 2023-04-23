#ifndef FIREBASESTORAGE_H
#define FIREBASESTORAGE_H

#include <QFile>
#include <QJsonDocument>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QObject>
#include <user.h>
class FirebaseStorage : public QObject
{
    Q_OBJECT
public:
    explicit FirebaseStorage(QObject *parent = nullptr);
    QNetworkAccessManager *networkManager;
    void uploadToStorage(QByteArray fileData, QString fileType);
    ~FirebaseStorage() { networkManager->deleteLater(); }

    void setUser(User *user) { this->user = user; }
signals:

public slots:
    void networkReplyFromServer(QString fileType);

private:
    User *user;
    QString bucketName = "cs6015-final.appspot.com";
    QNetworkReply *networkReply;
};

#endif // FIREBASESTORAGE_H
