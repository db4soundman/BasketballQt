#ifndef STATCREWSCANNER_H
#define STATCREWSCANNER_H

#include <QObject>
#include <QTimer>
#include <QFile>
#include <QDateTime>
#include "BasketballGame.h"
class StatCrewScanner : public QObject
{
    Q_OBJECT
public:
    StatCrewScanner(BasketballGame* game, QString fileName);

public slots:
    void toggleScanner(int pd);
    void toggleScanner();

private slots:
    void updateStats();

private:
    //GameXmlUpdater* statCrew;
    QTimer* trigger;
    bool isActive;
    QFile statFile;
    QDateTime lastModified;
};

#endif // STATCREWSCANNER_H
