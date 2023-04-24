#ifndef DROPLET_H
#define DROPLET_H

#include <QObject>
#include <QTimer>
#include <QGraphicsPixmapItem>

class droplet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

    int *hp;
    int *caught;
    QTimer *timer_drop;


public:
    explicit droplet(QObject *parent = nullptr);
    droplet(int time, int *hp, int *caught);

signals:
//    void caughtSignal();
public slots:
    void move_droplet();

};

#endif // DROPLET_H
