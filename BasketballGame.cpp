#include "BasketballGame.h"
#include "ClockDialog.h"
#include "RosterXmlHandler.h"

BasketballGame::BasketballGame(QString awayName, QString homeName, QColor awayColor, QColor homeColor,
                       QString xmlFile, QString sponsor, QString announcers,
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
    connect(this, SIGNAL(setStatBar(QString)), &sb, SLOT(changeTopBarText(QString)));
    connect(this, SIGNAL(awayFoulsChanged(int)), &sb, SLOT(checkAwayFouls(int)));
    connect(this, SIGNAL(awayTOLChanged(int)), &sb, SLOT(updateAwayTOL(int)));
    connect(this, SIGNAL(homeFoulsChanged(int)),&sb, SLOT(checkHomeFouls(int)));
    connect(this, SIGNAL(homeTOLChanged(int)), &sb, SLOT(updateHomeTOL(int)));

    // Jump Ball switcher
    possArrow = false;


    //connect(this, SIGNAL(checkScoreboardPp()), this, SLOT(determinePpClockForScoreboard()));
    // Make teams...
    homeTeam = new BasketballTeam();
    awayTeam = new BasketballTeam();


    RosterXmlHandler rosterHandler(this);
    QXmlSimpleReader r;
    r.setContentHandler(&rosterHandler);
    r.setErrorHandler(&rosterHandler);
    QFile f2(xmlFile);
    QXmlInputSource src2(&f2);
    r.parse(src2);
    f2.reset();

}

void
BasketballGame::changeAwayScore(int value) {
    awayScore+=value;

    emit awayScoreChanged(awayScore);

}

void
BasketballGame::changeHomeScore(int value) {
    homeScore+= value;

    emit homeScoreChanged(homeScore);
}


void
BasketballGame::addAwayFOUL() {
    awayFouls++;

    emit awayFoulsChanged(awayFouls);
}

