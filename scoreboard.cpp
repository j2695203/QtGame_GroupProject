#include "scoreboard.h"

scoreBoard::scoreBoard(QWidget *parent)
    : QWidget{parent}
{

    global = new QLabel("Global Ranking");
    QString n1 = "AAA : 100";
    QString n2 = "AAA : 100";
    QString n3 = "AAA : 100";
    QString n4 = "AAA : 100";
    QString n5 = "AAA : 100";

    QString u1 = "100";
    QString u2 = "100";
    QString u3 = "100";
    QString u4 = "100";
    QString u5 = "100";

    no1 = new QLabel(n1);
    no2 = new QLabel(n2);
    no3 = new QLabel(n3);
    no4 = new QLabel(n4);
    no5 = new QLabel(n5);
    user = new QLabel("My History Score");
    uNo1 = new QLabel(u1);
    uNo2 = new QLabel(u2);
    uNo3 = new QLabel(u3);
    uNo4 = new QLabel(u4);
    uNo5 = new QLabel(u5);

    layout = new QVBoxLayout();
    layout->addWidget(global,0,Qt::AlignCenter);
    layout->addWidget(no1);
    layout->addWidget(no2);
    layout->addWidget(no3);
    layout->addWidget(no4);
    layout->addWidget(no5);
    layout->addWidget(user,0,Qt::AlignCenter);
    layout->addWidget(uNo1);
    layout->addWidget(uNo2);
    layout->addWidget(uNo3);
    layout->addWidget(uNo4);
    layout->addWidget(uNo5);

    layout->setContentsMargins(100,30,100,30);

    setLayout(layout);




}
