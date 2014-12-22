#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H

#include <QWidget>
#include "BasketballGame.h"
#include "DisplayControls.h"
#include "TimeoutControl.h"
#include "FoulControl.h"
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
    ScoreControl scores;
    FoulControl fouls;
    TimeoutControl timeouts;
    GameInfo hud;
    ClockControls clockControls;
    StatDisplayControls stats;
};

#endif // CONTROLPANEL_H
