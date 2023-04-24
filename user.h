#ifndef USER_H
#define USER_H

#include <QObject>
#include "QtCore/qvariant.h"

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
    QList<QVariant> rankScore;

signals:
};

#endif // USER_H
