#ifndef FIREBASEDBHELPER_H
#define FIREBASEDBHELPER_H

#include <QDebug>
#include <QFuture>
#include <QJsonDocument>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QObject>
#include <QVariantMap>
#include <QWidget>
#include <QtConcurrent/QtConcurrent>
#include <user.h>

class FirebaseDBHelper : public QObject
{
    Q_OBJECT
public:
    explicit FirebaseDBHelper(QObject *parent = nullptr);
    ~FirebaseDBHelper() { this->networkManager->deleteLater(); }

    QNetworkAccessManager *getNetworkManager() { return networkManager; }
    void uploadToDatabase(User *user);
    QMap<QString, int> sortRankScore();

    void setScore(User *user, int score);

private:
    QNetworkAccessManager *networkManager;
    QNetworkReply *networkReply;

signals:
};

#endif // FIREBASEDBHELPER_H
