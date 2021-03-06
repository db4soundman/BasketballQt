#include "ControlPanel.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>

ControlPanel::ControlPanel(BasketballGame* game, CommercialGraphic* comGraphic, Ticker *ticker) :
    dispControls(game, comGraphic, ticker), scores(game), fouls(game),
    timeouts(game), hud(game), clockControls(game, comGraphic), stats(game), statcrewControl(game) {
    QHBoxLayout* mainLayout = new QHBoxLayout();

    QVBoxLayout* leftColumn = new QVBoxLayout();
    leftColumn->addWidget(&dispControls);
    QGridLayout* grid = new QGridLayout();
    grid->addWidget(&scores, 0, 1);
    grid->addWidget(&fouls, 0, 0,Qt::AlignHCenter | Qt::AlignTop);
    grid->addWidget(&timeouts, 1, 1, Qt::AlignHCenter | Qt::AlignTop );
    grid->addWidget(&statcrewControl, 1, 0, Qt::AlignHCenter | Qt::AlignTop);

    leftColumn->addLayout(grid);
    leftColumn->addWidget(&stats);

    QVBoxLayout* rightColumn = new QVBoxLayout();
    rightColumn->addWidget(&hud);
    rightColumn->addWidget(&clockControls);
    rightColumn->addSpacing(125);


    mainLayout->addLayout(leftColumn, 1);
    mainLayout->addLayout(rightColumn);
    setLayout(mainLayout);
}
