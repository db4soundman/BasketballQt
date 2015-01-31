#include "SetupWizard.h"

SetupWizard::SetupWizard(QString* pAwayName, QString* pHomeName, QString* pSponsor, QString* pAnnouncer,
                         QString* pAwayRank, QString* pHomeRank, QColor* pAwayColor,
                         QColor* pHomeColor, QColor* pBg, QString* statcrewName,
                         bool* pUsingTricaster, QString* awayLogo, QString* tricasterIp) :
    wizpage(pAwayName, pHomeName, pSponsor, pAnnouncer,
            pAwayRank, pHomeRank, pAwayColor, pHomeColor, pBg, statcrewName,
            pUsingTricaster, awayLogo, tricasterIp) {
    addPage(&wizpage);
}
