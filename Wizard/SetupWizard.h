#ifndef SETUPWIZARD_H
#define SETUPWIZARD_H

#include <QWizard>
#include <QPushButton>
#include <QColor>
#include "SetupPage.h"

class SetupWizard : public QWizard {
public:
    SetupWizard(QString* pAwayName, QString* pHomeName,
                QString* pSponsor, QString* pAnnouncer, QString* pAwayRank, QString* pHomeRank,
                QColor* pAwayColor, QColor* pHomeColor, QColor* pBg, QString* statcrewName, bool *pUsingTricaster, QString* awayLogo, QString *tricasterIp);

private:
    SetupPage wizpage;
};

#endif // SETUPWIZARD_H
