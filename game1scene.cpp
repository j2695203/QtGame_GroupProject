#include "game1scene.h"

game1scene::game1scene()
{

    // create image items
    bucket1 = new bucket();
    cloud = new QGraphicsPixmapItem();

    // create droplets every single period
    timer_produce = new QTimer();
    timer_produce->start(400);
    connect(timer_produce, &QTimer::timeout, this, &game1scene::produce_droplet );

    // set cloud image and movement
    cloud->setPixmap((QPixmap(":/images/cloud.png")).scaled(900,150));
    timer_cloud = new QTimer();
    timer_cloud->start(1000);
    connect(timer_cloud, &QTimer::timeout, this, &game1scene::move_cloud );

    // allow the object to respond to the key event
    bucket1->setFlags(QGraphicsItem::ItemIsFocusable);
    bucket1->setFocus();

    // add items to this scene
    addItem(bucket1);
    addItem(cloud);

    // set background of scene
    setBackgroundBrush(QBrush(QImage(":/images/background.jpg").scaledToHeight(512) .scaledToWidth(910)));
    setSceneRect(0,0,908,510);
}

void game1scene::produce_droplet(){
    droplet *dropletN = new droplet();
    dropletN->setPos( cloud->x()+arc4random() % 800 , 100);
    addItem(dropletN);
}

void game1scene::move_cloud(){
    if( cloud->x() >= 0 ){
        cloud->setPos( cloud->x()-10, cloud->y() );
    }else{
        cloud->setPos( cloud->x()+10, cloud->y() );
    }
}
