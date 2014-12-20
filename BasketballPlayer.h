#ifndef HOCKEYPLAYER_H
#define HOCKEYPLAYER_H

#include <QObject>

class BasketballPlayer : public QObject {
    Q_OBJECT
public:
    BasketballPlayer();

    QString getName() const;
    void setName(const QString& value);

    QString getUni() const;
    void setUni(const QString& value);

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

    double getFgPct();
    double getFtPct();
    double getFg3Pct();

    int getFouls() const;
    void setFouls(int value);

private:
    QString name, uni;
    int fgm, fga, fgm3, fga3, ftm, fta, pts, blk, stl, ast, oreb, dreb, treb, to, fouls;
};

#endif // HOCKEYPLAYER_H
