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
                 QString sponsorText, Clock* clock, QString pAwayRank, QString pHomeRank, QString pawayLogo);
     void paint(QPainter * painter,
                const QStyleOptionGraphicsItem * option, QWidget * widget = 0);

     bool getUseTransparency() const;
     void setUseTransparency(bool value);

signals:
     void sceneUpdated(int x, int y, int w, int h);
     void transparentField(int x, int y, int w, int h);
     void removeTransparentField(int x, int y, int w, int h);
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
     void updateShotClock(QString sc);
     void showingShotClock();
     void hidingShotClock();

private:
     QPixmap* ppBar;
     QPixmap* topBar;
     QPixmap* homeLogo, *awayLogo;
     QColor homeColor, awayColor;
     QGraphicsTextItem* homeName;
     QGraphicsTextItem* awayName;
     QGraphicsTextItem* homeScore;
     QGraphicsTextItem* awayScore;
     QGraphicsTextItem* topBarText;
     QGraphicsTextItem* awayRank;
     QGraphicsTextItem* homeRank;
     QString ppDescription, period, centeredTimeText, sponsorText, shotClock;
     QLinearGradient mainGradient, homeGradient, awayGradient, penaltyGradient, clockGradient, shotClockGradient, periodGradient, bonusGradient;
     bool awayPP, homePP, neutralPP, penalty, sponsor, homeBonus, homeDblBonus, awayBonus, awayDblBonus,
     scoreText, showPP, show, showPdAndClock, showClock, showShotClock, useTransparency;

     void prepareColor();
     void prepareAwayName();
     Clock* clock;
     Clock* ppClock;
     QFont defaultSponsorText;
     int homeRankOffset, awayRankOffset, awayTOL, homeTOL, homeLogoOffset, awayLogoOffset;

};

#endif
