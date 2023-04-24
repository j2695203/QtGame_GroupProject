#include "game1scene.h"
#include "droplet.h"
#include <iostream>



game1scene::game1scene()
{
    // page 1
    start();
}

void game1scene::mode_easy(){
    hardness_born = 1000;
    hardness_rate = 500;
    playGame(hardness_born);
}
void game1scene::mode_medium(){
    hardness_born = 750;
    hardness_rate = 250;
    playGame(hardness_born);
}
void game1scene::mode_hard(){
    hardness_born = 500;
    hardness_rate = 150;
    playGame(hardness_born);
}

void game1scene::playGame(int time){
    // page 2

//    delete levelSection;
    removeItem(levelSection);
    removeItem(userSection);

    health_count = new int(10);
    droplet_count = new int;
    actualScore = *new int;

    scoreText = new QGraphicsTextItem();
    scoreText -> setPlainText(QString("Score: ") + QVariant(actualScore).toString());
    scoreText -> setDefaultTextColor("black");
    scoreText -> setScale(2);
    scoreText -> setPos(30, 20);
    scoreText -> setZValue(1);

    hpText = new QGraphicsTextItem();
    hpText -> setPlainText(QString("HP: ") + QVariant(*health_count).toString());
    hpText -> setDefaultTextColor("blue");
    hpText -> setScale(2);
    hpText -> setPos(30, 48);
    hpText -> setZValue(1);


    bucketItem = new bucket();
    QGraphicsPixmapItem *cloudItem = new QGraphicsPixmapItem();

    cloudItem -> setPixmap((QPixmap(":/new/prefix1/cloud.png")).scaled(910,100));

    musicPlayer = new QMediaPlayer;
//    audioOutput = new QAudioOutput;

    musicPlayer -> setSource(QUrl(":/new/prefix1/one_summers_day.mp3"));
//    audioOutput -> setVolume(100);
    musicPlayer -> play();

    addItem(bucketItem);

    addItem(hpText);

    addItem(scoreText);

    addItem(cloudItem);


    bucketItem -> setFlag(QGraphicsItem::ItemIsFocusable);

    bucketItem -> setFocus();

    dropletGeneration = new QTimer(this);
    connect(dropletGeneration, &QTimer::timeout, this, &game1scene::addingDroplet);
    dropletGeneration->start(time);
}

void game1scene::addingDroplet() {
    droplet *dropletItem = new droplet(hardness_rate, health_count, droplet_count);
    addItem(dropletItem);
    actualScore = *droplet_count * 5;

    scoreText -> setPlainText(QString("Score: ") + QVariant(actualScore).toString());
    hpText -> setPlainText(QString("HP: ") + QVariant(*health_count).toString());

    if(*health_count == 0){
        dropletGeneration->stop();
        gameOver(actualScore);
    }

}

void game1scene::gameOver(int s){

    addItem(userSection);


    over = new QLabel("Game over");
    QString finalScore = "Score : ";
    finalScore.append(std::to_string(s));
    score = new QLabel(finalScore);
    button_restart = new QPushButton("Restart");
    button_close = new QPushButton("Close");
    overHLayout = new QHBoxLayout();
    overHLayout->addWidget(button_restart);
    overHLayout->addWidget(button_close);
    overVLayout = new QVBoxLayout();

    overVLayout->addWidget(over);
    overVLayout->addWidget(score);
    overVLayout->addLayout(overHLayout);


    overBox = new QGroupBox();
    overBox->setLayout(overVLayout);
    overSection = addWidget(overBox);
    overSection->setPos(380,200);

    connect(button_restart, &QPushButton::clicked, this, &game1scene::restart);

}

void game1scene::restart(){
    QList list = items();
    for(int i = 0; i < list.size(); i++ ){
        removeItem(list[i]);
    }
    start();
}

void game1scene::start(){
    // page 1


    // level section
    level = new QLabel("Level");
    button_easy = new QPushButton("Easy");
    button_medium = new QPushButton("Medium");
    button_hard = new QPushButton("Hard");

    levelVLayout = new QVBoxLayout();

    levelVLayout->addWidget(level);
    levelVLayout->addWidget(button_easy);
    levelVLayout->addWidget(button_medium);
    levelVLayout->addWidget(button_hard);

    levelBox = new QGroupBox();
    levelBox->setLayout(levelVLayout);
    levelSection = addWidget(levelBox);
    levelSection->setPos(380,200);

    // user section
    user_name = new QLabel("guest");
    button_profile = new QPushButton("Profile");
    button_score_board = new QPushButton("Score borad");
    button_signout = new QPushButton("Sign out");

    userHLayout = new QHBoxLayout();

    userHLayout->addWidget(user_name);
    userHLayout->addWidget(button_profile);
    userHLayout->addWidget(button_score_board);
    userHLayout->addWidget(button_signout);
    userBox = new QGroupBox();
    userBox->setLayout(userHLayout);
    userSection = addWidget(userBox);
    userSection->setPos(540,0);

    setBackgroundBrush(QBrush(QImage(":/new/prefix1/spirited-awaybr-disneyscreencaps.com-1204.jpg").scaledToHeight(600).scaledToWidth(910)));
    setSceneRect(0,0,910,500);

    connect(button_easy, &QPushButton::clicked, this, &game1scene::mode_easy);
    connect(button_medium, &QPushButton::clicked, this, &game1scene::mode_medium);
    connect(button_hard, &QPushButton::clicked, this, &game1scene::mode_hard);


}
