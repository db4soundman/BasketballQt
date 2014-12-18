#ifndef STATDISPLAYCONTROLS_H
#define STATDISPLAYCONTROLS_H

#include <QTabWidget>
#include "BasketballGame.h"
#include "HomeStatControl.h"
#include "VisitingGameStatControl.h"

class StatDisplayControls : public QTabWidget {
    Q_OBJECT
public:
    StatDisplayControls(BasketballGame* game);

private:
    HomeStatControl homeStats;
    VisitingGameStatControl awayStats;

};

#endif // STATDISPLAYCONTROLS_H
