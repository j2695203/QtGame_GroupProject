#include <QApplication>
#include <QAudioOutput>
#include <QGraphicsView>
#include <QMediaPlayer>
#include "game1scene.h"
#include "login.h"
#include "profile.h"
#include "scoreboard.h"
<<<<<<< HEAD
=======


>>>>>>> 30d7f37efc468dd99cfe2420290d006133424788
int main(int argc, char **argv) {
    QApplication app(argc, argv);

    QFile styleFile(":style.css");
    styleFile.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(styleFile.readAll());
    app.setStyleSheet(styleSheet);

<<<<<<< HEAD
    QMediaPlayer *player = new QMediaPlayer;
    QAudioOutput *audioOutput = new QAudioOutput;
    player->setAudioOutput(audioOutput);
    player->setSource(QUrl(":/sample-5s.mp4"));
    audioOutput->setVolume(100);

    player->play();
=======

>>>>>>> 30d7f37efc468dd99cfe2420290d006133424788

    Login *logWindow = new Login();
    logWindow->show();

    return app.exec();
}
