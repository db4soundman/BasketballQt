#ifndef LOWERTHIRD_H
#define LOWERTHIRD_H

#include <QGraphicsPixmapItem>
#include <QLinearGradient>
#include <QPainter>
#include <QObject>
#include <QList>
#include <QString>
#include <QFont>
#include <QColor>

class LowerThird : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    LowerThird(QColor awayColor, QColor homeColor, int screenWidth, QGraphicsItem* parent = 0);

    void paint(QPainter * painter,
               const QStyleOptionGraphicsItem * option, QWidget * widget = 0);



public slots:
    void hideLt();
    void showLt();
    void prepareForDisplay(QString name, QString number, QList<QString> statLabels,
                           QList<QString> statValues, bool homeTeam);
    void prepareForCustomLt(QString name, QString number, QList<QString> statLabels,
                           QList<QString> statValues, bool homeTeam);

private:
    QList<QString> statNames;
    QList<QString> statistics;
    QString name, number, firstName, lastName;
    QFont statFont, nameFont;
    QLinearGradient gradient, statGradient, homeNameGradient, awayNameGradient, homeStatGradient, awayStatGradient;
    QColor homeTeamMain, awayTeamMain;

    QString homeName, awayName, homeLabel, awayLabel, homeStat, awayStat;

    void prepareColors();
    void prepareFontSize();
    void adjustFont();

    bool show, showComp;
    int fontPointSize, statFontPointSize, centerPoint;
};

#endif // LOWERTHIRD_H
