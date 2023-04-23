#include <QApplication>
#include <QGraphicsView>
#include "game1scene.h"
#include "profile.h"

int main(int argc, char **argv) {
    QApplication app(argc, argv);

    QFile styleFile(":style.css");
    styleFile.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(styleFile.readAll());
    app.setStyleSheet(styleSheet);

<<<<<<< HEAD
    mainView -> setScene(scene1);
    mainView -> setFixedSize(910, 512);
    mainView ->setHorizontalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    mainView ->setVerticalScrollBarPolicy((Qt::ScrollBarAlwaysOff));

//    mainView -> show();

    // jinny start //////////////////////
    profile *frofileWindow = new profile();
=======
    Login *logWindow = new Login();
>>>>>>> eb2161d697def698c0046cfb41e37cf2c86c13cb

    frofileWindow->setWindowTitle("Welcome to Void Game");
    frofileWindow->show();

    return app.exec();
}
