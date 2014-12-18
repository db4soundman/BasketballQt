#ifndef FOULCONTROL_H
#define FOULCONTROL_H

#include <QWidget>
#include "BasketballGame.h"
#include <QPushButton>
#include <QLabel>

class FoulControl : public QWidget {
    Q_OBJECT
public:
    FoulControl(BasketballGame* game);

signals:
    void showFouls(QString fouls);

public slots:
    void updateHomeFouls(int fouls);
    void updateAwayFouls(int fouls);
    void callFoulDisplay();
private:
    QLabel homeLabel, awayLabel;
    QString homeName, awayName;
    QPushButton hp1, ap1, hm1, am1, show;


};

#endif // SOGCONTROL_H
