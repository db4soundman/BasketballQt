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

    BasketballPlayer* getTeamPlayer();

signals:


public slots:

private:
    QList<BasketballPlayer*> roster;
    int ptsTo, ptsCh2, ptsBench, ties, leads, largestLead;


};

#endif
