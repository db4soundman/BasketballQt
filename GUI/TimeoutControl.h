#ifndef TOCONTROL_H
#define TOCONTROL_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include "BasketballGame.h"

class TimeoutControl : public QWidget {
public:
    TimeoutControl(BasketballGame* game);

private:
    QLabel title;
    QPushButton ap, hp, am, hm;
};

#endif // SCORECONTROL_H
