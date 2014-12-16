#ifndef PLAYEREDITOR_H
#define PLAYEREDITOR_H

#include <QWidget>
#include <QSpinBox>
#include <QComboBox>
#include "BasketballGame.h"
#include "BasketballPlayer.h"

class PlayerEditor : public QWidget {
    Q_OBJECT
public:
    PlayerEditor(BasketballGame* game, bool homeTeam = false);

public slots:
    void updateSpinBoxes();
    void applyStats();

private slots:
    void changePlayer(int index);

private:
    QSpinBox goalsToday, astToday, penaltiesToday, pimToday;
    QComboBox playerSelect;
    BasketballPlayer* player;
    BasketballTeam* team;

};

#endif // PLAYEREDITOR_H
