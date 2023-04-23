#include "login.h"
#include <QFont>

Login::Login(QWidget *parent)
    : QWidget{parent}
{
    // create widgets
    intro_lb = new QLabel("Welcome to Void Game");
    username_lb = new QLabel("Username");
    password_lb = new QLabel("Password");
    errorMsg_lb = new QLabel("Username doesn't exist / Wrong password");
    orMsg_lb = new QLabel("or");

    username_te = new QLineEdit();
    password_te = new QLineEdit();

    login_bt = new QPushButton("LOGIN");
    signup_bt = new QPushButton("SIGN UP");
    guest_bt = new QPushButton("as GUEST");

    // create layouts
    gLayout = new QGridLayout;

    // add widgets to login layout
    gLayout->addWidget(intro_lb,0,0,1,0,Qt::AlignCenter);
    gLayout->addWidget(username_lb,1,0);
    gLayout->addWidget(username_te,1,1);
    gLayout->addWidget(password_lb,2,0);
    gLayout->addWidget(password_te,2,1);
    gLayout->addWidget(errorMsg_lb,3,0,1,0,Qt::AlignCenter);
    gLayout->addWidget(login_bt,4,0,1,0);//
    gLayout->addWidget(orMsg_lb,5,0,1,0,Qt::AlignCenter);
    gLayout->addWidget(signup_bt,6,0,1,2);
    gLayout->addWidget(guest_bt,6,1,1,1);

    // set main layout to window
    setLayout(gLayout);

    // set up style
    gLayout->setContentsMargins(50,100,50,100);
    QFont title("Marker Felt",20,75);
    intro_lb->setFont(title);
    errorMsg_lb->setStyleSheet("color:red;");

    // connect to slots
    connect(login_bt, &QPushButton::clicked, this, &Login::pressLogin);
    connect(signup_bt, &QPushButton::clicked, this, &Login::pressSignUp);
    connect(guest_bt, &QPushButton::clicked, this, &Login::pressGuest);
}

void Login::pressLogin(){

}

void Login::pressSignUp(){

}

void Login::pressGuest(){

}
