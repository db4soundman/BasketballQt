#ifndef PENALTYDISPLAY_H
#define PENALTYDISPLAY_H

#include <QWidget>
#include "BasketballGame.h"
#include <QComboBox>
#include <QPushButton>

class PenaltyDisplay : public QWidget {
    Q_OBJECT
public:
    PenaltyDisplay(BasketballGame* game, bool homeTeam);

signals:
    void callForPenaltyText(int player, QString penalty);

private slots:
    void prepareSignal();

private:
    QComboBox penaltySelector, playerSelector;
    QPushButton show;
};

#endif // PENALTYDISPLAY_H
