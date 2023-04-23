#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <QWidget>
#include <QtWidgets>

class scoreBoard : public QWidget
{
    Q_OBJECT

    QLabel *global;
    QLabel *no1;
    QLabel *no2;
    QLabel *no3;
    QLabel *no4;
    QLabel *no5;

    QLabel *user;
    QLabel *uNo1;
    QLabel *uNo2;
    QLabel *uNo3;
    QLabel *uNo4;
    QLabel *uNo5;

    QVBoxLayout *layout;

public:
    explicit scoreBoard(QWidget *parent = nullptr);


signals:

};

#endif // SCOREBOARD_H
