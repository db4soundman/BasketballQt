#ifndef COMMERCIALGRAPHIC_H
#define COMMERCIALGRAPHIC_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QFont>
#include "BasketballGame.h"
#include <QLinearGradient>
#include <QPainter>
#include <QGraphicsTextItem>

class CommercialGraphic : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    CommercialGraphic(BasketballGame* game, int width, QGraphicsItem *parent = 0);

    void paint(QPainter * painter,
               const QStyleOptionGraphicsItem * option, QWidget * widget = 0);

signals:
    void sceneUpdated();
public slots:
    void prepareAndShow();
    void updateClock();
    void showClock();
    void intermissionTime();
    void finalTime();
    void hide();

private:
    QPixmap blackBar;
    QLinearGradient homeTeamGradient, awayTeamGradient;
    BasketballGame* basketballGame;
    bool show, inGame;
    QGraphicsTextItem* away, *home;
    QString homeScore, awayScore, maaText, period, clock;
    QFont descriptiveFont;
    int clockStatus, WIDTH, NAME_WIDTH;
    void checkAwayFont();
    void prepareGradients(QColor awayColor, QColor homeColor);
};

#endif // COMMERCIALGRAPHIC_H
