#ifndef SIGNUPPAGE_H
#define SIGNUPPAGE_H

#include <QDateEdit>
#include <QFileDialog>
#include <QLabel>
#include <QObject>
#include <QRegularExpression>
#include <QSpacerItem>
#include <QWidget>
#include "QtWidgets/qboxlayout.h"
#include "QtWidgets/qlineedit.h"
#include "QtWidgets/qpushbutton.h"
#include "firebaseauth.h"
#include "firebasesignin.h"
#include "firebasestorage.h"
#include "user.h"
class SignUpPage : public QWidget
{
    Q_OBJECT
public:
    SignUpPage();
    QLabel *profileLabel;
    //    ~SignUpPage()
    //    {
    //        firebaseStorage->deleteLater();
    //        firebaseSignIn->deleteLater();
    //        dbHelper->deleteLater();
    //        firebaseAuth->deleteLater();
    //    }
    User *user;

private slots:
    void loadProfilePic();
    void signUserUp(QString password);
    void uploadToStorage();
    void uploadToFirebase();
    void closeAll();

private:
    FirebaseStorage *firebaseStorage;
    FirebaseSignIn *firebaseSignIn;
    FirebaseDBHelper *dbHelper;
    FirebaseAuth *firebaseAuth;

    QByteArray fileData;
    QString fileType;
};

#endif // SIGNUPPAGE_H
