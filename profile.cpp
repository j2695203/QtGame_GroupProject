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
        dialog = new QProgressDialog();

        connect(reply, &QNetworkReply::downloadProgress, this, &profile::downloadProgress);
        connect(reply, &QNetworkReply::finished, [=]() {
            if (reply->error() == QNetworkReply::NoError) {
                QByteArray data = reply->readAll();
                QPixmap pixmap;

                pixmap.loadFromData(data);

                pic->setPixmap(pixmap.scaledToHeight(100));
                pic->setPixmap(pixmap.scaledToWidth(200));
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
            }
            setLayout(mainLayout);
            reply->deleteLater();
            manager->deleteLater();
        });

    } else {
        username->setText("Username: Guest");
        mainLayout->addWidget(title, 0, Qt::AlignCenter);
        mainLayout->addWidget(username);
        setLayout(mainLayout);
    }
}

void profile::downloadProgress(qint64 ist, qint64 max)
{
    dialog->setRange(0, max);
    dialog->setValue(ist);
    if (ist == max)
        dialog->close();
}
