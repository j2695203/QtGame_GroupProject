#include "scoreboard.h"
#include "firebasedbhelper.h"

scoreBoard::scoreBoard(User *user)

{
    this->user = user;
    layout = new QVBoxLayout();
    global = new QLabel("Global Ranking");
    global->setStyleSheet("color: yellow; font-size: 16px");
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
        layout->addWidget(usernameScore, 0, Qt::AlignCenter);
    }

    userLabel = new QLabel("Personal History Score");
    userLabel->setStyleSheet("color: yellow; font-size: 16px");
    layout->addWidget(userLabel, 0, Qt::AlignCenter);

    foreach (auto i, user->rankScore) {
        if (i != "") {
            personalHistoryRankLabel = new QLabel(i.toString());
            layout->addWidget(personalHistoryRankLabel, 0, Qt::AlignCenter);
        }
    }

    layout->setContentsMargins(100, 30, 100, 30);

    setLayout(layout);
}
