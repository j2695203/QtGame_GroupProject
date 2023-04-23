#include <QApplication>
#include <QGraphicsView>
#include "game1scene.h"
#include "profile.h"

int main(int argc, char **argv) {
    QApplication app (argc, argv);
    game1scene *scene1 = new game1scene();

    QGraphicsView *mainView = new QGraphicsView();

    mainView -> setScene(scene1);
    mainView -> setFixedSize(910, 512);
    mainView ->setHorizontalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    mainView ->setVerticalScrollBarPolicy((Qt::ScrollBarAlwaysOff));

//    mainView -> show();

    // jinny start //////////////////////
    profile *frofileWindow = new profile();

    frofileWindow->setWindowTitle("Welcome to Void Game");
    frofileWindow->show();

    // jinny end /////////////////////////

    return app.exec();
}
