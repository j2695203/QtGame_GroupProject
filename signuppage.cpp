#include "signuppage.h"
#include "QtGui/qmovie.h"

SignUpPage::SignUpPage()
{
    //Init stuff
    user = new User;
    firebaseStorage = new FirebaseStorage();
    firebaseSignIn = new FirebaseSignIn();
    dbHelper = new FirebaseDBHelper();
    firebaseAuth = new FirebaseAuth();
    firebaseAuth->setUser(user);
    firebaseSignIn->setUser(user);
    firebaseStorage->setUser(user);

    //Widget stuff
    layout = new QGridLayout();
    QLabel *firstNameLabel = new QLabel("First Name: ");
    QLineEdit *qFirstNameEdit = new QLineEdit();
    qFirstNameEdit->setPlaceholderText("Enter first name");
    QLabel *lastNameLabel = new QLabel("Last Name: ");
    QLineEdit *qLastNameEdit = new QLineEdit();
    qLastNameEdit->setPlaceholderText("Enter last name");

    QLabel *usernameLabel = new QLabel("Username: ");
    QLineEdit *userName = new QLineEdit();
    userName->setPlaceholderText("Enter username");

    QLabel *warning = new QLabel();
    warning->hide();
    warning->setStyleSheet("color:red;");

    QLabel *passwordLabel = new QLabel("Password: ");
    QLineEdit *password = new QLineEdit();
    password->setEchoMode(QLineEdit::Password);
    password->setPlaceholderText("Enter password");
    QPushButton *showPasswordBtn = new QPushButton("Show Password");
    connect(showPasswordBtn, &QPushButton::released, [password]() {
        if (password->echoMode() == QLineEdit::Normal) {
            password->setEchoMode(QLineEdit::Password);
        } else {
            password->setEchoMode(QLineEdit::Normal);
        }
    });

    QLabel *birthdayLabel = new QLabel("Birthday: ");
    QDateEdit *birthday = new QDateEdit();
    birthday->setMinimumDate(QDate(1900, 1, 1));
    birthday->setMaximumDate(QDate::currentDate());
    birthday->setDisplayFormat("MM/dd/yyyy");

    profileLabel = new QLabel("Avatar: ");
    QPushButton *loadFileBtn = new QPushButton("Pick Avatar");
    connect(loadFileBtn, &QPushButton::released, [this]() { loadProfilePic(); });

    QPushButton *saveToDatabase = new QPushButton("Save to Firebase");
    connect(saveToDatabase,
            &QPushButton::released,
            this,
            [qLastNameEdit, qFirstNameEdit, userName, password, birthday, this, warning]() {
                QRegularExpression regex("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d).{8,}$");
                QRegularExpressionMatch match = regex.match(password->text());
                if ( userName->text() == "" || qFirstNameEdit->text() == "" || qLastNameEdit->text() == "" || password->text() == "" ){
                    warning->show();
                    layout->addWidget(warning, 5, 1);
                    warning->setText("No Empty Spaces");
                }else if(match.hasMatch() ) {
                    //Check with database username if it username exist

                    user->username = userName->text().replace(" ", "");
                    user->firstName = qFirstNameEdit->text().replace(" ", "");
                    user->lastName = qLastNameEdit->text().replace(" ", "");
                    user->birthday = birthday->date().toString();
                    this->signUserUp(password->text().replace(" ", ""));

                } else {
                    warning->show();
                    layout->addWidget(warning, 5, 1);
                    warning->setText("Wrong password format");
                }
            });
    QPushButton *closeBtn = new QPushButton("Close");
    connect(closeBtn, &QPushButton::released, this, &SignUpPage::closeAll);
    //    QPushButton *signIn = new QPushButton("Sign In");
    //    QObject::connect(signIn, &QPushButton::released, [&userName, &firebaseSignIn]() {
    //        //        user->username = userName->text();
    //        firebaseSignIn.signUserIn(userName->text() + "@gmail.com", "password123");
    //        FirebaseSignIn::connect(firebaseSignIn.networkReply,
    //                                &QNetworkReply::readyRead,
    //                                [&firebaseSignIn]() { firebaseSignIn.networkReplyResponse(); });
    //    });

    layout->addWidget(usernameLabel, 0, 0);
    layout->addWidget(userName, 0, 1);
    layout->addWidget(passwordLabel, 1, 0);
    layout->addWidget(password, 1, 1);

    layout->addWidget(firstNameLabel, 2, 0);
    layout->addWidget(qFirstNameEdit, 2, 1);
    layout->addWidget(lastNameLabel, 3, 0);
    layout->addWidget(qLastNameEdit, 3, 1);

    layout->addWidget(birthdayLabel, 4, 0);
    layout->addWidget(birthday, 4, 1);

    layout->addWidget(profileLabel, 6, 0);
    layout->addWidget(loadFileBtn, 6, 1);

    layout->addWidget(saveToDatabase, 10, 1);
    layout->addWidget(showPasswordBtn, 1, 2);
    //    layout->addWidget(closeBtn, 7, 2);
    this->setLayout(layout);
    this->setContentsMargins(50,60,50,60);
    setWindowTitle("Sign Up");

}

