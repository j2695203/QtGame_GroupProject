#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <QWidget>
#include <QtAlgorithms>
#include <QtWidgets>
class scoreBoard : public QWidget
{
    Q_OBJECT

    QLabel *global;

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
