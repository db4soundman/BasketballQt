#include "Scoreboard.h"
#include <QGraphicsScene>
#include <QMessageBox>
#include <QFontMetrics>
#include <QFontInfo>

#define GRADIENT_LEVEL .5
#define AWAY_PP 1
#define HOME_PP 2
#define NEUTRAL 3
#define TEAM_NAME_WIDTH 220
#define RANK_WIDTH 50
#define TEAM_BOX_Y 10

Scoreboard::Scoreboard(QColor awayCol, QColor homeCol, QString awayTeam, QString homeTeam,
                       QString sponsorText, Clock* clock, QString pAwayRank, QString pHomeRank,
                       QGraphicsItem *parent) :
    QGraphicsPixmapItem(parent), homeColor(homeCol), awayColor(awayCol) {
    QFont font("Arial", 36, QFont::Bold);
    QFont sponsorFont("Arial", 24, QFont::Bold);
#ifdef Q_OS_OSX
    font.setPointSize(40);
    sponsorFont.setPointSize(28);
    #endif

    homeTOL = awayTOL = 5;

    defaultSponsorText = sponsorFont;
    show = false;
    showShotClock = true;

    // setPixmap(QPixmap(":/images/Scoreboard.png"));


    ppBar = new QPixmap(":/images/ppBar.png");
    topBar = new QPixmap(":/images/statbar.png");
    networkLogo = new QPixmap(":/images/M.png");
    awayName = new QGraphicsTextItem(awayTeam);
    homeName = new QGraphicsTextItem(homeTeam);
    awayName->setFont(font);
    homeName->setFont(font);
    awayScore = new QGraphicsTextItem("0");
    awayScore->setFont(font);
    homeScore = new QGraphicsTextItem("0");
    homeScore->setFont(font);
    topBarText = new QGraphicsTextItem(sponsorText);
    this->sponsorText = sponsorText;
    topBarText->setFont(defaultSponsorText);

    homeGradient.setStart(0, TEAM_BOX_Y);
    awayGradient.setStart(0, TEAM_BOX_Y);
    homeGradient.setFinalStop(0,TEAM_BOX_Y + 50);
    awayGradient.setFinalStop(0,TEAM_BOX_Y + 50);

    mainGradient.setStart(0,0);
    mainGradient.setFinalStop(0, 74);
    clockGradient.setStart(0,6);
    clockGradient.setFinalStop(0, 38);
    shotClockGradient.setStart(0,6);
    shotClockGradient.setFinalStop(0, 38);

    prepareColor();


    QFont rankFont("Arial", 20, QFont::Bold);
    awayRank = new QGraphicsTextItem(pAwayRank);
    homeRank = new QGraphicsTextItem(pHomeRank);
    awayRank->setFont(rankFont);
    homeRank->setFont(rankFont);
    awayRankOffset = homeRankOffset = RANK_WIDTH;
    if (awayRank->toPlainText().isEmpty()) {
        awayRankOffset = 0;
    }

    if (homeRank->toPlainText().isEmpty()) {
        homeRankOffset = 0;
    }

    penalty = false;
    showPP = false;
    sponsor = true;
    showPdAndClock = true;
    showClock = true;

    this->clock = clock;
    connect(clock, SIGNAL(clockUpdated()), this, SLOT(updateClock()));
    prepareAwayName();

}

