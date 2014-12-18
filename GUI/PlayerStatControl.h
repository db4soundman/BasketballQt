#ifndef HOMESTATCONTROL_H
#define HOMESTATCONTROL_H

#include <QWidget>
#include "BasketballGame.h"
#include <QComboBox>
#include <QPushButton>

class PlayerStatControl : public QWidget {
    Q_OBJECT
public:
    PlayerStatControl(bool isHome, BasketballGame* game);

signals:
    void requestGameSummary(bool home, int index);
    void requestFgFoulStats(bool home, int index);
    void requestFtStats(bool home, int index);
    void requestShootingStats(bool home, int index);

private slots:
    void requestGameSummary();
    void requestShootingStats();
    void requestFtStats();
    void requestFgFoulStats();

private:
    QComboBox playerSelector;
    QPushButton summaryStats, shootingStats, ftStats, fgFoulStats;
    bool homeTeam;
};

#endif // HOMESTATCONTROL_H
