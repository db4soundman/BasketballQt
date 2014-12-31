#include "LowerThird.h"
#include <QFontMetrics>
#include <QStringRef>
#include <QGraphicsScene>
#include <QRect>

#define NAME_GRADIENT_LEVEL .7
#define STAT_GRADIENT_LEVEL .7
#define NAME_WIDTH 310
LowerThird::LowerThird(QColor awayColor, QColor homeColor, int screenWidth, QGraphicsItem* parent) : QGraphicsPixmapItem(parent),
    name(""), number("number"), statFont("Arial", 32, QFont::Bold), nameFont("Arial", 32, QFont::Bold),
    awayTeamMain(awayColor), homeTeamMain(homeColor) {
#ifdef Q_OS_OSX
    statFont.setPointSize(36);
    nameFont.setPointSize(36);
#endif
    fontPointSize = nameFont.pointSize();
    setPixmap(QPixmap(":/images/LowerThird.png"));
    statFontPointSize = statFont.pointSize();
    gradient.setStart(0, 0);
    gradient.setFinalStop(0, 120);
    homeNameGradient.setStart(0, 0);
    homeNameGradient.setFinalStop(0, 120);
    awayNameGradient.setStart(0, 0);
    awayNameGradient.setFinalStop(0, 120);
    statGradient.setStart(0, 47);
    statGradient.setFinalStop(0, 120);
    homeStatGradient.setStart(0, 47);
    homeStatGradient.setFinalStop(0, 120);
    awayStatGradient.setStart(0, 47);
    awayStatGradient.setFinalStop(0, 120);
    labelGradient.setStart(0, -47);
    labelGradient.setFinalStop(0,0);
    prepareColors();
    statistics.append("");
    statNames.append("");
    this->centerPoint = screenWidth / 2;
    show = false;
    showComp = false;
}

void
LowerThird::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                  QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);
    if (show) {
        painter->drawPixmap(0, 0, this->pixmap());
        painter->fillRect(-372, 0, 372, 120, gradient);
        painter->fillRect(0, 47, 800, 72, statGradient);
        painter->fillRect(0, 47, 800, 72, QColor(0, 0, 0, 60));

        painter->setFont(nameFont);
        painter->setPen(QColor(255,255,255));
        painter->drawText(-370, 0, NAME_WIDTH, 120, Qt::AlignVCenter, firstName + "\n" + lastName);
        painter->drawText(-60, 0, 60, 60, Qt::AlignCenter, number);
        //painter->drawText(-60, 60, 60, 60, Qt::AlignCenter, year);
        painter->setFont(statFont);

        int rectWidth = 800/statistics.size();
        // Stat Labels
        painter->setPen(QColor(0, 0, 0));
        for (int i = 0; i< statNames.size(); i++) {
            painter->drawText(rectWidth * i, 0, rectWidth, 47, Qt::AlignCenter, statNames.at(i));
        }

        painter->setPen(QColor(255, 255, 255));
        // Stat numbers

        for (int i = 0; i< statistics.size(); i++) {
            painter->drawText(rectWidth * i, 47, rectWidth, 72, Qt::AlignCenter | Qt::TextWordWrap, statistics.at(i));
        }

    }

    else if (showComp) {
        //painter->drawPixmap(0, 0, this->pixmap());
        painter->fillRect(-372, 0, 372 + 800, 60, awayNameGradient);
        painter->fillRect(-372, 60, 372 + 800, 60, homeNameGradient);
        painter->fillRect(0, -47, 800, 47, labelGradient);
        painter->fillRect(0, 0, 800, 120, QColor(0, 0, 0, 60));

        painter->setFont(nameFont);
        painter->setPen(QColor(255,255,255));

        painter->drawText(-370, 0, NAME_WIDTH, 60, Qt::AlignVCenter, awayName);
        painter->drawText(-370, 60, NAME_WIDTH, 60, Qt::AlignVCenter, homeName);

        //painter->drawText(-60, 0, 60, 60, Qt::AlignCenter, number);
        //painter->drawText(-60, 60, 60, 60, Qt::AlignCenter, year);
        painter->setFont(statFont);

        int rectWidth = 800/statNames.size();
        // Stat Labels
        painter->setPen(QColor(0, 0, 0));
        for (int i = 0; i< statNames.size(); i++) {
            painter->drawText(rectWidth * i, -47, rectWidth, 47, Qt::AlignCenter, statNames.at(i));
        }

        painter->setPen(QColor(255, 255, 255));
        // Stat numbers

        for (int i = 0; i< statistics.size(); i+=2) {
            painter->drawText(rectWidth * i, 0, rectWidth, 60, Qt::AlignCenter, statistics.at(i));
            painter->drawText(rectWidth * i, 60, rectWidth, 60, Qt::AlignCenter, statistics.at(i + 1));
        }
    }
}

void
LowerThird::prepareForDisplay(QString name, QString number,
                              QList<QString> statLabels,
                              QList<QString> statValues, bool homeTeam) {
    this->name = name;
    if (name.contains(" ")) {
        firstName = name.left(name.indexOf(" "));
        QStringRef substr(&name, name.indexOf(" ") + 1, name.length() - (name.indexOf(" ")+1));
        lastName = substr.toString();
    }
    else {
        firstName = name;
        lastName = "";
    }
    this->number = number;
    statNames = statLabels;
    statistics = statValues;
    gradient = homeTeam ? homeNameGradient : awayNameGradient;
    statGradient = homeTeam ? homeStatGradient : awayStatGradient;
    prepareFontSize();
    // To ensure font size is returned to normal in the event that
    // a custom text LT was used.
    statFont.setPointSize(statFontPointSize);
    showLt();
}

