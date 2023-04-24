#ifndef GAME1SCENE_H
#define GAME1SCENE_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QWidget>
#include <QtWidgets>
#include "bucket.h"
#include <QtMultimedia/QMediaPlayer>
//#include <QAudioOutput>

class game1scene : public QGraphicsScene
{
    Q_OBJECT
    QGraphicsTextItem *scoreText;
    QGraphicsTextItem *hpText;
    int actualScore;

    QMediaPlayer *musicPlayer;
//    QAudioOutput *audioOutput;

    int *health_count;
    int *droplet_count;

    QLabel *user_name;
    QPushButton *button_profile;
    QPushButton *button_score_board;
    QPushButton *button_signout;
    QHBoxLayout *userHLayout;
    QGroupBox *userBox;
    QGraphicsProxyWidget * userSection;


    bucket *bucketItem;
    QLabel *level;
    QVBoxLayout *levelVLayout;
    QPushButton *button_easy;
    QPushButton *button_medium;
    QPushButton *button_hard;
    QGroupBox *levelBox;
    QGraphicsProxyWidget * levelSection;
    int hardness_born;
    int hardness_rate;

    QLabel *over;
    QLabel *score;
    QPushButton *button_restart;
    QPushButton *button_close;
    QVBoxLayout *overVLayout;
    QHBoxLayout *overHLayout;
    QGroupBox *overBox;
    QGraphicsProxyWidget * overSection;


    QTimer *dropletGeneration;


public:
     game1scene();
     void playGame(int time);
     void gameOver(int s);
     void start();
     class score *scoreTest;

 signals:

public slots:
    void addingDroplet();
    void mode_easy();
    void mode_medium();
    void mode_hard();
    void restart();



};

#endif // GAME1SCENE_H
