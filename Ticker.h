#ifndef TICKER_H
#define TICKER_H

#include <QGraphicsPixmapItem>
#include <QList>
#include <QLinearGradient>
#include "BasketballGame.h"
#include "BasketballPlayer.h"

class Ticker : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Ticker(int pwidth, BasketballGame* game);

    void paint(QPainter * painter,
               const QStyleOptionGraphicsItem * option, QWidget * widget = 0);

public slots:


private:
    void prepareColor();
    int width;
    int index;
    QList<BasketballPlayer*> players;
    QLinearGradient mainGradient;
};

#endif // TICKER_H
