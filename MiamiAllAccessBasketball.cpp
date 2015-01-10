#include "MiamiAllAccessBasketball.h"
#include <QStandardPaths>
#include <QDir>
#include <QFile>
#include "SetupWizard.h"
#include <QDesktopWidget>
#include <QAction>
#include <QTimer>
#include "TricasterHandler.h"

MiamiAllAccessBasketball::MiamiAllAccessBasketball(int& argc, char* argv[]) :
    QApplication (argc, argv) {
    setApplicationName("Miami All-Access Basketball");
}

QString
MiamiAllAccessBasketball::getAppDirPath() {
    return QStandardPaths::writableLocation(QStandardPaths::DataLocation);
}

QString
MiamiAllAccessBasketball::getPenaltiesFilePath() {
    return QStandardPaths::writableLocation(QStandardPaths::DataLocation)
            + "/penalties.txt";
}

void
MiamiAllAccessBasketball::checkAppDirectory() {
    QDir appDir(QStandardPaths::writableLocation(QStandardPaths::DataLocation));
    if (!appDir.exists()) {
        appDir.mkdir(QStandardPaths::writableLocation(QStandardPaths::DataLocation));
    }
}

int
MiamiAllAccessBasketball::exec() {
    checkAppDirectory();

    // Make vars, create wizard.
    scene = new QGraphicsScene();

    QString awayName, homeName, awayRank, homeRank, homeFile, awayFile, sponsor, announcer,
            statcrewName;
    QColor awayColor, homeColor,  bg;

    homeColor.setRgb(226, 24, 54);
    //bg.setRgb(0,120,0);
    bg.setRgb(0, 120, 0, 255);
    announcer = "Steve Baker and Terry Bridge";
    sponsor = "Miami IMG Sports Network";
    homeName = "MIAMI";

    SetupWizard wizard(&awayName, &homeName, &sponsor,&announcer, &awayRank, &homeRank,
                       &awayColor, &homeColor, &bg, &statcrewName);
    wizard.exec();
    QDesktopWidget desktop;
    QRect graphicsScreen = desktop.screenGeometry(1);
   tv = new QGraphicsView(scene);
   game = new BasketballGame(awayName, homeName, awayColor, homeColor,
                          statcrewName, sponsor, announcer, awayRank,
                          homeRank, graphicsScreen.width() + 1, tv);


    scene->addItem(game->getSb());
    scene->setBackgroundBrush(QBrush(Qt::transparent));
    scene->addItem(game->getLt());
    commercial = new CommercialGraphic(game, graphicsScreen.width());
    scene->addItem(commercial);
    game->getLt()->setX((graphicsScreen.width() / 2) - 214);
    game->getLt()->setY(graphicsScreen.height() - 160);
    game->getSb()->setY(graphicsScreen.height() - 80 - 74);
    game->getSb()->setX((graphicsScreen.width() / 2) - (790/2));
    commercial->setY(graphicsScreen.height() - 230);
    //commercial->setX(460);




    tv->setGeometry(graphicsScreen);
    tv->setSceneRect(0, 0,graphicsScreen.width(), graphicsScreen.height());
    tv->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    tv->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // Get desktop set up and wizard val later...
    /*
    QPalette p = tv->viewport()->palette();
    p.setColor(QPalette::Base, Qt::transparent);
    tv->viewport()->setPalette(p);
    tv->setWindowFlags(Qt::FramelessWindowHint);
    tv->setAttribute(Qt::WA_TranslucentBackground);
    tv->setAttribute(Qt::WA_NoSystemBackground);

    scene->setPalette(p);
    tv->setStyleSheet("background-color: transparent;");

    scene->setBackgroundBrush(bg);
    tv->setAutoFillBackground(true);

    */
    tv->setFrameShape(QFrame::NoFrame);
    tv->setBackgroundBrush(bg);
    tv->showFullScreen();

    if (!statcrewName.isEmpty())
        stats = new StatCrewScanner(game, statcrewName);

    controlPanel = new MainWindow(game, commercial);
    controlPanel->show();
    game->connectWithSerialHandler(&allSportCgController);
    allSportCgController.show();
//    TricasterHandler hand(tv, bg);
//    QTimer* mytimer = new QTimer();
//    mytimer->setInterval(100);
//    connect(mytimer, SIGNAL(timeout()), &hand, SLOT(start()));
//    //hand.start();
//    mytimer->start();
    return QApplication::exec();
}


