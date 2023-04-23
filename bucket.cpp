#include "bucket.h"

bucket::bucket()
{
    this->setPixmap((QPixmap(":/bucket.png")).scaled(150, 150));
    this -> setPos(400, 365);


}


void bucket::keyPressEvent(QKeyEvent *event) {
    auto xPos = this->x();
    auto yPos = this->y();

    if (event -> key() == Qt::Key_Right) {
        xPos += 40;
        this->setPos(xPos, yPos);
    }
    if (event -> key() == Qt::Key_Left) {
        xPos -= 40;
        this->setPos(xPos, yPos);
    }
    if (x() > 900) {
        this -> setPos (-90, 370);
    }
    if (x() < -90) {
        this -> setPos (900, 370);
    }
}
