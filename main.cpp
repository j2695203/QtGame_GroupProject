#include <QApplication>
#include <QGraphicsView>
#include "game1scene.h"
#include "profile.h"
#include "login.h"
#include "scoreboard.h"

int main(int argc, char **argv) {
    QApplication app(argc, argv);

    QGraphicsView *mainView = new QGraphicsView();
    game1scene *scene1 = new game1scene;

    QFile styleFile(":style.css");
    styleFile.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(styleFile.readAll());
    app.setStyleSheet(styleSheet);

    mainView -> setScene(scene1);
    mainView -> setFixedSize(910, 512);
    mainView ->setHorizontalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    mainView ->setVerticalScrollBarPolicy((Qt::ScrollBarAlwaysOff));

    mainView -> show();

    // jinny start //////////////////////

    Login *logWindow = new Login();


    return app.exec();
}