void
Scoreboard::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                  QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);
    if (show) {
        painter->drawPixmap(0,-28, 790, 28, *topBar);
        painter->fillRect(0,0, 790, 74, mainGradient);
        painter->fillRect(310, 6, 85, 32, clockGradient);
        //shot clock..., maybe some if stat
        painter->fillRect(395, 6, 85, 32, showShotClock ? shotClockGradient : clockGradient);
        painter->drawPixmap(310, 38, 170, 32, *ppBar);
        //painter->drawPixmap(34, 4, 66, 50, *networkLogo);
        //Clock - Game time...draw clock first since default color is black
       painter->setFont(defaultSponsorText);
        if (showPdAndClock) {
            /*
            painter->drawText(838, 3, 247, 50, Qt::AlignVCenter, period);
            painter->drawText(833, 3, 242, 50, Qt::AlignRight | Qt::AlignVCenter,
                              showClock? clock->toString() : "HALFTIME");
                              */
            painter->drawText(310, 6, 85, 32, Qt::AlignCenter,
                              showClock? clock->toString() : "HALFTIME");
            painter->drawText(395, 6, 85, 32, Qt::AlignCenter,"35");
            painter->setPen(QColor(255,255,255));
            painter->drawText(310, 38, 170, 32, Qt::AlignCenter, period);
        }
        else {
            painter->setPen(QColor(255,255,255));
            painter->drawText(310, 38, 170, 32, Qt::AlignCenter, centeredTimeText);
        }
         painter->setFont(homeName->font());
        // Away text
        painter->fillRect(6, TEAM_BOX_Y, 75 + TEAM_NAME_WIDTH, 50, awayGradient );
        painter->setFont(awayRank->font());
        painter->setPen(QColor(255, 255, 255));
        //painter->drawText(66, TEAM_BOX_Y, awayRankOffset, 42, Qt::AlignCenter,  awayRank->toPlainText());
        painter->setFont(awayName->font());
        painter->drawText(81, TEAM_BOX_Y, TEAM_NAME_WIDTH - 5, 50, Qt::AlignVCenter | Qt::AlignRight, awayName->toPlainText());
        // Away Score
        painter->fillRect(6, TEAM_BOX_Y, 75, 50, QColor(0,0,0, 150));
        painter->setFont(awayScore->font());
        painter->drawText(6, TEAM_BOX_Y, 75, 50, Qt::AlignCenter, awayScore->toPlainText());

        // Home Text
        painter->fillRect(489, TEAM_BOX_Y, 75 + TEAM_NAME_WIDTH, 50, homeGradient);
        painter->setFont(homeRank->font());
        //painter->drawText(470, TEAM_BOX_Y, homeRankOffset, 42, Qt::AlignCenter, homeRank->toPlainText());
        painter->setFont(homeName->font());
        painter->drawText(489, TEAM_BOX_Y, TEAM_NAME_WIDTH, 50, Qt::AlignLeft | Qt::AlignVCenter, homeName->toPlainText());
        // Home Score
        painter->fillRect(489 + TEAM_NAME_WIDTH, TEAM_BOX_Y, 75, 50, QColor(0,0,0, 150));
        painter->setFont(homeScore->font());
        painter->drawText(489 + TEAM_NAME_WIDTH, TEAM_BOX_Y, 75, 50, Qt::AlignCenter, homeScore->toPlainText());
        if (sponsor) {
            //StatBarText
            painter->setPen(QColor(255, 255, 255));
            painter->setFont(topBarText->font());
            painter->drawText(0, -28, 790, 28, Qt::AlignCenter, topBarText->toPlainText());
        }

        for (int i = 0; i < awayTOL; i++) {
            painter->fillRect(266 - (40 * i) - 5, 62, 40, 5, QColor(255,255,0));
        }

        for (int i = 0; i < homeTOL; i++) {
            painter->fillRect(489 + (40 * i) + 5, 62, 40, 5, QColor(255,255,0));
        }

        if (showPP) {
            painter->setPen(QColor(255, 255, 255));
            painter->setFont(defaultSponsorText);
            // Away ppbar
            if(awayPP) {
                painter->drawPixmap(112,52, *ppBar);
                painter->drawText(120, 52, 345, 38, Qt::AlignLeft | Qt::AlignVCenter, ppDescription);
                painter->drawText(120, 52, 331, 38, Qt::AlignRight | Qt::AlignVCenter, ppClock->toStringPP());
            }
            //Home ppbar
            else if (homePP) {
                painter->drawPixmap(466,52, *ppBar);
                painter->drawText(474, 52, 345, 38, Qt::AlignLeft | Qt::AlignVCenter, ppDescription);
                painter->drawText(474, 52, 331, 38, Qt::AlignRight | Qt::AlignVCenter, ppClock->toStringPP());
            }
        }

    }
}

void
Scoreboard::prepareColor() {
    int red, green, blue;
    red = -1*homeColor.red() *GRADIENT_LEVEL + homeColor.red();
    green = -1*homeColor.green() *GRADIENT_LEVEL + homeColor.green();
    blue = -1*homeColor.blue() *GRADIENT_LEVEL + homeColor.blue();

    QColor end(red, green, blue);
    homeGradient.setColorAt(.4, homeColor);
    homeGradient.setColorAt(.6, homeColor);
    homeGradient.setColorAt(1, end);
    homeGradient.setColorAt(0, end);

    red = -1*awayColor.red() *GRADIENT_LEVEL + awayColor.red();
    green = -1*awayColor.green() *GRADIENT_LEVEL + awayColor.green();
    blue = -1*awayColor.blue() *GRADIENT_LEVEL + awayColor.blue();
    QColor end2(red, green, blue);
    awayGradient.setColorAt(.4, awayColor);
    awayGradient.setColorAt(.6, awayColor);
    awayGradient.setColorAt(1, end2);
    awayGradient.setColorAt(0, end2);

    mainGradient.setColorAt(0, QColor(0,0,0));
    mainGradient.setColorAt(1, QColor(0,0,0));
    mainGradient.setColorAt(.4, QColor(156,0,0));
    mainGradient.setColorAt(.6, QColor(156,0,0));

    clockGradient.setColorAt(0, QColor(255,255,255));
    clockGradient.setColorAt(1, QColor(255,255,255));
    clockGradient.setColorAt(.5, QColor(180,180,180));

    shotClockGradient.setColorAt(0, QColor(100,100,100));
    shotClockGradient.setColorAt(1, QColor(100,100,100));
    shotClockGradient.setColorAt(.5, QColor(180,180,180));

}

