#include "droplet.h"
#include "QtWidgets/qgraphicsscene.h"

droplet::droplet(QObject *parent)
    : QObject{parent}
{
    int random_number = arc4random() % 900;
    this -> setPixmap((QPixmap(":/new/prefix1/water.gif")).scaled(20,40));
    this -> setPos(random_number, 110);
    QTimer *timer_drop = new QTimer(this);
    connect(timer_drop, &QTimer::timeout, this, &droplet::move_droplet);
    timer_drop->start(200);
}

void droplet::move_droplet() {


    auto yPos = this ->y();
    yPos += 10;
    this -> setPos(x(), yPos);

    if (collidingItems().size() > 0 || yPos>450) {
        this->scene()->removeItem(this);
        delete this;
    }


}


