#include "scoreboard.h"
#include "firebasedbhelper.h"

scoreBoard::scoreBoard(QWidget *parent)
    : QWidget{parent}
{
    layout = new QVBoxLayout();
    global = new QLabel("Global Ranking");
    layout->addWidget(global, 0, Qt::AlignCenter);
    FirebaseDBHelper dbHelper;
    QMap<QString, int> score = dbHelper.sortRankScore();
    QList<QPair<int, QString>> inv;

    // Populate the inverted list
    for (auto k : score.keys()) {
        inv.append(QPair<int, QString>(score[k], k));
    }
    std::sort(std::begin(inv), std::end(inv));


    for(int i = inv.size()-1; i >= 0; i--){
        usernameScore = new QLabel(inv[i].second + " " + QString::number(inv[i].first));
        layout->addWidget(usernameScore);
    }

    layout->setContentsMargins(100, 30, 100, 30);

    setLayout(layout);
}

bool compareValues(const QPair<QString, int> &a, const QPair<QString, int> &b)
{
    return a.second < b.second;
}
