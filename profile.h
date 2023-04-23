#ifndef PROFILE_H
#define PROFILE_H

#include <QWidget>
#include <QtWidgets>

class profile : public QWidget
{
    Q_OBJECT

    QLabel *title = new QLabel("My Profile");
    QLabel *name = new QLabel();
    QLabel *birth = new QLabel();
    QLabel *gender = new QLabel();
    QLabel *pic = new QLabel();

    QVBoxLayout *mainLayout = new QVBoxLayout();

public:
    explicit profile(QWidget *parent = nullptr);

signals:

};

#endif // PROFILE_H
