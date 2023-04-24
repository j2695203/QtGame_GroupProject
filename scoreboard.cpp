#include "scoreboard.h"
#include "firebasedbhelper.h"

scoreBoard::scoreBoard(QWidget *parent)
    : QWidget{parent}
{
    layout = new QVBoxLayout();
    global = new QLabel("Global Ranking");
    layout->addWidget(global, 0, Qt::AlignCenter);
    FirebaseDBHelper dbHelper;
    QHash<QString, int> score = dbHelper.sortRankScore();
    //std::qsort(&v[0],v.size(),sizeof(int),QsortIntCompare);
    //    std::qsort(&score[0], score.size(),sizeof(int), compareValues);
    //    qsort(score.begin(), score.end(), &scoreBoard::compareValues);
    //    QVector<QPair<QString, int>> vec;
    //    for(auto& el : score){
    //        vec.push_back(el);
    //    }

    QHash<QString, int>::const_iterator i;
    for (i = score.constBegin(); i != score.constEnd(); ++i) {
        usernameScore = new QLabel(i.key() + " " + QString::number(i.value()));
        layout->addWidget(usernameScore);
    }
    //    user = new QLabel("My History Score");

    layout->setContentsMargins(100, 30, 100, 30);

    setLayout(layout);
}

bool compareValues(const QPair<QString, int> &a, const QPair<QString, int> &b)
{
    return a.second < b.second;
}
