#include "ClockControls.h"
#include <QVBoxLayout>
#include "ClockDialog.h"

ClockControls::ClockControls(BasketballGame* game, CommercialGraphic* comGraphic) {
    QVBoxLayout* main = new QVBoxLayout();
    label.setText("Clock Controls");
    run.setText("Run Clock");
    set.setText("Set Clock");
    reset.setText("Reset Clock");
    nextPd.setText("Next Period");
    prevPd.setText("Previous Period");
    clock.setText("Clock");
    intermission.setText("INT");
    final.setText("FINAL");
    jumpBall.setText("Jump Ball");
    possArrow.setText("Poss: A");
    main->addWidget(&label);
    main->addWidget(&run);
    main->addWidget(&set);
    main->addWidget(&nextPd);
    main->addWidget(&prevPd);
    main->addWidget(&reset);
    main->addWidget(&clock);
    main->addWidget(&intermission);
    main->addWidget(&final);
    main->addWidget(&jumpBall);
    main->addWidget(&possArrow);

    connect(&run, SIGNAL(clicked()), game, SLOT(toggleClock()));
    connect(game, SIGNAL(clockIsRunning(bool)),
            this, SLOT(updateClockButton(bool)));
    connect(&set, SIGNAL(clicked()), this, SLOT(showClockDialog()));
    connect(&nextPd, SIGNAL(clicked()), game, SLOT(advancePeriod()));
    connect(&prevPd, SIGNAL(clicked()), game, SLOT(rewindPeriod()));
    connect(&reset, SIGNAL(clicked()), game->getGameClock(), SLOT(resetClock()));
    connect(&clock, SIGNAL(clicked()), game->getSb(), SLOT(displayClock()));
    connect(&clock, SIGNAL(clicked()), comGraphic, SLOT(showClock()));
    connect(&intermission, SIGNAL(clicked()), game->getSb(), SLOT(intermission()));
    connect(&intermission, SIGNAL(clicked()), comGraphic, SLOT(intermissionTime()));
    connect(&final, SIGNAL(clicked()), game->getSb(), SLOT(final()));
    connect(&final, SIGNAL(clicked()), comGraphic, SLOT(finalTime()));
    connect(&final, SIGNAL(clicked()), game, SLOT(makeFinal()));
    connect(&possArrow, SIGNAL(clicked()), game, SLOT(flipPossArrow()));
    connect(&jumpBall, SIGNAL(clicked()), game, SLOT(showPossArrow()));
    connect(game, SIGNAL(possArrowChanged(bool)), this, SLOT(updatePossArrowButton(bool)));
    setLayout(main);

    gameClock = game->getGameClock();
}

void ClockControls::updateClockButton(bool clockIsRunning) {
    run.setText( clockIsRunning ? "Stop Clock" : "Run Clock");
}

void ClockControls::showClockDialog()
{
    ClockDialog cd(gameClock);
    cd.exec();
}

void ClockControls::updatePossArrowButton(bool home)
{
    QString team = home ? "H" : "A";
    possArrow.setText("POS: " + team);
}
