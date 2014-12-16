#ifndef STATDISPLAYCONTROLS_H
#define STATDISPLAYCONTROLS_H

#include <QTabWidget>
#include "BasketballGame.h"
#include "GoalDisplayWidget.h"
#include "HomeStatControl.h"
#include "VisitingGameStatControl.h"
#include "PenaltyDisplay.h"
#include "Goalies.h"

class StatDisplayControls : public QTabWidget {
    Q_OBJECT
public:
    StatDisplayControls(BasketballGame* game);

private:
    GoalDisplayWidget homeGoal, awayGoal;
    HomeStatControl homeStats;
    VisitingGameStatControl awayStats;
    PenaltyDisplay homePenalty, awayPenalty;
    Goalies goalies;

};

#endif // STATDISPLAYCONTROLS_H
