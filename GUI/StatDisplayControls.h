#ifndef STATDISPLAYCONTROLS_H
#define STATDISPLAYCONTROLS_H

#include <QTabWidget>
#include "BasketballGame.h"
#include "PlayerStatControl.h"
#include "TeamComparisonControls.h"

class StatDisplayControls : public QTabWidget {
    Q_OBJECT
public:
    StatDisplayControls(BasketballGame* game);

private:
    PlayerStatControl homeStats, awayStats;
    TeamComparisonControls teamComps;

};

#endif // STATDISPLAYCONTROLS_H
