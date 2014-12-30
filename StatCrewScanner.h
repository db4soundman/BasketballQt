#ifndef STATCREWSCANNER_H
#define STATCREWSCANNER_H

#include <QObject>
#include <QThread>
#include <QTimer>
#include <QFile>
#include <QDateTime>
#include "BasketballGame.h"
#include "InGameXml.h"
class StatCrewScanner : public QThread
{
    Q_OBJECT
public:
    StatCrewScanner(BasketballGame* game, QString fileName);

    void run();

signals:
    void statCrewStatus(bool isActive);

public slots:
    void toggleScanner(int pd);
    void toggleScanner();

private slots:
    void updateStats();

private:
    InGameXml* statCrew;
    QTimer* trigger;
    bool isActive;
    QString statFile;
    QDateTime lastModified;
};

#endif // STATCREWSCANNER_H
