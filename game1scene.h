#ifndef GAME1SCENE_H
#define GAME1SCENE_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

class game1scene : public QGraphicsScene
{
    Q_OBJECT
    QGraphicsTextItem *scoreText;
    int actualScore;


public:
     game1scene();

signals:

public slots:
            void addingDroplet();

};

#endif // GAME1SCENE_H
