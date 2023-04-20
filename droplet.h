#ifndef DROPLET_H
#define DROPLET_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>

class droplet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit droplet(QObject *parent = nullptr);
    QTimer *timer_drop;

signals:

public slots:
    void move_droplet();
};

#endif // DROPLET_H
