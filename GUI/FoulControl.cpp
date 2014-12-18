#include "FoulControl.h"
#include <QString>
#include <QGridLayout>

FoulControl::FoulControl(BasketballGame* game) {
    QGridLayout* main = new QGridLayout();
    awayName = game->getAwayName();
    homeName = game->getHomeName();
    awayLabel.setText(awayName + " Fouls: 0");
    homeLabel.setText(homeName + " Fouls: 0");
    ap1.setText("+ 1");
    hp1.setText("+ 1");
    am1.setText("- 1");
    hm1.setText("- 1");
    show.setText("Show Foul Update");

    main->addWidget(&awayLabel,0,0);
    main->addWidget(&homeLabel,0,1);
    main->addWidget(&ap1, 1,0);
    main->addWidget(&hp1, 1,1);
    main->addWidget(&am1, 2,0);
    main->addWidget(&hm1, 2, 1);
    main->addWidget(&show, 3, 0, 1, 2);
    main->setHorizontalSpacing(10);
    main->setVerticalSpacing(0);

    connect(game, SIGNAL(awayFoulsChanged(int)), this, SLOT(updateAwayFouls(int)));
    connect(game, SIGNAL(homeFoulsChanged(int)), this, SLOT(updateHomeFouls(int)));

    connect(&ap1, SIGNAL(clicked()), game, SLOT(addAwayFOUL()));
    connect(&am1, SIGNAL(clicked()), game, SLOT(subAwayFOUL()));
    connect(&hp1, SIGNAL(clicked()), game, SLOT(addHomeFOUL()));
    connect(&hm1, SIGNAL(clicked()), game, SLOT(subHomeFOUL()));

    connect(&show, SIGNAL(clicked()), this, SLOT(callFoulDisplay()));

    connect(this, SIGNAL(showFouls(QString)), game->getSb(), SLOT(changeTopBarText(QString)));

    setLayout(main);
}

void
FoulControl::updateHomeFouls(int fouls) {
    homeLabel.setText(homeName + " FOULS: " +QString::number(fouls));
}

void
FoulControl::updateAwayFouls(int fouls) {
    awayLabel.setText(awayName + " FOULS: " +QString::number(fouls));
}

void
FoulControl::callFoulDisplay() {
    QString awayFouls = awayLabel.text();
    int indexOfNumber = awayFouls.length() - (awayFouls.indexOf(":") + 2);

    QString homeFouls = homeLabel.text();
    int indexOfNumber2 = homeFouls.length() - (homeFouls.indexOf(":") + 2);

    QString text = "FOULS: " + awayName +": " + awayFouls.right(indexOfNumber)
            + "    |    " + homeName+": " + homeFouls.right(indexOfNumber2);

    emit showFouls(text);
}
