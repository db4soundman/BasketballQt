#include "BasketballPlayer.h"

BasketballPlayer::BasketballPlayer() {
    goalsToday = assistsToday = ptsToday = penaltiesToday =
            pimToday = gaToday = savesToday = shotsFacedToday = 0;
}

BasketballPlayer::BasketballPlayer(const BasketballPlayer& p) {
    goalsToday = assistsToday = ptsToday = penaltiesToday =
            pimToday = gaToday = savesToday = shotsFacedToday = 0;

    name = p.getName();
    uni = p.getUni();
    year = p.getYear();
    plusMinus = p.getPlusMinus();
    gaavg = p.getGaavg();
    gp = p.getGp();
    goals = p.getGoals();
    assists = p.getAssists();
    pts = p.getPts();
    penalties = p.getPenalties();
    pim = p.getPim();
    ga = p.getGa();
    saves = p.getSaves();
    wins = p.getWins();
    losses = p.getLosses();
    shotsFaced = p.getShotsFaced();
}

QString BasketballPlayer::getName() const {
    return name;
}

void BasketballPlayer::setName(const QString& value) {
    name = value;
}
QString BasketballPlayer::getUni() const {
    return uni;
}

void BasketballPlayer::setUni(const QString& value) {
    uni = value;
}
QString BasketballPlayer::getYear() const {
    return year;
}

void BasketballPlayer::setYear(const QString& value) {
    year = value;
}

QString BasketballPlayer::getPlusMinus() const {
    return plusMinus;
}

void BasketballPlayer::setPlusMinus(const QString& value) {
    plusMinus = value;
}

int BasketballPlayer::getGp() const {
    return gp;
}

void BasketballPlayer::setGp(int value)
{
    gp = value;
}

int BasketballPlayer::getGoals() const {
    return goals;
}

void BasketballPlayer::setGoals(int value) {
    goals = value;
}
int BasketballPlayer::getAssists() const {
    return assists;
}

void BasketballPlayer::setAssists(int value) {
    assists = value;
}

int BasketballPlayer::getPts() const {
    return pts;
}

void BasketballPlayer::setPts(int value) {
    pts = value;
}

int BasketballPlayer::getPenalties() const {
    return penalties;
}

void BasketballPlayer::setPenalties(int value) {
    penalties = value;
}

int BasketballPlayer::getPim() const {
    return pim;
}

void BasketballPlayer::setPim(int value) {
    pim = value;
}

int BasketballPlayer::getGa() const {
    return ga;
}

void BasketballPlayer::setGa(int value) {
    ga = value;
}

int BasketballPlayer::getSaves() const {
    return saves;
}

void BasketballPlayer::setSaves(int value) {
    saves = value;
}
int BasketballPlayer::getShotsFaced() const {
    return shotsFaced;
}

void BasketballPlayer::setShotsFaced(int value) {
    shotsFaced = value;
}
int BasketballPlayer::getWins() const {
    return wins;
}

void BasketballPlayer::setWins(int value) {
    wins = value;
}
int BasketballPlayer::getLosses() const {
    return losses;
}

void BasketballPlayer::setLosses(int value) {
    losses = value;
}
int BasketballPlayer::getGoalsToday() const {
    return goalsToday;
}

void BasketballPlayer::setGoalsToday(int value) {
    goalsToday = value;
}
int BasketballPlayer::getAssistsToday() const {
    return assistsToday;
}

void BasketballPlayer::setAssistsToday(int value) {
    assistsToday = value;
}
int BasketballPlayer::getPtsToday() const {
    return ptsToday;
}

void BasketballPlayer::setPtsToday(int value) {
    ptsToday = value;
}
int BasketballPlayer::getPenaltiesToday() const {
    return penaltiesToday;
}

void BasketballPlayer::setPenaltiesToday(int value) {
    penaltiesToday = value;
}
int BasketballPlayer::getPimToday() const {
    return pimToday;
}

void BasketballPlayer::setPimToday(int value) {
    pimToday = value;
}
int BasketballPlayer::getGaToday() const {
    return gaToday;
}

void BasketballPlayer::setGaToday(int value) {
    gaToday = value;
}
int BasketballPlayer::getSavesToday() const {
    return savesToday;
}

void BasketballPlayer::setSavesToday(int value) {
    savesToday = value;
}
int BasketballPlayer::getShotsFacedToday() const {
    return shotsFacedToday;
}

void BasketballPlayer::setShotsFacedToday(int value) {
    shotsFacedToday = value;
}

QString BasketballPlayer::getGaavg() const
{
    return gaavg;
}

void BasketballPlayer::setGaavg(const QString& value)
{
    gaavg = value;
}

void BasketballPlayer::addSave()
{
    savesToday++;
    shotsFacedToday++;
}

void BasketballPlayer::minusSave()
{
    savesToday--;
    shotsFacedToday--;
}

void BasketballPlayer::addGa()
{
    gaToday++;
    shotsFacedToday++;
}

void BasketballPlayer::minusGa()
{
    gaToday--;
    shotsFacedToday--;
}
double BasketballPlayer::getSvPct() const
{
    return svPct;
}

void BasketballPlayer::calcSvPct()
{
    shotsFaced = ga + saves;
    svPct = ((double)saves / shotsFaced) * 100;
}


