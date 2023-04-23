#ifndef USER_H
#define USER_H

#include <QObject>

class User : public QObject
{
    Q_OBJECT
public:
    QString username;
    QString firstName;
    QString lastName;
    QString localID;
    QString imageURL;
    int score = 0;
    QString birthday;

signals:
};

#endif // USER_H
