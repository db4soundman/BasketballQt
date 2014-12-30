#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <QObject>
#include <QPainter>
#include <QColor>
#include <QTimer>
#include <QList>
#include "Clock.h"
#include <QString>

class Scoreboard : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
     Scoreboard(QColor awayCol, QColor homeCol, QString awayTeam, QString homeTeam,
                 QString sponsorText, Clock* clock, QString pAwayRank, QString pHomeRank, QGraphicsItem* parent = 0);
     void paint(QPainter * painter,
                const QStyleOptionGraphicsItem * option, QWidget * widget = 0);

signals:

public slots:
     void showPd();
     void final();
     void updateHomeScore(int score);
     void updateAwayScore(int score);
     void updatePeriod(int pd);
     void changeTopBarText(QString text);
     void toggleShowBoard();
     void hideBoard();
     void updateClock();
     void intermission();
     void displayClock();
     void displaySponsor();
     void updateHomeTOL(int tol);
     void updateAwayTOL(int tol);
     void checkHomeFouls(int fouls);
     void checkAwayFouls(int fouls);

private:
     QPixmap* ppBar;
     QPixmap* topBar;
     QPixmap* networkLogo;
     QColor homeColor, awayColor;
     QGraphicsTextItem* homeName;
     QGraphicsTextItem* awayName;
     QGraphicsTextItem* homeScore;
     QGraphicsTextItem* awayScore;
     QGraphicsTextItem* topBarText;
     QGraphicsTextItem* awayRank;
     QGraphicsTextItem* homeRank;
     QString ppDescription, period, centeredTimeText, sponsorText;
     QLinearGradient mainGradient, homeGradient, awayGradient, penaltyGradient, clockGradient, shotClockGradient;
     bool awayPP, homePP, neutralPP, penalty, sponsor, homeBonus, homeDblBonus, awayBonus, awayDblBonus,
     scoreText, showPP, show, showPdAndClock, showClock, showShotClock;

     void prepareColor();
     void prepareAwayName();
     Clock* clock;
     Clock* ppClock;
     QFont defaultSponsorText;
     int homeRankOffset, awayRankOffset, awayTOL, homeTOL;

};

#endif
