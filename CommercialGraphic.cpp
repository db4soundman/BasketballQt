#include "CommercialGraphic.h"
#include <QFontMetrics>
#include <QGraphicsScene>

//#define WIDTH 1920/2
//#define NAME_WIDTH 860
#define RECT_HEIGHT 120
#define CENTER_OFFSET 200
#define BLACK_BAR_HEIGHT 60
#define GRADIENT_LEVEL .5
#define SHOW_CLOCK 0
#define INTERMISSION 1
#define FINAL 2

CommercialGraphic::CommercialGraphic(BasketballGame* game, int width, QString pawayLogo, QGraphicsItem* parent) :
    QGraphicsPixmapItem(parent), blackBar(QPixmap(":/images/ppBar.png")), blockText(QPixmap(":/images/M.png")),
    awayLogo(pawayLogo){
    basketballGame = game;
    show = false;
    WIDTH = width / 2;
    NAME_WIDTH = WIDTH - CENTER_OFFSET;
    inGame  = false;
    QFont font("Arial", 60, QFont::Bold);
    QFont sponsorFont("Arial", 36, QFont::Bold);
#ifdef Q_OS_OSX
    font.setPointSize(68);
    sponsorFont.setPointSize(44);
#endif
    setPixmap(QPixmap(":/images/Scoreboard.png"));
    away = new QGraphicsTextItem(game->getAwayName());
    away->setFont(font);
    checkAwayFont();
    home = new QGraphicsTextItem(game->getHomeName());
    home->setFont(font);

    descriptiveFont = sponsorFont;
    prepareGradients(game->getAwayColor(), game->getHomeColor());
    maaText = "Miami All-Access";
    clockStatus = SHOW_CLOCK;
    connect(game->getGameClock(), SIGNAL(clockUpdated()), this, SLOT(updateClock()));
    if (awayLogo.height() > 120) {
        awayLogo = awayLogo.scaledToHeight(120, Qt::SmoothTransformation);
    }
    if (blockText.height() > 120) {
        blockText = blockText.scaledToHeight(120, Qt::SmoothTransformation);
    }
}

void CommercialGraphic::paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
                              QWidget* widget) {
    if (show){
        painter->setPen(QColor(255, 255, 255));
        //painter->drawPixmap(WIDTH/2, -BLACK_BAR_HEIGHT, WIDTH, BLACK_BAR_HEIGHT, blackBar);
        painter->drawPixmap(WIDTH/2,0, WIDTH, BLACK_BAR_HEIGHT, blackBar);
        painter->setFont(descriptiveFont);
        painter->drawText(WIDTH / 2, 0, WIDTH, BLACK_BAR_HEIGHT, Qt::AlignCenter, maaText);

        painter->fillRect(0, BLACK_BAR_HEIGHT, WIDTH, RECT_HEIGHT, awayTeamGradient);
        painter->fillRect(WIDTH, BLACK_BAR_HEIGHT, WIDTH, RECT_HEIGHT, homeTeamGradient);
        painter->setFont(away->font());
        //painter->drawText(10, BLACK_BAR_HEIGHT, NAME_WIDTH, RECT_HEIGHT, Qt::AlignCenter, away->toPlainText());
        painter->setFont(home->font());
        //painter->drawText(WIDTH + CENTER_OFFSET, BLACK_BAR_HEIGHT, NAME_WIDTH, RECT_HEIGHT, Qt::AlignCenter, home->toPlainText());
        painter->setOpacity(.996);
        painter->drawPixmap(WIDTH - CENTER_OFFSET - 100 - awayLogo.width(), BLACK_BAR_HEIGHT, awayLogo);
        painter->drawPixmap(WIDTH + CENTER_OFFSET + 100, BLACK_BAR_HEIGHT, blockText);
        painter->setOpacity(1);
        painter->fillRect(WIDTH - CENTER_OFFSET, BLACK_BAR_HEIGHT, CENTER_OFFSET * 2, RECT_HEIGHT, QColor(0,0,0, 100));

        painter->drawText(WIDTH - CENTER_OFFSET, BLACK_BAR_HEIGHT, CENTER_OFFSET, RECT_HEIGHT, Qt::AlignCenter, awayScore);
        painter->drawText(WIDTH, BLACK_BAR_HEIGHT, CENTER_OFFSET, RECT_HEIGHT, Qt::AlignCenter, homeScore);


        painter->drawPixmap(WIDTH - 200, RECT_HEIGHT + BLACK_BAR_HEIGHT, WIDTH - (WIDTH- 400), BLACK_BAR_HEIGHT, blackBar);
        painter->setFont(descriptiveFont);
        if (clockStatus != SHOW_CLOCK) {
            painter->drawText(WIDTH - 200, RECT_HEIGHT + BLACK_BAR_HEIGHT, WIDTH - (WIDTH- 400), BLACK_BAR_HEIGHT, Qt::AlignCenter, clock);
        }
        else {
            painter->drawText(WIDTH- 190, RECT_HEIGHT + BLACK_BAR_HEIGHT, WIDTH - (WIDTH- 400), BLACK_BAR_HEIGHT, Qt::AlignLeft, period);
            painter->drawText(WIDTH-200, RECT_HEIGHT + BLACK_BAR_HEIGHT, WIDTH - (WIDTH- 390), BLACK_BAR_HEIGHT, Qt::AlignRight, clock);
        }
    }
}

