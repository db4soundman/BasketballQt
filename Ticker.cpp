#include "Ticker.h"

Ticker::Ticker(int pwidth, BasketballGame* game)
{
    width = pwidth;
}

void Ticker::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{

}

void Ticker::prepareColor()
{
    mainGradient.setStart(0,0);
    mainGradient.setFinalStop(0, 74);
    mainGradient.setColorAt(0, QColor(0,0,0));
    mainGradient.setColorAt(1, QColor(0,0,0));
    mainGradient.setColorAt(.4, QColor(156,0,0));
    mainGradient.setColorAt(.6, QColor(156,0,0));
}
