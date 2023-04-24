#ifndef DROPLET_H
#define DROPLET_H

#include <QObject>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>
#include <QAudioOutput>

class droplet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

    int *hp;
    int *caught;
    QTimer *timer_drop;

    QMediaPlayer *received;
    QAudioOutput *receivedOutput;
    QMediaPlayer *missed;
    QAudioOutput *missedOutput;

    int dropRate = 50;




public:
    explicit droplet(QObject *parent = nullptr);

    droplet(int time, int *hp, int *caught, bool birthday);


signals:
//    void caughtSignal();
    void speedUp();
public slots:
    void move_droplet();

};

#endif // DROPLET_H
