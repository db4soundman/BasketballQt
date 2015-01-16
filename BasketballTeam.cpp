#include "BasketballTeam.h"

BasketballTeam::BasketballTeam() {
   ptsFb = ptsPaint = ptsTo = ptsCh2 = ptsBench = ties = leads = largestLead = 0;

}

BasketballPlayer* BasketballTeam::getPlayer(const int i) {
    if (i >= roster.size())
        return NULL;
    return roster.at(i);
}

BasketballPlayer*BasketballTeam::getPlayerByNumber(const QString num)
{
    for (int i = 0; i < roster.size(); i++) {
        if (roster.at(i)->getUni() == num) {
            return roster.at(i);
        }
    }
    return NULL;
}

void
BasketballTeam::addPlayer(BasketballPlayer* player) {
    roster.append(player);
}


int BasketballTeam::getPtsTo() const
{
    return ptsTo;
}

void BasketballTeam::setPtsTo(int value)
{
    ptsTo = value;
}
int BasketballTeam::getPtsCh2() const
{
    return ptsCh2;
}

void BasketballTeam::setPtsCh2(int value)
{
    ptsCh2 = value;
}
int BasketballTeam::getPtsBench() const
{
    return ptsBench;
}

void BasketballTeam::setPtsBench(int value)
{
    ptsBench = value;
}
int BasketballTeam::getTies() const
{
    return ties;
}

void BasketballTeam::setTies(int value)
{
    ties = value;
}
int BasketballTeam::getLeads() const
{
    return leads;
}

void BasketballTeam::setLeads(int value)
{
    leads = value;
}
int BasketballTeam::getLargestLead() const
{
    return largestLead;
}

void BasketballTeam::setLargestLead(int value)
{
    largestLead = value;
}

BasketballPlayer*BasketballTeam::getTeamPlayer()
{
    return getPlayer(roster.size() - 1);
}
int BasketballTeam::getPtsFb() const
{
    return ptsFb;
}

void BasketballTeam::setPtsFb(int value)
{
    ptsFb = value;
}
int BasketballTeam::getPtsPaint() const
{
    return ptsPaint;
}

void BasketballTeam::setPtsPaint(int value)
{
    ptsPaint = value;
}
QList<BasketballPlayer *> BasketballTeam::getRoster() const
{
    return roster;
}

void BasketballTeam::setRoster(const QList<BasketballPlayer *> &value)
{
    roster = value;
}




QList<QString> BasketballTeam::getGuiNames()
{
    QList<QString> names;
    for (int i = 0; i < roster.size(); i++) {
        names.append(roster.at(i)->getUni() + " - " +
                     roster.at(i)->getName());
    }

    return names;
}

