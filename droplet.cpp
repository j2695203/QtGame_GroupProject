#include "droplet.h"
#include "QtWidgets/qgraphicsscene.h"


droplet::droplet(QObject *parent)
    : QObject{parent}
{
    int random_number = arc4random() % 900;

    this -> setPixmap((QPixmap(":/new/prefix1/blue_candy.png")).scaled(20,20));
    this -> setPos(random_number, 110);
    QTimer *timer_drop = new QTimer(this);
    connect(timer_drop, &QTimer::timeout, this, &droplet::move_droplet);
    timer_drop->start(200);
}

droplet::droplet(int time, int *hp, int *caught, bool birthday){
    this->hp = hp;
    this ->caught = caught;
    time -= (*caught / 5)*50;

    int random_number = arc4random() % 900;
    if (birthday) {
        this -> setPixmap((QPixmap(":/IMG_2731.PNG")).scaled(30,30));
    }
    else {
        this -> setPixmap((QPixmap(":/blue_candy.png")).scaled(20,20));
    }
    this -> setPos(random_number, 110);
    timer_drop = new QTimer(this);
    connect(timer_drop,  &QTimer::timeout, this, &droplet::move_droplet);
    timer_drop->start(time);




}

void droplet::move_droplet() {





    if(*hp == 0){
        timer_drop ->stop();
    }

    //    qDebug() << dropRate;

    auto yPos = this ->y();
    yPos += 10;
    this->setPos(x(), yPos);

    auto items = collidingItems();

    if (items.size() > 0) {
        foreach (auto item, items) {
            auto item2 = dynamic_cast<droplet *>(item);
            if (item2 == NULL) {
                receivedOutput = new QAudioOutput;
                received = new QMediaPlayer;
                *caught += 1;
                received->setAudioOutput(receivedOutput);
                received->setSource(QUrl("qrc:/bell.wav"));
                receivedOutput->setVolume(0.1);
                received->play();

                *caught += 1;

                this->scene()->removeItem(this);
                delete this;
            }
        }
    }

    //    if (collidingItems().size() > 0) {
    //        receivedOutput = new QAudioOutput;
    //        received = new QMediaPlayer;
    //        *caught += 1;
    //        received->setAudioOutput(receivedOutput);
    //        received->setSource(QUrl("qrc:/bell.wav"));
    //        receivedOutput->setVolume(0.1);
    //        received->play();

    //        *caught += 1;

    //        this->scene()->removeItem(this);
    //        delete this;
    //    }

    else if (yPos > 450) {
        missedOutput = new QAudioOutput;
        missed = new QMediaPlayer;
        *hp = *hp - 1;
        missed->setAudioOutput(missedOutput);
        missed->setSource(QUrl("qrc:/losing.wav"));
        missedOutput->setVolume(0.1);
        missed->play();
        this->scene()->removeItem(this);
        delete this;
    }
}
