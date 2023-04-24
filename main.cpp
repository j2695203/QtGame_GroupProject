#include <QApplication>
#include <QAudioOutput>
#include <QGraphicsView>
#include <QMediaPlayer>
#include "game1scene.h"
#include "login.h"
#include "profile.h"
#include "scoreboard.h"

int main(int argc, char **argv) {
    QApplication app(argc, argv);

    QFile styleFile(":style.css");
    styleFile.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(styleFile.readAll());
    app.setStyleSheet(styleSheet);

    Login *logWindow = new Login();
    logWindow->show();

    return app.exec();
}
