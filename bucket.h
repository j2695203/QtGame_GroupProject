#ifndef BUCKET_H
#define BUCKET_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QKeyEvent>

class bucket : public QObject, public QGraphicsPixmapItem
{

    void keyPressEvent(QKeyEvent *event);


public:
    bucket();
};

#endif // BUCKET_H
