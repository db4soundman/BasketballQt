#ifndef DISPLAYCONTROLS_H
#define DISPLAYCONTROLS_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include "BasketballGame.h"
#include "CommercialGraphic.h"
#include "Ticker.h"

class DisplayControls : public QWidget {
    Q_OBJECT
public:
    DisplayControls(BasketballGame* game, CommercialGraphic* comGraphic, Ticker* ticker);

public slots:
    void prepareCustomText();

signals:
    void showCustomText(QString text);

private:
    QLineEdit customtext;
    QPushButton customButton, announcersButton, tickerButton, commericalButton, sbButton, hideButton, sponsorButton, hideLT;
    QString sponsorText;
};

#endif // DISPLAYCONTROLS_H
