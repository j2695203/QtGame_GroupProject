#ifndef LOGIN_H
#define LOGIN_H

#include <QProgressBar>
#include <QWidget>
#include <QtWidgets>
#include "firebasesignin.h"
#include "signuppage.h"

class Login : public QWidget
{
    Q_OBJECT

    // widgets
    QLabel *intro_lb;
    QLabel *username_lb;
    QLabel *password_lb;
    QLabel *errorMsg_lb;
    QLabel *orMsg_lb;

    QLineEdit *username_te;
    QLineEdit *password_te;

    QPushButton *login_bt;
    QPushButton *signup_bt;
    QPushButton *guest_bt;
    User *user = new User;
    // layouts
    QVBoxLayout *mainLayout;
    QGridLayout *gLayout;
    QHBoxLayout *buttomLayout;



public:
    explicit Login(QWidget *parent = nullptr);

signals:

public slots:
    void pressLogin();
    void pressSignUp();
    void pressGuest();


private:
    FirebaseSignIn signIn;
};

#endif // LOGIN_H