void CommercialGraphic::prepareAndShow()
{
    awayScore = QString::number(basketballGame->getAwayScore());
    homeScore = QString::number(basketballGame->getHomeScore());

    switch (basketballGame->getPeriod()) {
    case 0:
        inGame = false;
        period = "Starts in";
        break;
    case 1:
        inGame = true;
        period = "1st";
        break;
    case 2:
        period = "2nd";
        break;
    default:
        period = "OT";
        break;
    }
    show = true;
    updateClock();
}

void CommercialGraphic::updateClock()
{
    if (show) {
        if (clockStatus == SHOW_CLOCK) {
            clock = basketballGame->getGameClock()->toString();
        }
        else if (clockStatus == INTERMISSION) {
            clock = "HALFTIME";
        }
        else {
            clock = "FINAL";
        }

        scene()->update();

        //basketballGame->takePicture();
    }
}

void CommercialGraphic::showClock() {
    clockStatus = SHOW_CLOCK;
    if (show)
        scene()->update();
}

void CommercialGraphic::intermissionTime()
{
    clockStatus = INTERMISSION;
    if (show)
        scene()->update();
}

void CommercialGraphic::finalTime()
{
    clockStatus = FINAL;
    if (show)
        scene()->update();
}

void CommercialGraphic::hide()
{
    if (show) {
        show = false;
        scene()->update();
    }
}

void CommercialGraphic::checkAwayFont()
{
    int fontPointSize = away->font().pointSize();
    int subtraction = 1;
    QFontMetrics fontSize(away->font());
    while (fontSize.width(away->toPlainText()) > NAME_WIDTH - 5) {
        QFont tempFont("Arial", fontPointSize - subtraction, QFont::Bold);
        subtraction++;
        away->setFont(tempFont);
        QFontMetrics temp(away->font());
        fontSize = temp;
    }
}

void CommercialGraphic::prepareGradients(QColor awayColor, QColor homeColor)
{
    homeTeamGradient.setStart(0, BLACK_BAR_HEIGHT);
    homeTeamGradient.setFinalStop(0, BLACK_BAR_HEIGHT + RECT_HEIGHT);
    awayTeamGradient.setStart(0,BLACK_BAR_HEIGHT);
    awayTeamGradient.setFinalStop(0, BLACK_BAR_HEIGHT + RECT_HEIGHT);
    int red, green, blue;
    red = -1*homeColor.red() *GRADIENT_LEVEL + homeColor.red();
    green = -1*homeColor.green() *GRADIENT_LEVEL + homeColor.green();
    blue = -1*homeColor.blue() *GRADIENT_LEVEL + homeColor.blue();

    QColor end(red, green, blue);
    if (end == QColor(0,0,0))
            end = QColor(1,1,1);
    homeTeamGradient.setColorAt(.4, homeColor);
    homeTeamGradient.setColorAt(.6, homeColor);
    homeTeamGradient.setColorAt(1, end);
    homeTeamGradient.setColorAt(0, end);

    red = -1*awayColor.red() *GRADIENT_LEVEL + awayColor.red();
    green = -1*awayColor.green() *GRADIENT_LEVEL + awayColor.green();
    blue = -1*awayColor.blue() *GRADIENT_LEVEL + awayColor.blue();
    QColor end2(red, green, blue);
    if (end2 == QColor(0,0,0))
            end2 = QColor(1,1,1);
    awayTeamGradient.setColorAt(.4, awayColor);
    awayTeamGradient.setColorAt(.6, awayColor);
    awayTeamGradient.setColorAt(1, end2);
    awayTeamGradient.setColorAt(0, end2);
}
