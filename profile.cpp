#include "profile.h"
#include <QPixmap>
#include <QUrl>
#include "QtNetwork/qnetworkaccessmanager.h"
#include "QtNetwork/qnetworkreply.h"

profile::profile(User *user)
{
    this->user = user;
    if (user->username != "") {
        username->setText("Username: " + user->username);

        QUrl url(user->imageURL);
        QNetworkAccessManager *manager = new QNetworkAccessManager(this);
        QNetworkReply *reply = manager->get(QNetworkRequest(url));
        connect(reply, &QNetworkReply::finished, [=]() {
            if (reply->error() == QNetworkReply::NoError) {
                QByteArray data = reply->readAll();
                QPixmap pixmap;

                pixmap.loadFromData(data);

                pic->setPixmap(pixmap.scaled(100, 100));
            }
            reply->deleteLater();
            manager->deleteLater();
        });

        firstName->setText("First name: " + user->firstName);
        lastName->setText("Last name: " + user->lastName);
        birthday->setText("Birthday: " + user->birthday);

        // set style
        mainLayout->setContentsMargins(60, 60, 60, 60);

        // add widgets to layout

        mainLayout->addWidget(title, 0, Qt::AlignCenter);
        mainLayout->addWidget(pic, 0, Qt::AlignCenter);
        mainLayout->addWidget(username);
        mainLayout->addWidget(birthday);
        mainLayout->addWidget(firstName);
        mainLayout->addWidget(lastName);

        // set layout to window

    } else {
        username->setText("Username: Guest");
        mainLayout->addWidget(title, 0, Qt::AlignCenter);
        mainLayout->addWidget(username);
    }
    setLayout(mainLayout);
}
