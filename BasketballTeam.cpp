#include "BasketballTeam.h"

BasketballTeam::BasketballTeam() {


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


int BasketballTeam::getFgm() const
{
    return fgm;
}

void BasketballTeam::setFgm(int value)
{
    fgm = value;
}
int BasketballTeam::getFga() const
{
    return fga;
}

void BasketballTeam::setFga(int value)
{
    fga = value;
}
int BasketballTeam::getFgm3() const
{
    return fgm3;
}

void BasketballTeam::setFgm3(int value)
{
    fgm3 = value;
}
int BasketballTeam::getFga3() const
{
    return fga3;
}

void BasketballTeam::setFga3(int value)
{
    fga3 = value;
}
int BasketballTeam::getFtm() const
{
    return ftm;
}

void BasketballTeam::setFtm(int value)
{
    ftm = value;
}
int BasketballTeam::getFta() const
{
    return fta;
}

void BasketballTeam::setFta(int value)
{
    fta = value;
}
int BasketballTeam::getPts() const
{
    return pts;
}

void BasketballTeam::setPts(int value)
{
    pts = value;
}
int BasketballTeam::getBlk() const
{
    return blk;
}

void BasketballTeam::setBlk(int value)
{
    blk = value;
}
int BasketballTeam::getStl() const
{
    return stl;
}

void BasketballTeam::setStl(int value)
{
    stl = value;
}
int BasketballTeam::getAst() const
{
    return ast;
}

void BasketballTeam::setAst(int value)
{
    ast = value;
}
int BasketballTeam::getOreb() const
{
    return oreb;
}

void BasketballTeam::setOreb(int value)
{
    oreb = value;
}
int BasketballTeam::getDreb() const
{
    return dreb;
}

void BasketballTeam::setDreb(int value)
{
    dreb = value;
}
int BasketballTeam::getTreb() const
{
    return treb;
}

void BasketballTeam::setTreb(int value)
{
    treb = value;
}
int BasketballTeam::getTo() const
{
    return to;
}

void BasketballTeam::setTo(int value)
{
    to = value;
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

double BasketballTeam::getFgPct()
{
    return fga != 0 ? (double)fgm / fga * 100 : 0.0;
}

double BasketballTeam::getFtPct()
{
    return fta != 0 ? (double)ftm / fta * 100 : 0.;
}

double BasketballTeam::getFg3Pct()
{
    return fga3 != 0 ? (double)fgm3 / fga3 * 100 : 0.;
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

