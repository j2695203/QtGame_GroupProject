#include <QApplication>
#include <QGraphicsView>
#include "game1scene.h"
#include "login.h"

int main(int argc, char **argv) {
    QApplication app(argc, argv);

    QFile styleFile(":style.css");
    styleFile.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(styleFile.readAll());
    app.setStyleSheet(styleSheet);

    Login *logWindow = new Login();

    logWindow->setWindowTitle("Welcome to Void Game");
    logWindow->show();

    return app.exec();
}
