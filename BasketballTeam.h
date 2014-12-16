#ifndef HOCKEYTEAM_H
#define HOCKEYTEAM_H

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
    int getPpg() const;
    void setPpg(int value);

    int getPpopp() const;
    void setPpopp(int value);

    int getPk() const;
    void setPk(int value);

    int getPkopp() const;
    void setPkopp(int value);

    int getPpgToday() const;
    void setPpgToday(int value);

    int getPpoppToday() const;
    void setPpoppToday(int value);

    int getPkToday() const;
    void setPkToday(int value);

    int getPkoppToday() const;
    void setPkoppToday(int value);

    double getPpPct() const;
    void setPpPct(double value);

    double getPkPct() const;
    void setPkPct(double value);

    QList<QString> getGuiNames();

    BasketballPlayer* getGoalie();

    bool getPlayerInGoal() const;

    void setGoalies(QString goalies);

signals:


public slots:
    void addPpg();
    void addPpFail();
    void addPkStop();
    void addPkFail();

    void setGoalie(int index);

private:
    QList<BasketballPlayer*> roster;
    int ppg, ppopp, pk, pkopp,
    ppgToday, ppoppToday, pkToday, pkoppToday;
    double ppPct, pkPct;
    bool playerInGoal;

    BasketballPlayer* goalie;
    // period data???
    // game history???
};

#endif // HOCKEYTEAM_H
