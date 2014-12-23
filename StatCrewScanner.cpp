#include "StatCrewScanner.h"
#include <QMessageBox>
StatCrewScanner::StatCrewScanner(BasketballGame* game, QString fileName)
{
    statCrew = new InGameXml(game->getAwayTeam(), game->getHomeTeam());
    statFile = new QFile(fileName);
    trigger = new QTimer();
    trigger->setInterval(1000 * 15);
    isActive = false;
    connect(trigger, SIGNAL(timeout()), this, SLOT(updateStats()));
    connect(game, SIGNAL(periodChanged(int)), this, SLOT(toggleScanner(int)));
}

void StatCrewScanner::toggleScanner() {
    if (!isActive) {
        trigger->start();
    }
    else {
        trigger->stop();
    }
}

void StatCrewScanner::toggleScanner(int pd)
{
    if (pd == 0) {
        trigger->stop();
        isActive = false;
    }
    else if (pd == 1) {
        trigger->start();
        isActive = true;
    }
}

void StatCrewScanner::updateStats() {
    QXmlSimpleReader r;
    r.setContentHandler(statCrew);
    r.setErrorHandler(statCrew);
    QXmlInputSource src(statFile);
    r.parse(src);
    statFile->reset();

}
