#include "game1scene.h"
#include "droplet.h"
#include "login.h"
#include "profile.h"
#include "scoreboard.h"
#include <iostream>

game1scene::game1scene(User *user)
{
    this->user = user;
    // page 1
    start();
}

void game1scene::mode_easy()
{
    hardness_born = 300;
    hardness_rate = 550;
    playGame(hardness_born);
}
void game1scene::mode_medium()
{
    hardness_born = 200;
    hardness_rate = 550;
    playGame(hardness_born);
}
void game1scene::mode_hard()
{
    hardness_born = 500;
    hardness_rate = 70;
    playGame(hardness_born);
}

void game1scene::playGame(int time)
{
    // page 2

    removeItem(levelSection);
    removeItem(userSection);

    health_count = new int(10);
    droplet_count = new int;

    scoreText = new QGraphicsTextItem();
    scoreText->setPlainText(QString("Score: ") + QVariant(actualScore).toString());
    scoreText->setDefaultTextColor("black");
    scoreText->setScale(2);
    scoreText->setPos(30, 20);
    scoreText->setZValue(1);

    hpText = new QGraphicsTextItem();
    hpText->setPlainText(QString("HP: ") + QVariant(*health_count).toString());
    hpText->setDefaultTextColor("blue");
    hpText->setScale(2);
    hpText->setPos(30, 48);
    hpText->setZValue(1);

    bucketItem = new bucket();
    QGraphicsPixmapItem *cloudItem = new QGraphicsPixmapItem();

    cloudItem->setPixmap((QPixmap(":/cloud.png")).scaled(910, 100));
    cloudItem->setOpacity(0.85);

    musicPlayer = new QMediaPlayer;
    audioOutput = new QAudioOutput;
    musicPlayer->setAudioOutput(audioOutput);
    musicPlayer->setSource(QUrl("qrc:/one_summers_day.mp3"));

    audioOutput->setVolume(100);
    musicPlayer->play();

    addItem(bucketItem);

    addItem(hpText);

    addItem(scoreText);

    addItem(cloudItem);
    musicPlayer = new QMediaPlayer;
    audioOutput = new QAudioOutput;
    musicPlayer->setAudioOutput(audioOutput);
    musicPlayer->setSource(QUrl("qrc:/one_summers_day.mp3"));
    audioOutput->setVolume(100);
    musicPlayer->play();

    bucketItem->setFlag(QGraphicsItem::ItemIsFocusable);

    bucketItem->setFocus();

    dropletGeneration = new QTimer(this);
    connect(dropletGeneration, &QTimer::timeout, this, &game1scene::addingDroplet);
    dropletGeneration->start(time);
}

void game1scene::addingDroplet()
{
    droplet *dropletItem = new droplet(hardness_rate, health_count, droplet_count, isBirthday);
    addItem(dropletItem);
    actualScore = *droplet_count * 5;

    scoreText->setPlainText(QString("Score: ") + QVariant(actualScore).toString());
    hpText->setPlainText(QString("HP: ") + QVariant(*health_count).toString());

    if (*health_count == 0) {
        dropletGeneration->stop();
        gameOver(actualScore);
    }
}

void game1scene::gameOver(int s)
{
    removeItem(bucketItem);
    delete bucketItem;
    addItem(userSection);

    over = new QLabel("Game over");
    QString finalScore = "Score : ";
    finalScore.append(std::to_string(s));

    if (user->score < s)
        dbHelper.setScore(user, s);

    dbHelper.addHistoryScore(user, s);

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
    overSection->setPos(380, 200);

    connect(button_restart, &QPushButton::clicked, this, &game1scene::restart);
    connect(button_close, &QPushButton::clicked, this, &game1scene::close);
}

void game1scene::restart()
{
    QList list = items();
    for (int i = 0; i < list.size(); i++) {
        removeItem(list[i]);
    }
    musicPlayer->stop();

    start();
}

void game1scene::start()
{
    //     page 1

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
    levelSection->setPos(380, 200);

    // user section

    if (user->username == "") {
        user_name = new QLabel("guest");
    } else {
        user_name = new QLabel(user->username);
    }

    button_profile = new QPushButton("Profile");

    button_score_board = new QPushButton("Score borad");
    button_signout = new QPushButton("Sign out");

    userHLayout = new QHBoxLayout();

    QString dateQstring = currentDate->currentDateTime().date().toString();
    std::string toBeDelimited = dateQstring.toStdString();
    const char delim = ' ';

    std::vector<std::string> currentDateVector;
    std::stringstream ss(toBeDelimited);

    while (std::getline(ss, toBeDelimited, delim)) {
        currentDateVector.push_back(toBeDelimited);
    }

    if (user->birthday != "") {
        QString bday = user->birthday;
        std::string bdaystr = bday.toStdString();

        std::vector<std::string> birthdayVector;
        std::stringstream ss1(bdaystr);

        while (std::getline(ss1, bdaystr, delim)) {
            birthdayVector.push_back(bdaystr);
        }

        if (currentDateVector[1] == birthdayVector[1] && currentDateVector[2] == birthdayVector[2]) {
            isBirthday = true;
        }
    }

    if (isBirthday) {
        birthday = new QLabel("Happy Birthday!");
        userHLayout->addWidget(birthday);
    }

    userHLayout->addWidget(user_name);
    userHLayout->addWidget(button_profile);
    userHLayout->addWidget(button_score_board);
    userHLayout->addWidget(button_signout);
    userBox = new QGroupBox();
    userBox->setLayout(userHLayout);
    userSection = addWidget(userBox);
    if (isBirthday) {
        userSection->setPos(450, 0);
    } else {
        userSection->setPos(540, 0);
    }

    setBackgroundBrush(QBrush(QImage(":/spirited-awaybr-disneyscreencaps.com-1204.jpg")
                                  .scaledToHeight(600)
                                  .scaledToWidth(910)));
    setSceneRect(0, 0, 910, 500);

    connect(button_easy, &QPushButton::clicked, this, &game1scene::mode_easy);
    connect(button_medium, &QPushButton::clicked, this, &game1scene::mode_medium);
    connect(button_hard, &QPushButton::clicked, this, &game1scene::mode_hard);
    connect(button_profile, &QPushButton::clicked, this, &game1scene::openProfile);
    connect(button_score_board, &QPushButton::clicked, this, &game1scene::openRank);
    connect(button_signout, &QPushButton::clicked, this, &game1scene::signOut);
}

void game1scene::setUser(User *user)
{
    this->user = user;
}

void game1scene::openProfile()
{
    qDebug() << user->imageURL;
    profile *frofileWindow = new profile(user);
    frofileWindow->setWindowTitle("Profile");
    frofileWindow->show();
}

void game1scene::openRank()
{
    scoreBoard *score_board = new scoreBoard(user);
    score_board->setWindowTitle("Score Board");
    score_board->show();
}

void game1scene::signOut()
{
    Login *logWindow = new Login();
    logWindow->show();
    QList list = items();
    for (auto &i : list) {
        removeItem(i);
    }
    QList view = views();
    for (auto v : view) {
        v->close();
    }
    this->clear();
}

void game1scene::close()
{
    QList list = items();
    for (auto &i : list) {
        removeItem(i);
    }
    QList view = views();
    for (auto v : view) {
        v->close();
    }
    this->clear();
}
