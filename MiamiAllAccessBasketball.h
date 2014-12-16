#ifndef MIAMIALLACCESSBASKETBALL_H
#define MIAMIALLACCESSBASKETBALL_H

#include <QApplication>
#include "BasketballGame.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include "MainWindow.h"
#include "CommercialGraphic.h"
#include "StatCrewScanner.h"

class MiamiAllAccessBasketball : public QApplication {
public:
    MiamiAllAccessBasketball(int &argc, char *argv[]);

    /**
     * @brief getAppDirPath Gets the file path to the application
     * directory.
     * @return A QString representing the file path to the application
     * directory.
     */
    static QString getAppDirPath();

    static QString getPenaltiesFilePath();

    void checkAppDirectory();

    int exec();

private:
    QGraphicsView* tv;
    QGraphicsScene* scene;
    BasketballGame* game;
    MainWindow* controlPanel;
    CommercialGraphic* commercial;
    StatCrewScanner* stats;
};

#endif // MIAMIALLACCESSBASKETBALL_H