void LowerThird::prepareForCustomLt(QString name, QString number,
                                    QList<QString> statLabels,
                                    QList<QString> statValues, bool homeTeam)
{
    statFont.setPointSize(statFontPointSize);
    this->name = name;
    if (name.contains(" ")) {
        firstName = name.left(name.indexOf(" "));
        QStringRef substr(&name, name.indexOf(" ") + 1, name.length() - (name.indexOf(" ")+1));
        lastName = substr.toString();
    }
    else {
        firstName = name;
        lastName = "";
    }
    this->number = number;
    statNames = statLabels;
    statistics = statValues;
    gradient = homeTeam ? homeNameGradient : awayNameGradient;
    statGradient = homeTeam ? homeStatGradient : awayStatGradient;
    // Resize the font to be two lines ONLY if necessary...
    QFontMetrics fontSize(statFont);
    if (fontSize.width(statistics[0]) > this->pixmap().width() - 100)
        adjustFont();
    showLt();
}

void LowerThird::prepareForCompLt(QString awayName, QString homeName, QList<QString> statLabels, QList<QString> statValues)
{
   this->awayName = awayName;
    this->homeName = homeName;
    statNames = statLabels;
    statistics = statValues;
    // To ensure font size is returned to normal in the event that
    // a custom text LT was used.
    statFont.setPointSize(statFontPointSize);
    showCompLt();
}

void LowerThird::prepareColors() {
    int red, green, blue;
    red = -1*homeTeamMain.red() *NAME_GRADIENT_LEVEL + homeTeamMain.red();
    green = -1*homeTeamMain.green() *NAME_GRADIENT_LEVEL + homeTeamMain.green();
    blue = -1*homeTeamMain.blue() *NAME_GRADIENT_LEVEL + homeTeamMain.blue();

    QColor end(red, green, blue);
    homeNameGradient.setColorAt(0.45, homeTeamMain);
    homeNameGradient.setColorAt(0.55, homeTeamMain);
    homeNameGradient.setColorAt(1, end);
    homeNameGradient.setColorAt(0, end);

    red = -1*homeTeamMain.red() *STAT_GRADIENT_LEVEL + homeTeamMain.red();
    green = -1*homeTeamMain.green() *STAT_GRADIENT_LEVEL + homeTeamMain.green();
    blue = -1*homeTeamMain.blue() *STAT_GRADIENT_LEVEL + homeTeamMain.blue();
    end.setRgb(red, green, blue);
    homeStatGradient.setColorAt(.5, homeTeamMain);
    homeStatGradient.setColorAt(1, end);
    homeStatGradient.setColorAt(0, end);

    // -------------------------------------Away Team--------------------------------

    red = -1*awayTeamMain.red() *NAME_GRADIENT_LEVEL + awayTeamMain.red();
    green = -1*awayTeamMain.green() *NAME_GRADIENT_LEVEL + awayTeamMain.green();
    blue = -1*awayTeamMain.blue() *NAME_GRADIENT_LEVEL + awayTeamMain.blue();
    end.setRgb(red, green, blue);
    awayNameGradient.setColorAt(0.45, awayTeamMain);
    awayNameGradient.setColorAt(0.55, awayTeamMain);
    awayNameGradient.setColorAt(1, end);
    awayNameGradient.setColorAt(0, end);

    red = -1*awayTeamMain.red() *STAT_GRADIENT_LEVEL + awayTeamMain.red();
    green = -1*awayTeamMain.green() *STAT_GRADIENT_LEVEL + awayTeamMain.green();
    blue = -1*awayTeamMain.blue() *STAT_GRADIENT_LEVEL + awayTeamMain.blue();
    end.setRgb(red, green, blue);
    awayStatGradient.setColorAt(.5, awayTeamMain);
    awayStatGradient.setColorAt(1, end);
    awayStatGradient.setColorAt(0, end);

    labelGradient.setColorAt(0, QColor(255,255,255));
    labelGradient.setColorAt(1, QColor(255,255,255));
    labelGradient.setColorAt(.45, QColor(180,180,180));
    labelGradient.setColorAt(.55, QColor(180,180,180));
}

void
LowerThird::prepareFontSize() {
    int subtraction = 1;
    QFontMetrics fontSize(nameFont);
    while (fontSize.width(firstName) > NAME_WIDTH ||
           fontSize.width(lastName) > NAME_WIDTH) {
        QFont tempFont("Arial", fontPointSize - subtraction, QFont::Bold);
        //nameFont.setPointSize(fontPointSize - subtraction);
        subtraction++;
        nameFont = tempFont;
        QFontMetrics temp(nameFont);
        fontSize = temp;
    }
}

void LowerThird::adjustFont()
{
    statFont.setPointSize(22);
#ifdef Q_OS_OSX
    statFont.setPointSize(28);
#endif
    int subtraction = 1;
    QFontMetrics fontSize(statFont);
    while (fontSize.width(statistics[0]) > this->pixmap().width() * 2 - 100) {
        QFont tempFont("Arial", statFont.pointSize() - subtraction, QFont::Bold);
        subtraction++;
        statFont = tempFont;
        QFontMetrics temp(statFont);
        fontSize = temp;
    }
}

void
LowerThird::hideLt() {
    show = false;
    showComp = false;
    scene()->update();
}

void
LowerThird::showLt() {
    show = true;
    showComp = false;
    scene()->update();
}

void LowerThird::showCompLt()
{
    show = false;
    showComp = true;
    scene()->update();
}

