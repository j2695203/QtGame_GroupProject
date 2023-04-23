#include "profile.h"

profile::profile(QWidget *parent)
    : QWidget{parent}
{
    // set text
    name->setText("Name: "); //
    birth->setText("Birth: "); //
    gender->setText("Gender: "); //
    pic->setPixmap(QPixmap(":/new/prefix1/bucket.png").scaled(100,100));

    // set style
    mainLayout->setContentsMargins(60,60,60,60);

    // add widgets to layout

    mainLayout->addWidget(title,0,Qt::AlignCenter);
    mainLayout->addWidget(pic,0,Qt::AlignCenter);
    mainLayout->addWidget(name);
    mainLayout->addWidget(birth);
    mainLayout->addWidget(gender);

    // set layout to window
    setLayout(mainLayout);

}
