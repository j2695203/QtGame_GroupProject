#ifndef FIREBASESIGNIN_H
#define FIREBASESIGNIN_H

#include <QJsonDocument>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QObject>
#include <QVariantMap>
#include "user.h"
#include <firebasedbhelper.h>
class FirebaseSignIn : public QObject
{
    Q_OBJECT
public:
    explicit FirebaseSignIn(QObject *parent = nullptr);
    void signUserIn(QString username, QString password);
    QNetworkReply *networkReply;
    User *user;
    void setUser(User *user) { this->user = user; }
public slots:
    void networkReplyResponse();
    void importUserInfo();

private:
    QString apiKey = "AIzaSyBwgJWz_F7Wu_UzKlxw0D8AZCFHAyvKAJc";
    QNetworkAccessManager *networkAccessManager;
    void performPOST(QString &url, QJsonDocument &payload);
signals:

};

#endif // FIREBASESIGNIN_H
