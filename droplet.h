#ifndef DROPLET_H
#define DROPLET_H

#include <QObject>
#include <QTimer>
#include <QGraphicsPixmapItem>

class droplet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT


public:
    explicit droplet(QObject *parent = nullptr);

signals:

public slots:
    void move_droplet();

};

#endif // DROPLET_H
