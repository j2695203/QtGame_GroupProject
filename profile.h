#ifndef PROFILE_H
#define PROFILE_H

#include <QWidget>
#include <QtWidgets>
#include "user.h"

class profile : public QWidget
{
    Q_OBJECT
    User *user;
    QLabel *title = new QLabel("My Profile");
    QLabel *username = new QLabel();
    QLabel *birthday = new QLabel();
    QLabel *lastName = new QLabel();
    QLabel *firstName = new QLabel();
    QLabel *pic = new QLabel();

    QVBoxLayout *mainLayout = new QVBoxLayout();

public:
    profile(User *user);

signals:
};

#endif // PROFILE_H
