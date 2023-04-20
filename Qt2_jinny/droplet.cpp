#include "droplet.h"
#include "game1scene.h"

droplet::droplet(QObject *parent)
    : QObject{parent}
{
    setPixmap((QPixmap(":/images/water.gif")).scaled(30,30));

    timer_drop = new QTimer(this);
    timer_drop->start(400);

    // connect to slots
    connect(timer_drop, &QTimer::timeout, this, &droplet::move_droplet );
}

void droplet::move_droplet(){

    // fall down
    setPos(x(),y()+50);

    // delete object when it's out of boundary or collide
    if( y() > scene()->height() || !collidingItems().isEmpty() ){
        scene()->removeItem(this);
        delete this;
    }
}
