#ifndef BASKETBALLTEAM_H
#define BASKETBALLTEAM_H

#include <QObject>
#include <QList>
#include "BasketballPlayer.h"

class BasketballTeam : public QObject {
    Q_OBJECT
public:
    BasketballTeam();
    BasketballPlayer* getPlayer(const int i);
    BasketballPlayer* getPlayerByNumber(const QString i);
    void addPlayer(BasketballPlayer* player);


    QList<QString> getGuiNames();

    BasketballPlayer* getGoalie();

    bool getPlayerInGoal() const;

    void setGoalies(QString goalies);

    int getFgm() const;
    void setFgm(int value);

    int getFga() const;
    void setFga(int value);

    int getFgm3() const;
    void setFgm3(int value);

    int getFga3() const;
    void setFga3(int value);

    int getFtm() const;
    void setFtm(int value);

    int getFta() const;
    void setFta(int value);

    int getPts() const;
    void setPts(int value);

    int getBlk() const;
    void setBlk(int value);

    int getStl() const;
    void setStl(int value);

    int getAst() const;
    void setAst(int value);

    int getOreb() const;
    void setOreb(int value);

    int getDreb() const;
    void setDreb(int value);

    int getTreb() const;
    void setTreb(int value);

    int getTo() const;
    void setTo(int value);

    int getPtsTo() const;
    void setPtsTo(int value);

    int getPtsCh2() const;
    void setPtsCh2(int value);

    int getPtsBench() const;
    void setPtsBench(int value);

    int getTies() const;
    void setTies(int value);

    int getLeads() const;
    void setLeads(int value);

    int getLargestLead() const;
    void setLargestLead(int value);

    double getFgPct();
    double getFtPct();
    double getFg3Pct();

signals:


public slots:

private:
    QList<BasketballPlayer*> roster;
    int fgm, fga, fgm3, fga3, ftm, fta, pts, blk, stl, ast, oreb, dreb, treb,
    to, ptsTo, ptsCh2, ptsBench, ties, leads, largestLead;


};

#endif
