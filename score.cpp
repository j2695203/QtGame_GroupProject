#include "score.h"
#include <QFont>

score::score(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    scoreNum = 0;

    setPlainText(QString("Score: ") + QString::number(scoreNum));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times", 25));
}

void score::increase() {
    scoreNum ++;
}

int score::getScore() {
    return scoreNum;
}
