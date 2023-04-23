#ifndef FIREBASEAUTH_H
#define FIREBASEAUTH_H

#include <QJsonDocument>
#include <QMap>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QObject>
#include <QVariantMap>
#include "user.h"
#include <string>
class FirebaseAuth : public QObject
{
    Q_OBJECT
public:
    explicit FirebaseAuth(QObject *parent = nullptr);
    User *user;
    void setUser(User *user) { this->user = user; }
    void signUserUp(QString emailAddress, QString password);
    QNetworkAccessManager *networkAccessManager;

public slots:
    void networkReplyResponse();

private:
    QString apiKey = "AIzaSyBwgJWz_F7Wu_UzKlxw0D8AZCFHAyvKAJc";
    void performPOST(QString &url, QJsonDocument &payload);

    QNetworkReply *networkReply;

signals:
};

#endif // FIREBASEAUTH_H
