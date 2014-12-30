#include "StatCrewScanner.h"
#include <QFileInfo>
StatCrewScanner::StatCrewScanner(BasketballGame* game, QString fileName)
{
    statCrew = new InGameXml(game->getAwayTeam(), game->getHomeTeam());
    statFile = fileName;
    trigger = new QTimer();
    trigger->setInterval(1000 * 5);
    isActive = false;
    connect(trigger, SIGNAL(timeout()), this, SLOT(updateStats()));
    connect(game, SIGNAL(periodChanged(int)), this, SLOT(toggleScanner(int)));
}

void StatCrewScanner::toggleScanner() {
    if (!isActive) {
        trigger->start();
        isActive = true;
    }
    else {
        trigger->stop();
        isActive = false;
    }
    emit statCrewStatus(isActive);
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
    emit statCrewStatus(isActive);
}

void StatCrewScanner::updateStats() {
    this->start();
}

void StatCrewScanner::run() {
    QFile file(statFile);
    QXmlSimpleReader r;
    r.setContentHandler(statCrew);
    r.setErrorHandler(statCrew);
    QXmlInputSource src(&file);
    r.parse(src);
}