void SignUpPage::loadProfilePic()
{
    QString defaultPath = QDir::homePath();
    QString file_name = QFileDialog::getOpenFileName(this,
                                                     "Open a file",
                                                     defaultPath,
                                                     "Images (*.png *.jpg)");

    QFile file(file_name);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open file";
    } else {
        profileLabel->setText("Upload Success!");
    }
    fileData = file.readAll();
    QFileInfo fileInfo(file);
    fileType = fileInfo.completeSuffix();
    file.close();
}

void SignUpPage::signUserUp(QString password)
{
    QLabel *label = new QLabel();
    QMovie *movie = new QMovie(":/loader.gif");
    layout->addWidget(label, 5, 1);
    label->setMovie(movie);
    label->show();
    movie->start();

    qDebug() << "Sign user up";
    firebaseAuth->signUserUp(user->username + "@gmail.com", password);
    connect(firebaseAuth, &FirebaseAuth::isUsernameExist, this, [=](bool isExist = false) {
        if (isExist) {
            QLabel *usernameExistLabel = new QLabel("Username exist");
            label->hide();
            user->username = "";
            user->firstName = "";
            user->lastName = "";
            user->birthday = "";
            qDebug() << "received username exist signal";

            usernameExistLabel->setStyleSheet("color: red");
            layout->addWidget(usernameExistLabel, 0, 2);
        } else {
            label->hide();
            FirebaseAuth::connect(firebaseAuth->networkAccessManager,
                                  &QNetworkAccessManager::finished,
                                  this,
                                  &SignUpPage::uploadToStorage);
        }
    });
}

void SignUpPage::uploadToStorage()
{
    qDebug() << "Finished Sign user up";
    qDebug() << "Upload to storage";

    if (fileData.isEmpty()) {
        QFile file(":/msd-logo.jpeg");
        qDebug() << file.fileName();
        if (!file.open(QIODevice::ReadOnly)) {
            qDebug() << "Failed to open file";
        }
        fileData = file.readAll();
        QFileInfo fileInfo(file);
        fileType = fileInfo.completeSuffix();
        file.close();
    }

    firebaseStorage->uploadToStorage(fileData, fileType);

    FirebaseStorage::connect(firebaseStorage->networkManager,
                             &QNetworkAccessManager::finished,
                             this,
                             &SignUpPage::uploadToFirebase);
}

void SignUpPage::uploadToFirebase()
{
    qDebug() << "Finished upload to storage";
    qDebug() << "Upload to database";
    dbHelper->uploadToDatabase(user);
    qDebug() << "Finished upload to database";

    connect(dbHelper->getNetworkManager(),
            &QNetworkAccessManager::finished,
            this,
            &SignUpPage::closeAll);
}

void SignUpPage::closeAll()
{
    this->close();
}
