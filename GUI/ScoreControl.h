#ifndef SCORECONTROL_H
#define SCORECONTROL_H

#include <QWidget>
#include "BasketballGame.h"
#include <QPushButton>
#include <QLabel>

class ScoreControl : public QWidget {
    Q_OBJECT
public:
    ScoreControl(BasketballGame* game);

signals:
    void awayScore(int length);
    void homeScore(int length);

private slots:
    void awayTwo();
    void awayThree();
    void awayOnePlus();
    void awayOneMinus();
    void homeTwo();
    void homeThree();
    void homeOnePlus();
    void homeOneMinus();

private:
    QPushButton ap2, ap3, ap1, hp2, hp3, hp1, am1, hm1;
    QLabel homeLabel, awayLabel;
};

#endif
