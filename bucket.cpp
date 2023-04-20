#include "bucket.h"
#include "game1scene.h"

bucket::bucket(QObject *parent)
    : QObject{parent}
{
    setPixmap((QPixmap(":/images/bucket.png")).scaled(150,150));
    setPos(400,365);

}


void bucket::keyPressEvent(QKeyEvent *event){

    if( event->key() == Qt :: Key_Right && x() < scene()->width() - 150){
        setPos(x()+30,y());
    }

    if( event->key() == Qt :: Key_Left && x() > 0){
        setPos(x()-30,y());
    }
}
