#include "BasketballPlayer.h"

BasketballPlayer::BasketballPlayer() {

}


QString BasketballPlayer::getName() const {
    return name;
}

void BasketballPlayer::setName(const QString& value) {
    name = value;

    if (!name.contains(",")) {
        name = name.toUpper();
    }
    QString goodName = (name.mid(name.indexOf(",")) + " " +
                        name.left(name.indexOf(",")));
    name = goodName.toUpper().trimmed();
}
QString BasketballPlayer::getUni() const {
    return uni;
}

void BasketballPlayer::setUni(const QString& value) {
    uni = value;
}
int BasketballPlayer::getFgm() const
{
    return fgm;
}

void BasketballPlayer::setFgm(int value)
{
    fgm = value;
}
int BasketballPlayer::getFga() const
{
    return fga;
}

void BasketballPlayer::setFga(int value)
{
    fga = value;
}
int BasketballPlayer::getFgm3() const
{
    return fgm3;
}

void BasketballPlayer::setFgm3(int value)
{
    fgm3 = value;
}
int BasketballPlayer::getFga3() const
{
    return fga3;
}

void BasketballPlayer::setFga3(int value)
{
    fga3 = value;
}
int BasketballPlayer::getFtm() const
{
    return ftm;
}

void BasketballPlayer::setFtm(int value)
{
    ftm = value;
}
int BasketballPlayer::getFta() const
{
    return fta;
}

void BasketballPlayer::setFta(int value)
{
    fta = value;
}
int BasketballPlayer::getPts() const
{
    return pts;
}

void BasketballPlayer::setPts(int value)
{
    pts = value;
}

int BasketballPlayer::getBlk() const
{
    return blk;
}

void BasketballPlayer::setBlk(int value)
{
    blk = value;
}
int BasketballPlayer::getStl() const
{
    return stl;
}

void BasketballPlayer::setStl(int value)
{
    stl = value;
}
int BasketballPlayer::getAst() const
{
    return ast;
}

void BasketballPlayer::setAst(int value)
{
    ast = value;
}
int BasketballPlayer::getOreb() const
{
    return oreb;
}

void BasketballPlayer::setOreb(int value)
{
    oreb = value;
}
int BasketballPlayer::getDreb() const
{
    return dreb;
}

void BasketballPlayer::setDreb(int value)
{
    dreb = value;
}
int BasketballPlayer::getTreb() const
{
    return treb;
}

void BasketballPlayer::setTreb(int value)
{
    treb = value;
}
int BasketballPlayer::getTo() const
{
    return to;
}

void BasketballPlayer::setTo(int value)
{
    to = value;
}

double BasketballPlayer::getFgPct()
{
    return fga != 0 ? (double)fgm / fga * 100 : 0.0;
}

double BasketballPlayer::getFtPct()
{
    return fta != 0 ? (double)ftm / fta * 100 : 0.;
}

double BasketballPlayer::getFg3Pct()
{
    return fga3 != 0 ? (double)fgm3 / fga3 * 100 : 0.;
}
