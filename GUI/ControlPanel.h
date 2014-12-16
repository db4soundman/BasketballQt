#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H

#include <QWidget>
#include "BasketballGame.h"
#include "DisplayControls.h"
#include "PowerPlayUpdaters.h"
#include "PenaltyControl.h"
#include "SogControl.h"
#include "ScoreControl.h"
#include "GameInfo.h"
#include "ClockControls.h"
#include "StatDisplayControls.h"
#include "CommercialGraphic.h"


class ControlPanel : public QWidget {
    Q_OBJECT
public:
    ControlPanel(BasketballGame* game, CommercialGraphic* comGraphic);

private:
    DisplayControls dispControls;
    PowerPlayUpdaters ppus;
    PenaltyControl penaltyControl;
    SogControl sogs;
    ScoreControl scores;
    GameInfo hud;
    ClockControls clockControls;
    StatDisplayControls stats;
};

#endif // CONTROLPANEL_H
