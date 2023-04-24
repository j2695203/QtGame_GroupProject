#include "bucket.h"
#include <QGraphicsScene>

bucket::bucket(QObject *parent)
{

    this -> setPixmap((QPixmap(":/IMG_2725.PNG")).scaled(80,135));
    this -> setPos(400, 355);


}


void bucket::keyPressEvent(QKeyEvent *event) {


    if (event -> key() == Qt::Key_Right) {
        this->setX(this->x()+30);
    }
    if (event -> key() == Qt::Key_Left) {

        this->setX(this->x()-30);
    }
    if (x() > 900) {
        this -> setPos (-90, 370);
    }
    if (x() < -90) {
        this -> setPos (900, 370);
    }
}
