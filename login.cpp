#include "login.h"
#include <QFont>
#include "game1scene.h"
Login::Login(QWidget *parent)
    : QWidget{parent}
{
    // create widgets
    intro_lb = new QLabel("Welcome to Void Game");
    username_lb = new QLabel("Username");
    password_lb = new QLabel("Password");
    errorMsg_lb = new QLabel("Username doesn't exist / Wrong password");
    errorMsg_lb->hide();
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
    gLayout->addWidget(signup_bt, 6, 0);
    gLayout->addWidget(guest_bt, 6, 1);

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

void Login::pressLogin()
{
    signIn.setUser(user);
    signIn.signUserIn(username_te->text(), password_te->text());

    connect(signIn.networkReply, &QNetworkReply::finished, this, [this]() {
        if (!signIn.isLogin) {
            errorMsg_lb->show();
        } else {
            connect(&signIn, &FirebaseSignIn::finishedImportUserInfo, this, [this]() {
                QGraphicsView *mainView = new QGraphicsView();

                game1scene *scene1 = new game1scene(user);
                mainView->setScene(scene1);
                mainView->setFixedSize(910, 485);
                mainView->setHorizontalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
                mainView->setVerticalScrollBarPolicy((Qt::ScrollBarAlwaysOff));

                mainView->show();
                this->close();
            });
        }
        qDebug() << user->username + "Hellooooo";
    });
}

void Login::pressSignUp()
{
    SignUpPage *signUpPage = new SignUpPage();
    signUpPage->show();
}

void Login::pressGuest()
{
    QGraphicsView *mainView = new QGraphicsView();
    game1scene *scene1 = new game1scene(user);
    mainView->setScene(scene1);
    mainView->setFixedSize(910, 485);
    mainView->setHorizontalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    mainView->setVerticalScrollBarPolicy((Qt::ScrollBarAlwaysOff));

    mainView->show();
    this->close();
}
