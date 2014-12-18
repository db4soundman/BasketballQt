#ifndef HOCKEYGAME_H
#define HOCKEYGAME_H

#include <QObject>
#include "Clock.h"
#include <QString>
#include <QTimer>
#include "Scoreboard.h"
#include "LowerThird.h"
#include "BasketballTeam.h"


class BasketballGame : public QObject {
    Q_OBJECT
public:
    BasketballGame(QString awayName, QString homeName, QColor awayColor, QColor homeColor,
               QString awayXML, QString homeXML, QString sponsor, QString announcers,
               QString awayRank, QString homeRank, int screenWidth);

    Scoreboard* getSb();
    LowerThird* getLt();

    QString getSponsor() const;
    void setSponsor(const QString& value);

    QString getAnnouncers() const;
    void setAnnouncers(const QString& value);

    QString getHomeName() const;
    void setHomeName(const QString& value);

    QString getAwayName() const;
    void setAwayName(const QString& value);

    BasketballTeam* getHomeTeam() const;

    BasketballTeam* getAwayTeam() const;

    Clock* getGameClock();

    QString getHomeRank() const;
    void setHomeRank(const QString& value);

    QString getAwayRank() const;
    void setAwayRank(const QString& value);

    QColor getHomeColor() const;
    void setHomeColor(const QColor& value);

    QColor getAwayColor() const;
    void setAwayColor(const QColor& value);

    int getAwayScore() const;
    void setAwayScore(int value);

    int getHomeScore() const;
    void setHomeScore(int value);

    int getPeriod() const;
    void setPeriod(int value);

    bool getIsFinal() const;
    void setIsFinal(bool value);

    int getHomeFouls() const;
    void setHomeFouls(int value);

    int getAwayFouls() const;
    void setAwayFouls(int value);

    bool getPossArrow() const;

    int getHomeTOL() const;
    void setHomeTOL(int value);

    int getAwayTOL() const;
    void setAwayTOL(int value);

public slots:
    void changeHomeScore(int value);
    void changeAwayScore(int value);
    void advancePeriod();
    void rewindPeriod();
    void toggleClock();
    void addHomeFOUL();
    void addAwayFOUL();
    void subHomeFOUL();
    void subAwayFOUL();
    void addHomeTOL();
    void addAwayTOL();
    void subHomeTOL();
    void subAwayTOL();
    void showAnnouncers();
    void gatherSummaryLt(bool home, int index);
    void gatherShootingLt(bool home,int index);
    void gatherFreethrowLt(bool home,int index);
    void gatherFgFoulLt(bool home,int index);
    void makeFinal();
    void flipPossArrow();

signals:
    void homeScoreChanged(int score);
    void awayScoreChanged(int score);
    void periodChanged(int pd);
    void clockIsRunning(bool isRunning);
    void awayFoulsChanged(int fouls);
    void homeFoulsChanged(int fouls);
    void homeTOLChanged(int tol);
    void awayTOLChanged(int tol);

private slots:

private:
    QString homeName, awayName, sponsor, announcers, homeRank,
    awayRank;
    int awayScore, homeScore, period, homeFouls, awayFouls, homeTOL, awayTOL;
    Clock gameClock;
    //QList<Clock*> awayPenalty, homePenalty;
    QTimer timer;
    bool clockRunning, isFinal, possArrow;
    QColor homeColor, awayColor;
    BasketballTeam* homeTeam;
    BasketballTeam* awayTeam;
    Scoreboard sb;
    LowerThird lt;
    // GUI is separate class
    // GraphicsVars

};

#endif // HOCKEYGAME_H
