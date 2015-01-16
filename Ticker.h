#ifndef TICKER_H
#define TICKER_H

#include <QGraphicsPixmapItem>
#include <QList>
#include <QLinearGradient>
#include "BasketballGame.h"
#include "BasketballPlayer.h"
#include <QTimer>

class Ticker : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Ticker(int pwidth, BasketballGame* pgame);

    void paint(QPainter * painter,
               const QStyleOptionGraphicsItem * option, QWidget * widget = 0);

public slots:
    void advanceTicker();
    void showTicker();
    void hideTicker();

private:
    void prepareColor();
    QFont resizeText();
    int width;
    int index;
    QList<BasketballPlayer*> players;
    QLinearGradient mainGradient;
    bool show;
    QTimer timer;
    BasketballGame* game;
};

#endif // TICKER_H
