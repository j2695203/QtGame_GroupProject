#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QtWidgets>

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

};

#endif // LOGIN_H
