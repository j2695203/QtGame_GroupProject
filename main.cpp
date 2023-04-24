#include <QApplication>
#include <QGraphicsView>
#include "game1scene.h"
#include "profile.h"
#include "login.h"
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
