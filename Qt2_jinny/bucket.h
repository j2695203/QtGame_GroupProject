#ifndef BUCKET_H
#define BUCKET_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>

class bucket : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit bucket(QObject *parent = nullptr);

signals:

public slots:
    void keyPressEvent(QKeyEvent *event);
};

#endif // BUCKET_H
