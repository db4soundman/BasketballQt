#ifndef SCORECONTROL_H
#define SCORECONTROL_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include "BasketballGame.h"

class ScoreControl : public QWidget {
public:
    ScoreControl(BasketballGame* game);

private:
    QLabel title;
    QPushButton ag, hg, am, hm;
};

#endif // SCORECONTROL_H
