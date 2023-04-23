#include "game1scene.h"
#include "bucket.h"
#include "droplet.h"

game1scene::game1scene()
{

    bucket *bucketItem = new bucket();
    scoreText = new QGraphicsTextItem();

    scoreText = this->addText(QString("Score: ") + QVariant(actualScore).toString());
    scoreText -> setDefaultTextColor("black");
    scoreText -> setScale(2);
    scoreText -> setPos(30, 20);
    scoreText -> setZValue(1);


    QGraphicsPixmapItem *cloudItem = new QGraphicsPixmapItem();

    cloudItem -> setPixmap((QPixmap(":/new/prefix1/cloud.png")).scaled(910,100));

    QTimer *dropletGeneration = new QTimer(this);
    connect(dropletGeneration, &QTimer::timeout, this, &game1scene::addingDroplet);
    dropletGeneration->start(1000);

    addItem(bucketItem);

    addItem(scoreText);

    addItem(cloudItem);


    bucketItem -> setFlag(QGraphicsItem::ItemIsFocusable);

    bucketItem -> setFocus();

    setBackgroundBrush(QBrush(QImage(":/new/prefix1/background.jpg").scaledToHeight(512).scaledToWidth(910)));

    setSceneRect(0,0,908,510);

}

void game1scene::addingDroplet() {
    droplet *dropletItem = new droplet();
    addItem(dropletItem);

}
