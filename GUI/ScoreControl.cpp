#include "ScoreControl.h"
#include <QGridLayout>

ScoreControl::ScoreControl(BasketballGame* game) {
    QGridLayout* main = new QGridLayout();
    awayLabel.setText(game->getAwayName());
    homeLabel.setText(game->getHomeName());
    ap2.setText("+ 2");
    ap3.setText("+ 3");
    ap1.setText("+ 1");
    hp2.setText("+ 2");
    hp3.setText("+ 3");
    hp1.setText("+ 1");
    am1.setText("- 1");
    hm1.setText("- 1");

    main->addWidget(&awayLabel, 0, 0);
    main->addWidget(&homeLabel, 0, 1);
    main->addWidget(&ap2, 1, 0);
    main->addWidget(&hp2, 1,1);
    main->addWidget(&ap3, 2,0);
    main->addWidget(&hp3, 2,1);
    main->addWidget(&ap1, 3, 0);
    main->addWidget(&hp1, 3, 1);
    main->addWidget(&am1, 4, 0);
    main->addWidget(&hm1, 4, 1);
    main->setHorizontalSpacing(3);
    main->setVerticalSpacing(0);
    setLayout(main);


    connect(&ap2, SIGNAL(clicked()), this, SLOT(awayTwo()));
    connect(&ap3, SIGNAL(clicked()), this, SLOT(awayThree()));
    connect(&ap1, SIGNAL(clicked()), this, SLOT(awayOnePlus()));
    connect(&hp2, SIGNAL(clicked()), this, SLOT(homeTwo()));
    connect(&hp3, SIGNAL(clicked()), this, SLOT(homeThree()));
    connect(&hp1, SIGNAL(clicked()), this, SLOT(homeOnePlus()));
    connect(&am1, SIGNAL(clicked()), this, SLOT(awayOneMinus()));
    connect(&hm1, SIGNAL(clicked()), this, SLOT(homeOneMinus()));
    connect(this, SIGNAL(awayScore(int)), game, SLOT(changeAwayScore(int)));
    connect(this, SIGNAL(homeScore(int)), game, SLOT(changeHomeScore(int)));
}

void ScoreControl::awayTwo()
{
    emit awayScore(2);
}

void ScoreControl::awayThree()
{
    emit awayScore(3);
}

void ScoreControl::awayOnePlus()
{
    emit awayScore(1);
}

void ScoreControl::awayOneMinus()
{
    emit awayScore(-1);
}

void ScoreControl::homeTwo()
{
    emit homeScore(2);
}

void ScoreControl::homeThree()
{
    emit homeScore(3);
}

void ScoreControl::homeOnePlus()
{
    emit homeScore(1);
}

void ScoreControl::homeOneMinus()
{
    emit homeScore(-1);
}
