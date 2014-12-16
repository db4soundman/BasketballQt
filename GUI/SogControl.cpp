#include "SogControl.h"
#include <QString>
#include <QGridLayout>

SogControl::SogControl(BasketballGame* game) {
    QGridLayout* main = new QGridLayout();
    awayName = game->getAwayName();
    homeName = game->getHomeName();
    awayLabel.setText(awayName + " SOG: 0");
    homeLabel.setText(homeName + " SOG: 0");
    ap1.setText("+ 1");
    hp1.setText("+ 1");
    am1.setText("- 1");
    hm1.setText("- 1");
    show.setText("Show SOG Update");

    main->addWidget(&awayLabel,0,0);
    main->addWidget(&homeLabel,0,1);
    main->addWidget(&ap1, 1,0);
    main->addWidget(&hp1, 1,1);
    main->addWidget(&am1, 2,0);
    main->addWidget(&hm1, 2, 1);
    main->addWidget(&show, 3, 0, 1, 2);
    main->setHorizontalSpacing(10);
    main->setVerticalSpacing(0);

    connect(game, SIGNAL(awayFoulsChanged(int)), this, SLOT(updateAwaySog(int)));
    connect(game, SIGNAL(homeFoulsChanged(int)), this, SLOT(updateHomeSog(int)));

    connect(&ap1, SIGNAL(clicked()), game, SLOT(addAwayFOUL()));
    connect(&am1, SIGNAL(clicked()), game, SLOT(subAwayFOUL()));
    connect(&hp1, SIGNAL(clicked()), game, SLOT(addHomeFOUL()));
    connect(&hm1, SIGNAL(clicked()), game, SLOT(subHomeFOUL()));

    connect(&show, SIGNAL(clicked()), this, SLOT(callSogDisplay()));

    connect(this, SIGNAL(showSOG(QString)), game->getSb(), SLOT(changeTopBarText(QString)));

    setLayout(main);
}

void
SogControl::updateHomeSog(int sog) {
    homeLabel.setText(homeName + " SOG: " +QString::number(sog));
}

void
SogControl::updateAwaySog(int sog) {
    awayLabel.setText(awayName + " SOG: " +QString::number(sog));
}

void
SogControl::callSogDisplay() {
    QString awaySog = awayLabel.text();
    int indexOfNumber = awaySog.length() - (awaySog.indexOf(":") + 2);

    QString homeSog = homeLabel.text();
    int indexOfNumber2 = homeSog.length() - (homeSog.indexOf(":") + 2);

    QString text = "SHOTS ON GOAL: " + awayName +": " + awaySog.right(indexOfNumber)
            + "    |    " + homeName+": " + homeSog.right(indexOfNumber2);

    emit showSOG(text);
}
