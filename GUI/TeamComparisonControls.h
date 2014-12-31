#ifndef TEAMCOMPARISONCONTROLS_H
#define TEAMCOMPARISONCONTROLS_H

#include <QWidget>
#include "BasketballGame.h"
#include <QPushButton>

class TeamComparisonControls : public QWidget
{
    Q_OBJECT
public:
    TeamComparisonControls(BasketballGame* game);

private:
    QPushButton shooting, assistComp, freethrow, rebounds, specialPts, leads;
};

#endif // TEAMCOMPARISONCONTROLS_H
