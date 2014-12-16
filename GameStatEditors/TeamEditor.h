#ifndef TEAMEDITOR_H
#define TEAMEDITOR_H

#include <QWidget>
#include <QSpinBox>
#include "BasketballTeam.h"

class TeamEditor : public QWidget {
    Q_OBJECT
public:
    TeamEditor(BasketballTeam* pTeam);

public slots:
    void updateSpinBoxes();
    void changeStats();

private:
    BasketballTeam* team;
    QSpinBox ppg, ppopp, pk, pkopp;
    int ppgS, ppoppS, pkS, pkoppS;

};

#endif // TEAMEDITOR_H
