#include "Ticker.h"

Ticker::Ticker(int pwidth, BasketballGame* pgame)
{
    width = pwidth;
    timer.setInterval(1000 * 10); // 5 seconds
    connect(&timer, SIGNAL(timeout()), this, SLOT(advanceTicker()));
    game = pgame;
    show = false;
    prepareColor();
}

void Ticker::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    if (show) {
        painter->fillRect(0,0,width, 74, mainGradient);
        painter->fillRect(100, 2, width - 200, 44, QColor(1,1,1));
        painter->setFont(resizeText());
        painter->setPen(QColor(255,255,255));
        painter->drawText(100, 2, width - 200, 44, Qt::AlignCenter, players.at(index)->toString());
    }
}

void Ticker::advanceTicker()
{
    index = (index + 1) % players.size();
    scene()->update(0, this->y(), width, 74);
}

void Ticker::showTicker()
{
    players = game->getPlayersForTicker();
    index = 0;
    show = true;
    timer.start();
    scene()->update(0, this->y(), width, 74);
}

void Ticker::hideTicker()
{
    show = false;
    timer.stop();
    scene()->update(0, this->y(), width, 74);
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

QFont Ticker::resizeText()
{
    int subtraction = 0;
    int fontPointSize = 40;
    QFontMetrics fontSize(QFont("Arial", 40, QFont::Bold));
    while (fontSize.width(players.at(index)->toString()) > width - 205) {
        QFont tempFont("Arial", fontPointSize - subtraction, QFont::Bold);
        subtraction++;
        QFontMetrics temp(tempFont);
        fontSize = temp;
    }
    return QFont("Arial", 40 - subtraction, QFont::Bold);
}

