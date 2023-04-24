#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <QWidget>
#include <QtAlgorithms>
#include <QtWidgets>
#include <user.h>
class scoreBoard : public QWidget
{
    Q_OBJECT

    QLabel *global;

    QLabel *userLabel;
    User *user;
    QLabel *personalHistoryRankLabel;
    QLabel *usernameScore;
    QVBoxLayout *layout;

public:
    //    explicit scoreBoard(QWidget *parent = nullptr);
    scoreBoard(User *user);

private:
    bool compareValues(const QPair<QString, int> &a, const QPair<QString, int> &b);

signals:

};

#endif // SCOREBOARD_H
