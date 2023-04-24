#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <QWidget>
#include <QtAlgorithms>
#include <QtWidgets>
class scoreBoard : public QWidget
{
    Q_OBJECT

    QLabel *global;
    //    QLabel *no1;
    //    QLabel *no2;
    //    QLabel *no3;
    //    QLabel *no4;
    //    QLabel *no5;

    QLabel *user;
    QLabel *usernameScore;
    QVBoxLayout *layout;

public:
    explicit scoreBoard(QWidget *parent = nullptr);

private:
    bool compareValues(const QPair<QString, int> &a, const QPair<QString, int> &b);

signals:

};

#endif // SCOREBOARD_H
