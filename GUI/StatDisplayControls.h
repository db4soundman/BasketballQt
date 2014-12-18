#ifndef STATDISPLAYCONTROLS_H
#define STATDISPLAYCONTROLS_H

#include <QTabWidget>
#include "BasketballGame.h"
#include "PlayerStatControl.h"

class StatDisplayControls : public QTabWidget {
    Q_OBJECT
public:
    StatDisplayControls(BasketballGame* game);

private:
    PlayerStatControl homeStats, awayStats;

};

#endif // STATDISPLAYCONTROLS_H