void
BasketballGame::subAwayFOUL() {
    awayFouls--;

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


void BasketballGame::gatherSummaryLt(bool home, int index)
{
    BasketballPlayer* player = home ? getHomeTeam()->getPlayer(index) :
                                      getAwayTeam()->getPlayer(index);
    QList<QString> labels, numbers;

    labels.append("PTS");
    labels.append("AST");
    labels.append("REB");
    labels.append("STL");
    labels.append("BLK");
    labels.append("TO");

    numbers.append(QString::number(player->getPts()));
    numbers.append(QString::number(player->getAst()));
    numbers.append(QString::number(player->getTreb()));
    numbers.append(QString::number(player->getStl()));
    numbers.append(QString::number(player->getBlk()));
    numbers.append(QString::number(player->getTo()));

    lt.prepareForDisplay(player->getName(), player->getUni(), labels, numbers, home);
}

void BasketballGame::gatherShootingLt(bool home, int index)
{
    BasketballPlayer* player = home ? getHomeTeam()->getPlayer(index) :
                                      getAwayTeam()->getPlayer(index);
    QList<QString> labels, numbers;

    labels.append("FG");
    labels.append("FG%");
    labels.append("3PT");
    labels.append("3PT%");
    labels.append("PTS");

    numbers.append(QString::number(player->getFgm()) + "-" + QString::number(player->getFga()));
    numbers.append(QString::number(player->getFgPct(), 'g', 3) + "%");
    numbers.append(QString::number(player->getFgm3()) + "-" + QString::number(player->getFga3()));
    numbers.append(QString::number(player->getFg3Pct(), 'g', 3) + "%");
    numbers.append(QString::number(player->getPts()));



    lt.prepareForDisplay(player->getName(), player->getUni(),
                         labels, numbers, home);
}

void BasketballGame::gatherFreethrowLt(bool home, int index)
{
    BasketballPlayer* player = home ? getHomeTeam()->getPlayer(index) :
                                      getAwayTeam()->getPlayer(index);
    QList<QString> labels, numbers;
    labels.append("FT");
    labels.append("FT%");

    numbers.append(QString::number(player->getFtm()) + "-" + QString::number(player->getFta()));
    numbers.append(QString::number(player->getFtPct(),'g', 3) + "%");

    lt.prepareForDisplay(player->getName(), player->getUni(),
                         labels, numbers, home);
}

void BasketballGame::gatherFgFoulLt(bool home, int index)
{
    BasketballPlayer* player = home ? getHomeTeam()->getPlayer(index) :
                                      getAwayTeam()->getPlayer(index);
    QList<QString> labels, numbers;

    labels.append("FG");
    labels.append("FG%");
    labels.append("PTS");
    labels.append("FOULS");

    numbers.append(QString::number(player->getFgm()) + "-" + QString::number(player->getFga()));
    numbers.append(QString::number(player->getFgPct(), 'g', 3) + "%");
    numbers.append(QString::number(player->getPts()));
    if (!player->getName().contains(" ")) {
        numbers.append(home ? QString::number(homeFouls) : QString::number(awayFouls));
    }
    else numbers.append(QString::number(player->getFouls()));

    lt.prepareForDisplay(player->getName(), player->getUni(),
                         labels, numbers, home);
}

void BasketballGame::gatherFgComp()
{
    QList<QString> labels, numbers;
    BasketballPlayer* away = awayTeam->getTeamPlayer();
    BasketballPlayer* home = homeTeam->getTeamPlayer();

    labels.append("FG");
    labels.append("FG%");
    labels.append("3PT");
    labels.append("3PT%");

    numbers.append(QString::number(away->getFgm()) + "-" + QString::number(away->getFga()));
    numbers.append(QString::number(home->getFgm()) + "-" + QString::number(home->getFga()));
    numbers.append(QString::number(away->getFgPct(), 'g', 3) + "%");
    numbers.append(QString::number(home->getFgPct(), 'g', 3) + "%");
    numbers.append(QString::number(away->getFgm3()) + "-" + QString::number(away->getFga3()));
    numbers.append(QString::number(home->getFgm3()) + "-" + QString::number(home->getFga3()));
    numbers.append(QString::number(away->getFg3Pct(), 'g', 3) + "%");
    numbers.append(QString::number(home->getFg3Pct(), 'g', 3) + "%");

    lt.prepareForCompLt(awayName, homeName, labels, numbers);
}

void BasketballGame::gatherAssistTurnoverComp()
{
    QList<QString> labels, numbers;
    BasketballPlayer* away = awayTeam->getTeamPlayer();
    BasketballPlayer* home = homeTeam->getTeamPlayer();

    labels.append("AST");
    labels.append("TO");
    labels.append("PTS OFF TO");

    numbers.append(QString::number(away->getAst()));
    numbers.append(QString::number(home->getAst()));
    numbers.append(QString::number(away->getTo()));
    numbers.append(QString::number(home->getTo()));
    numbers.append(QString::number(awayTeam->getPtsTo()));
    numbers.append(QString::number(homeTeam->getPtsTo()));

    lt.prepareForCompLt(awayName, homeName, labels, numbers);
}

void BasketballGame::gatherReboundComp()
{
    QList<QString> labels, numbers;
    BasketballPlayer* away = awayTeam->getTeamPlayer();
    BasketballPlayer* home = homeTeam->getTeamPlayer();

    labels.append("O. REB");
    labels.append("D. REB");
    labels.append("REB");
    labels.append("2CH. PTS");

    numbers.append(QString::number(away->getOreb()));
    numbers.append(QString::number(home->getOreb()));
    numbers.append(QString::number(away->getDreb()));
    numbers.append(QString::number(home->getDreb()));
    numbers.append(QString::number(away->getTreb()));
    numbers.append(QString::number(home->getTreb()));
    numbers.append(QString::number(awayTeam->getPtsCh2()));
    numbers.append(QString::number(homeTeam->getPtsCh2()));

    lt.prepareForCompLt(awayName, homeName, labels, numbers);
}

void BasketballGame::gatherFtComp()
{
    QList<QString> labels, numbers;
    BasketballPlayer* away = awayTeam->getTeamPlayer();
    BasketballPlayer* home = homeTeam->getTeamPlayer();

    labels.append("FT");
    labels.append("FT%");

    numbers.append(QString::number(away->getFtm()) + "-" + QString::number(away->getFta()));
    numbers.append(QString::number(home->getFtm()) + "-" + QString::number(home->getFta()));
    numbers.append(QString::number(away->getFtPct(),'g', 3) + "%");
    numbers.append(QString::number(home->getFtPct(),'g', 3) + "%");

    lt.prepareForCompLt(awayName, homeName, labels, numbers);
}

void BasketballGame::gatherSpecialPtsComp()
{
    QList<QString> labels, numbers;

    labels.append("PTS PAINT");
    labels.append("PTS FB");
    labels.append("PTS BENCH");

    numbers.append(QString::number(awayTeam->getPtsPaint()));
    numbers.append(QString::number(homeTeam->getPtsPaint()));
    numbers.append(QString::number(awayTeam->getPtsFb()));
    numbers.append(QString::number(homeTeam->getPtsFb()));
    numbers.append(QString::number(awayTeam->getPtsBench()));
    numbers.append(QString::number(homeTeam->getPtsBench()));

    lt.prepareForCompLt(awayName, homeName, labels, numbers);


}

void BasketballGame::gatherLeadsTiesComp()
{
    QList<QString> labels, numbers;

    labels.append("LEADS");
    labels.append("TIES");

    numbers.append(QString::number(awayTeam->getLeads()));
    numbers.append(QString::number(homeTeam->getLeads()));
    numbers.append(QString::number(awayTeam->getTies()));
    numbers.append(QString::number(homeTeam->getTies()));

    lt.prepareForCompLt(awayName, homeName, labels, numbers);
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
    emit possArrowChanged(possArrow);
}

void BasketballGame::showPossArrow()
{
    QString text = "POSESSION ARROW: " + (possArrow ? "MIAMI" : getAwayName());
    emit setStatBar(text);
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

