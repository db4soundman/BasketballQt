#include "TimeoutControl.h"
#include <QGridLayout>

TimeoutControl::TimeoutControl(BasketballGame* game) {
    QGridLayout* main = new QGridLayout();
    title.setText("Timeout Controls");
    main->addWidget(&title, 0, 0);
    ap.setText(game->getAwayName() + " +");
    hp.setText(game->getHomeName() + " +");
    am.setText(game->getAwayName() + " -");
    hm.setText(game->getHomeName() + " -");
    main->addWidget(&ap, 1, 0);
    main->addWidget(&hp, 1, 1);
    main->addWidget(&am, 2, 0);
    main->addWidget(&hm, 2, 1);
    main->setHorizontalSpacing(3);
    main->setVerticalSpacing(0);
    setLayout(main);

    connect(&ap, SIGNAL(clicked()), game, SLOT(addAwayTOL()));
    connect(&am, SIGNAL(clicked()), game, SLOT(subAwayTOL()));
    connect(&hp, SIGNAL(clicked()), game, SLOT(addHomeTOL()));
    connect(&hm, SIGNAL(clicked()), game, SLOT(subHomeTOL()));

}
