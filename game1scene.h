#ifndef GAME1SCENE_H
#define GAME1SCENE_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include "bucket.h"
#include "droplet.h"


class game1scene : public QGraphicsScene
{
    Q_OBJECT;
public:
    game1scene();
    bucket *bucket1;
    droplet *droplet1;
    QGraphicsPixmapItem *cloud;
    QGraphicsPixmapItem *background;
    QTimer *timer_produce;
    QTimer *timer_cloud;
public slots:
    void produce_droplet();
    void move_cloud();
};

#endif // GAME1SCENE_H
