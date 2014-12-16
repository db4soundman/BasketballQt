#include "BasketballGame.h"
#include "SeasonXMLHandler.h"
#include "ClockDialog.h"


BasketballGame::BasketballGame(QString awayName, QString homeName, QColor awayColor, QColor homeColor,
                       QString awayXML, QString homeXML, QString sponsor, QString announcers,
                       QString awayRank, QString homeRank, int screenWidth) :
    awayName(awayName), homeName(homeName), sponsor(sponsor), announcers(announcers), awayColor(awayColor),
    homeColor(homeColor), awayRank(awayRank), homeRank(homeRank),
    sb(awayColor, homeColor, awayName, homeName, sponsor, &gameClock, awayRank, homeRank),
    lt (awayColor, homeColor, screenWidth) {
    isFinal = false;
    awayScore = 0;
    homeScore = 0;
    homeFouls = 0;
    awayFouls = 0;
    period = 0;
    awayTOL = 5;
    homeTOL = 5;
    timer.setTimerType(Qt::PreciseTimer);
    timer.setInterval(100);
    clockRunning = false;

    connect(&gameClock, SIGNAL(clockExpired()),
            this, SLOT(toggleClock()));
    connect(&timer, SIGNAL(timeout()), &gameClock, SLOT(tick()));
    connect(this, SIGNAL(periodChanged(int)), &sb, SLOT(updatePeriod(int)));
    connect(this, SIGNAL(awayScoreChanged(int)), &sb, SLOT(updateAwayScore(int)));
    connect(this, SIGNAL(homeScoreChanged(int)), &sb, SLOT(updateHomeScore(int)));

    // Jump Ball switcher
    connect(this, SIGNAL(penaltyChanged(int,Clock*,QString)), &sb, SLOT(preparePowerplayClock(int,Clock*,QString)));



    connect(this, SIGNAL(checkScoreboardPp()), this, SLOT(determinePpClockForScoreboard()));
    // Make teams...
    homeTeam = new BasketballTeam();
    awayTeam = new BasketballTeam();

    /*
    SeasonXMLHandler handler(homeTeam);
    QXmlSimpleReader r;
    r.setContentHandler(&handler);
    r.setErrorHandler(&handler);
    QFile file(homeXML);
    QXmlInputSource src(&file);
    r.parse(src);

    GameXmlHandler roadHandler(awayTeam);
    r.setContentHandler(&roadHandler);
    r.setErrorHandler(&roadHandler);
    QFile f2(awayXML);
    QXmlInputSource src2(&f2);
    r.parse(src2);
    */
}

void
BasketballGame::awayGoal() {
    awayScore ++;

    emit awayScoreChanged(awayScore);

}

void
BasketballGame::awayLoseGoal() {
    awayScore --;
    emit awayScoreChanged(awayScore);

}

void
BasketballGame::homeGoal() {
    homeScore ++;

    emit homeScoreChanged(homeScore);
}

void
BasketballGame::homeLoseGoal() {
    homeScore --;
    emit homeScoreChanged(homeScore);
    if (getAwayTeam()->getPlayerInGoal()) {
        awayTeam->getGoalie()->minusGa();
    }
    homeFouls--;
    emit homeFoulsChanged(homeFouls);
}

void
BasketballGame::addAwayFOUL() {
    awayFouls++;
    if (getHomeTeam()->getPlayerInGoal()) {
        homeTeam->getGoalie()->addSave();
    }
    emit awayFoulsChanged(awayFouls);
}

void
BasketballGame::subAwayFOUL() {
    awayFouls--;
    if (getHomeTeam()->getPlayerInGoal()) {
        homeTeam->getGoalie()->minusSave();
    }
    emit awayFoulsChanged(awayFouls);
}

void BasketballGame::addHomeTOL()
{
    homeTOL++;
    emit homeTOLChanged(homeTOL);
}

