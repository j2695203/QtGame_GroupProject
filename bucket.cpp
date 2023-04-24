#include "bucket.h"
#include <QGraphicsScene>

bucket::bucket(QObject *parent)
{
    this->setPixmap((QPixmap(":/bucket.png")).scaled(150, 150));
    this -> setPos(400, 365);


}


void bucket::keyPressEvent(QKeyEvent *event) {
//    auto xPos = this->x();
//    auto yPos = this->y();

    if (event -> key() == Qt::Key_Right) {
        if(this->x() < scene()->width() - 150)
        this->setX(this->x()+15);
    }
    if (event -> key() == Qt::Key_Left) {
        if(this->x() > 0)
        this->setX(this->x()-15);
    }
//    if (x() > 900) {
//        this -> setPos (-90, 370);
//    }
//    if (x() < -90) {
//        this -> setPos (900, 370);
//    }
}
