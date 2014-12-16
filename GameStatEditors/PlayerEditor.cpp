#include "PlayerEditor.h"
#include <QVBoxLayout>
#include <QFormLayout>
#include <QPushButton>

PlayerEditor::PlayerEditor(BasketballGame* game, bool homeTeam) {
    QVBoxLayout* mainLayout = new QVBoxLayout();
    QFormLayout* statsLayout = new QFormLayout();
    playerSelect.addItems(homeTeam ? game->getHomeTeam()->getGuiNames() :
                                     game->getAwayTeam()->getGuiNames());
    team = homeTeam ? game->getHomeTeam() : game->getAwayTeam();
    player = team->getPlayer(0);
    mainLayout->addWidget(&playerSelect);
    statsLayout->addRow("Goals", &goalsToday);
    statsLayout->addRow("Assits", &astToday);
    statsLayout->addRow("Penalties", &penaltiesToday);
    statsLayout->addRow("PIM Today", &pimToday);
    mainLayout->addLayout(statsLayout);
    QPushButton* ok = new QPushButton("Ok");
    connect(ok, SIGNAL(clicked()), this, SLOT(applyStats()));
    connect(ok, SIGNAL(clicked()), this, SLOT(hide()));
    mainLayout->addWidget(ok);
    setLayout(mainLayout);

    connect(&playerSelect, SIGNAL(currentIndexChanged(int)),
            this, SLOT(changePlayer(int)));
    setWindowTitle("Player Editor");
}

void PlayerEditor::updateSpinBoxes() {
    goalsToday.setValue(player->getGoalsToday());
    astToday.setValue(player->getAssistsToday());
    penaltiesToday.setValue(player->getPenaltiesToday());
    pimToday.setValue(player->getPimToday());
}

void PlayerEditor::applyStats() {
    player->setGoalsToday(goalsToday.value());
    player->setAssistsToday(astToday.value());
    player->setPenaltiesToday(penaltiesToday.value());
    player->setPimToday(pimToday.value());
    player->setPtsToday(goalsToday.value() +  astToday.value());

}

void PlayerEditor::changePlayer(int index)
{
    player = team->getPlayer(index);
    updateSpinBoxes();
}
