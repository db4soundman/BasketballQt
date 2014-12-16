#include "BasketballTeam.h"

BasketballTeam::BasketballTeam() {
    ppgToday = ppoppToday = pkToday = pkoppToday = 0;

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

void
BasketballTeam::addPkFail() {
    pkopp++;
    pkoppToday++;
}

BasketballPlayer* BasketballTeam::getGoalie()
{
    return goalie;
}

void BasketballTeam::setGoalie(int index)
{
    if (index >= roster.size()) {
        playerInGoal = false;
    }
    else {
        goalie = getPlayer(index);
        playerInGoal = true;
    }
}
bool BasketballTeam::getPlayerInGoal() const
{
    return playerInGoal;
}

void BasketballTeam::setGoalies(QString goalies)
{
    QString list = goalies;
    int number;
    QString strNum;
    while (list.contains(" ")) {
        strNum = list.left(list.indexOf(" "));
        list = list.mid(list.indexOf(" ")+1);
        number = strNum.toInt();
        for (int i = 0; i < roster.size(); i++) {
            if (number == getPlayer(i)->getUni().toInt()) {
                getPlayer(i)->setGaavg("Goalie");
                break;
            }
        }
    }
    number = list.toInt();
    for (int i = 0; i < roster.size(); i++) {
        if (number == getPlayer(i)->getUni().toInt()) {
            getPlayer(i)->setGaavg("Goalie");
            break;
        }
    }
}

double BasketballTeam::getPkPct() const
{
    return (double) pk/pkopp * 100;
}

void BasketballTeam::setPkPct(double value)
{
    pkPct = value;
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

double BasketballTeam::getPpPct() const
{
    return (double)ppg/ppopp * 100;
}

void BasketballTeam::setPpPct(double value)
{
    ppPct = value;
}

int BasketballTeam::getPkoppToday() const
{
    return pkoppToday;
}

void BasketballTeam::setPkoppToday(int value)
{
    pkoppToday = value;
}

int BasketballTeam::getPkToday() const
{
    return pkToday;
}

void BasketballTeam::setPkToday(int value)
{
    pkToday = value;
}

int BasketballTeam::getPpoppToday() const
{
    return ppoppToday;
}

void BasketballTeam::setPpoppToday(int value)
{
    ppoppToday = value;
}

int BasketballTeam::getPpgToday() const
{
    return ppgToday;
}

void BasketballTeam::setPpgToday(int value)
{
    ppgToday = value;
}

int BasketballTeam::getPkopp() const
{
    return pkopp;
}

void BasketballTeam::setPkopp(int value)
{
    pkopp = value;
}

int BasketballTeam::getPk() const
{
    return pk;
}

void BasketballTeam::setPk(int value)
{
    pk = value;
}

int BasketballTeam::getPpopp() const
{
    return ppopp;
}

void BasketballTeam::setPpopp(int value)
{
    ppopp = value;
}

int BasketballTeam::getPpg() const
{
    return ppg;
}

void BasketballTeam::setPpg(int value)
{
    ppg = value;
}


void
BasketballTeam::addPkStop() {
    pk++;
    pkopp++;
    pkToday++;
    pkoppToday++;
}

void
BasketballTeam::addPpFail() {
    ppopp++;
    ppoppToday++;
}

void
BasketballTeam::addPpg() {
    ppg++;
    ppopp++;
    ppgToday++;
    ppoppToday++;
}
