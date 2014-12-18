#include "PlayerStatControl.h"
#include <QHBoxLayout>

PlayerStatControl::PlayerStatControl(bool isHome, BasketballGame* game) {
    homeTeam = isHome;
    playerSelector.addItems(homeTeam ? game->getHomeTeam()->getGuiNames() :
                                       game->getAwayTeam()->getGuiNames());
    summaryStats.setText("Summary");
    shootingStats.setText("Shooting");
    ftStats.setText("Free Throws");
    fgFoulStats.setText("Field goals - Fouls");

    QHBoxLayout* main = new QHBoxLayout();
    main->addWidget(&playerSelector);
    main->addWidget(&summaryStats);
    main->addWidget(&ftStats);
    main->addWidget(&shootingStats);
    main->addWidget(&fgFoulStats);

    connect(&summaryStats, SIGNAL(clicked()), this, SLOT(requestGameSummary()));
    connect(this, SIGNAL(requestGameSummary(bool,int)), game, SLOT(gatherSummaryLt(bool,int)));

    connect(&shootingStats, SIGNAL(clicked()), this, SLOT(requestShootingStats()));
    connect(this, SIGNAL(requestShootingStats(bool,int)), game, SLOT(gatherShootingLt(bool,int)));

    connect(&fgFoulStats, SIGNAL(clicked()), this, SLOT(requestFgFoulStats()));
    connect(this, SIGNAL(requestFgFoulStats(bool,int)), game, SLOT(gatherFgFoulLt(bool,int)));

    connect(&ftStats, SIGNAL(clicked()), this, SLOT(requestFtStats()));
    connect(this, SIGNAL(requestFtStats(bool,int)), game, SLOT(gatherFreethrowLt(bool,int)));

    setLayout(main);
}

void PlayerStatControl::requestGameSummary()
{
    emit requestGameSummary(homeTeam, playerSelector.currentIndex());
}

void PlayerStatControl::requestShootingStats()
{
    emit requestShootingStats(homeTeam, playerSelector.currentIndex());
}

void PlayerStatControl::requestFtStats()
{
    emit requestFtStats(homeTeam, playerSelector.currentIndex());
}

void PlayerStatControl::requestFgFoulStats()
{
    emit requestFgFoulStats(homeTeam, playerSelector.currentIndex());
}
