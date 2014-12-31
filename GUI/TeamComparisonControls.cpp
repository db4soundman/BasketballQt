#include "TeamComparisonControls.h"
#include <QHBoxLayout>
TeamComparisonControls::TeamComparisonControls(BasketballGame* game)
{
    shooting.setText("Shooting");
    assistComp.setText("Assists - TO");
    freethrow.setText("Free Throws");
    rebounds.setText("Rebounding");
    specialPts.setText("Special Points");
    leads.setText("Leads - Ties");

    QHBoxLayout* myLayout = new QHBoxLayout();
    myLayout->addWidget(&shooting);
    myLayout->addWidget(&assistComp);
    myLayout->addWidget(&freethrow);
    myLayout->addWidget(&rebounds);
    myLayout->addWidget(&specialPts);
    myLayout->addWidget(&leads);

    setLayout(myLayout);

    connect(&shooting, SIGNAL(clicked()), game, SLOT(gatherFgComp()));
    connect(&assistComp, SIGNAL(clicked()), game, SLOT(gatherAssistTurnoverComp()));
    connect(&freethrow, SIGNAL(clicked()), game, SLOT(gatherFtComp()));
    connect(&rebounds, SIGNAL(clicked()), game, SLOT(gatherReboundComp()));
    connect(&specialPts, SIGNAL(clicked()), game, SLOT(gatherSpecialPtsComp()));
    connect(&leads, SIGNAL(clicked()), game, SLOT(gatherLeadsTiesComp()));
}
