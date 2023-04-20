#include <QApplication>
#include <QGraphicsView>
#include "game1scene.h"

int main(int argc, char **argv){
    QApplication app (argc, argv);

    // create scenes and view
    game1scene *scene1 = new game1scene();
    QGraphicsView *view = new QGraphicsView();

    // prevent scroll bars
    view->setHorizontalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    view->setVerticalScrollBarPolicy((Qt::ScrollBarAlwaysOff));

    view->setFixedSize(910,512);

    // add scenes to view
    view->setScene(scene1);
    view->show();

    return app.exec();
}