void BasketballGame::addAwayTOL()
{
    awayTOL++;
    emit awayTOLChanged(awayTOL);
}

void BasketballGame::subAwayTOL()
{
    awayTOL--;
    emit awayTOLChanged(awayTOL);
}

void BasketballGame::subHomeTOL()
{
    homeTOL--;
    emit homeTOLChanged(homeTOL);
}

void
BasketballGame::showAnnouncers() {
    if (announcers.contains("and") || announcers.contains("&")) {
        sb.changeTopBarText("Commentators: " + announcers);
    }
    else {
        sb.changeTopBarText("Commentator: " + announcers);
    }
}


void BasketballGame::gatherHomeStatsLt(int index)
{
    BasketballPlayer* player = getHomeTeam()->getPlayer(index);
    QList<QString> labels, numbers;
    if (player->getGaavg() == "NG") {
        labels.append("G");
        labels.append("A");
        labels.append("PTS");
        labels.append("PIM");
        numbers.append(QString::number(player->getGoalsToday()));
        numbers.append(QString::number(player->getAssistsToday()));
        numbers.append(QString::number(player->getPtsToday()));
        numbers.append(QString::number(player->getPimToday()));
    }
    else {
        labels.append("GA");
        labels.append("SV");
        labels.append("SHOTS");
        numbers.append(QString::number(player->getGaToday()));
        numbers.append(QString::number(player->getSavesToday()));
        numbers.append(QString::number(player->getShotsFacedToday()));
    }
    lt.prepareForDisplay(player->getName(), player->getUni(), player->getYear(),
                         labels, numbers, true);
}

void BasketballGame::gatherAwayStatsLt(int index)
{
    BasketballPlayer* player = getAwayTeam()->getPlayer(index);
    QList<QString> labels, numbers;
    if (player->getGaavg() == "NG") {
        labels.append("G");
        labels.append("A");
        labels.append("PTS");
        labels.append("PIM");
        numbers.append(QString::number(player->getGoalsToday()));
        numbers.append(QString::number(player->getAssistsToday()));
        numbers.append(QString::number(player->getPtsToday()));
        numbers.append(QString::number(player->getPimToday()));
    }
    else {
        labels.append("GA");
        labels.append("SV");
        labels.append("SHOTS");
        numbers.append(QString::number(player->getGaToday()));
        numbers.append(QString::number(player->getSavesToday()));
        numbers.append(QString::number(player->getShotsFacedToday()));
    }
    lt.prepareForDisplay(player->getName(), player->getUni(), "",
                         labels, numbers, false);
}

void BasketballGame::gatherHomeGameStatsSb(int index)
{
    BasketballPlayer* player = getHomeTeam()->getPlayer(index);
    QString text = player->getName() + " (" + getHomeName()+"): ";
    if (player->getGaavg() == "NG") {
        text += QString::number(player->getGoalsToday()) + " G, ";
        text += QString::number(player->getAssistsToday()) + " A, ";
        text += QString::number(player->getPimToday()) + " PIM";
    }
    else {
        text += QString::number(player->getGaToday()) + " GA, ";
        text += QString::number(player->getSavesToday()) + " SAVES";
    }
    sb.changeTopBarText(text);
}

void BasketballGame::gatherAwayGameStatsSb(int index)
{
    BasketballPlayer* player = getAwayTeam()->getPlayer(index);
    QString text = player->getName() + " (" + getAwayName()+"): ";
    if (player->getGaavg() == "NG") {
        text += QString::number(player->getGoalsToday()) + " G, ";
        text += QString::number(player->getAssistsToday()) + " A, ";
        text += QString::number(player->getPimToday()) + " PIM";
    }
    else {
        text += QString::number(player->getGaToday()) + " GA, ";
        text += QString::number(player->getSavesToday()) + " SAVES";
    }
    sb.changeTopBarText(text);
}

Clock* BasketballGame::getGameClock()
{
    return &gameClock;
}