void Scoreboard::prepareAwayName()
{
    int subtraction = 1;
    int fontPointSize = awayName->font().pointSize();
    QFontMetrics fontSize(awayName->font());
    while (fontSize.width(awayName->toPlainText()) > TEAM_NAME_WIDTH - awayRankOffset - 5) {
        QFont tempFont("Arial", fontPointSize - subtraction, QFont::Bold);
        //topBarText->font().setPointSize(defaultSponsorText.pointSize()-subtraction);
        subtraction++;
        awayName->setFont(tempFont);
        QFontMetrics temp(awayName->font());
        fontSize = temp;
    }
}


void
Scoreboard::updateClock() {
//    scene()->update(this->x() + 833, this->y() + 3, 242, 50);
//    if (awayPP) {
//        scene()->update(this->x() + 112, this->y() + 54, 350, 38);
//    }
//    else if (homePP) {
//        scene()->update(this->x() + 474, this->y() + 54, 350, 38);
//    }
    scene()->update();
}

void
Scoreboard::updateAwayScore(int score) {
    QString scoreText;
    awayScore->setPlainText(scoreText.setNum(score, 10));
    scene()->update();
}

void
Scoreboard::updateHomeScore(int score) {
    QString str;
    homeScore->setPlainText(str.setNum(score, 10));
    scene()->update();
}

void
Scoreboard::updatePeriod(int pd) {
    switch (pd) {
    case 1:
        period = "1st HALF";
        break;
    case 2:
        period = "2nd HALF";
        break;
    case 3:
        period = "OT";
        showPdAndClock = true;
        break;
    default:
        period = "";
        break;
    }
    scene()->update();
}

void
Scoreboard::showPd() {
    showPdAndClock = true;
    scene()->update();
}

void
Scoreboard::final() {
    showPdAndClock = false;
    centeredTimeText = "FINAL";
    scene()->update();
}

void
Scoreboard::changeTopBarText(QString text) {
    topBarText->setPlainText(text);
    int subtraction = 1;
    topBarText->setFont(QFont("Arial", 20, QFont::Bold));
    QFontMetrics fontSize(topBarText->font());
    while (fontSize.width(text) > 790) {
        QFont tempFont("Arial", defaultSponsorText.pointSize() - subtraction, QFont::Bold);
        subtraction++;
        topBarText->setFont(tempFont);
        QFontMetrics temp(topBarText->font());
        fontSize = temp;
    }
    scene()->update();
}

void
Scoreboard::displaySponsor() {
    topBarText->setPlainText(sponsorText);
    int subtraction = 1;
    topBarText->setFont(QFont("Arial", 20, QFont::Bold));
    QFontMetrics fontSize(topBarText->font());
    while (fontSize.width(sponsorText) > 790) {
        QFont tempFont("Arial", defaultSponsorText.pointSize() - subtraction, QFont::Bold);
        //topBarText->font().setPointSize(defaultSponsorText.pointSize()-subtraction);
        subtraction++;
        topBarText->setFont(tempFont);
        QFontMetrics temp(topBarText->font());
        fontSize = temp;
    }
    scene()->update();
}

void Scoreboard::updateHomeTOL(int tol)
{
    homeTOL = tol;
    scene()->update();
}

void Scoreboard::updateAwayTOL(int tol)
{
    awayTOL = tol;
    scene()->update();
}

void
Scoreboard::toggleShowBoard() {
    show = !show;
    scene()->update();
}

void Scoreboard::togglePpClocks()
{
    showPP = !showPP;
    scene()->update();
}

void
Scoreboard::hideBoard() {
    show = false;
    scene()->update();
}

void
Scoreboard::intermission() {
    showPdAndClock = false;
    showClock = false;
    centeredTimeText = "HALFTIME";
    scene()->update();
}

void
Scoreboard::displayClock() {
    showPdAndClock = true;
    showClock = true;
    scene()->update();
}