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

droplet::droplet(int time, int *hp, int *caught){
    this->hp = hp;
    this ->caught = caught;
    int random_number = arc4random() % 900;
    this -> setPixmap((QPixmap(":/new/prefix1/blue_candy.png")).scaled(20,20));
    this -> setPos(random_number, 110);
    timer_drop = new QTimer(this);
    connect(timer_drop, SIGNAL(timeout()), this,SLOT(move_droplet()) );
    timer_drop->start(time);
}

void droplet::move_droplet() {
    if(*hp == 0){
        timer_drop ->stop();
    }

    auto yPos = this ->y();
    yPos += 10;
    this -> setPos(x(), yPos);

    if (collidingItems().size() > 0) {
        *caught += 1;
        this->scene()->removeItem(this);
        delete this;
    }

    if(yPos > 450 ){
        *hp = *hp - 1;
        this->scene()->removeItem(this);
        delete this;
    }




}