BasketballTeam* BasketballGame::getAwayTeam() const
{
    return awayTeam;
}

BasketballTeam* BasketballGame::getHomeTeam() const
{
    return homeTeam;
}


QString BasketballGame::getAwayName() const
{
    return awayName;
}

void BasketballGame::setAwayName(const QString& value)
{
    awayName = value;
}

QString BasketballGame::getHomeName() const
{
    return homeName;
}

void BasketballGame::setHomeName(const QString& value)
{
    homeName = value;
}

QString BasketballGame::getAnnouncers() const
{
    return announcers;
}

void BasketballGame::setAnnouncers(const QString& value)
{
    announcers = value;
}

QString BasketballGame::getSponsor() const
{
    return sponsor;
}

void BasketballGame::setSponsor(const QString& value)
{
    sponsor = value;
}

LowerThird* BasketballGame::getLt()
{
    return &lt;
}


Scoreboard* BasketballGame::getSb()
{
    return &sb;
}

void
BasketballGame::addHomeFOUL() {
    homeFouls++;

    emit homeFoulsChanged(homeFouls);
}

void
BasketballGame::subHomeFOUL() {
    homeFouls--;

    emit homeFoulsChanged(homeFouls);
}

void
BasketballGame::advancePeriod() {
    period++;
    isFinal = false;

    emit periodChanged(period);
}

void
BasketballGame::rewindPeriod() {
    period--;
    isFinal = false;

    emit periodChanged(period);
}


void BasketballGame::makeFinal()
{
    isFinal = true;
}


bool BasketballGame::getPossArrow() const
{
    return possArrow;
}

void BasketballGame::flipPossArrow()
{
    possArrow = !possArrow;
}
int BasketballGame::getAwayTOL() const
{
    return awayTOL;
}

void BasketballGame::setAwayTOL(int value)
{
    awayTOL = value;
}

int BasketballGame::getHomeTOL() const
{
    return homeTOL;
}

void BasketballGame::setHomeTOL(int value)
{
    homeTOL = value;
}


int BasketballGame::getAwayFouls() const
{
    return awayFouls;
}

void BasketballGame::setAwayFouls(int value)
{
    awayFouls = value;
    emit awayFoulsChanged(awayFouls);
}

int BasketballGame::getHomeFouls() const
{
    return homeFouls;
}

void BasketballGame::setHomeFouls(int value)
{
    homeFouls = value;
    emit homeFoulsChanged(homeFouls);
}

bool BasketballGame::getIsFinal() const
{
    return isFinal;
}

void BasketballGame::setIsFinal(bool value)
{
    isFinal = value;
}

int BasketballGame::getPeriod() const
{
    return period;
}

void BasketballGame::setPeriod(int value)
{
    period = value;
}

int BasketballGame::getHomeScore() const
{
    return homeScore;
}

void BasketballGame::setHomeScore(int value)
{
    homeScore = value;
}

int BasketballGame::getAwayScore() const
{
    return awayScore;
}

void BasketballGame::setAwayScore(int value)
{
    awayScore = value;
}

QColor BasketballGame::getAwayColor() const
{
    return awayColor;
}

void BasketballGame::setAwayColor(const QColor& value)
{
    awayColor = value;
}

QColor BasketballGame::getHomeColor() const
{
    return homeColor;
}

void BasketballGame::setHomeColor(const QColor& value)
{
    homeColor = value;
}

QString BasketballGame::getAwayRank() const
{
    return awayRank;
}

void BasketballGame::setAwayRank(const QString& value)
{
    awayRank = value;
}

QString BasketballGame::getHomeRank() const
{
    return homeRank;
}

void BasketballGame::setHomeRank(const QString& value)
{
    homeRank = value;
}

void
BasketballGame::toggleClock() {
    clockRunning = !clockRunning;
    if (clockRunning) {
        timer.start();
    }
    else {
        timer.stop();
    }
    emit clockIsRunning(clockRunning);
}

