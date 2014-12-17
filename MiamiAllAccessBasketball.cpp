#include "MiamiAllAccessBasketball.h"
#include <QStandardPaths>
#include <QDir>
#include <QFile>
#include "SetupWizard.h"
#include <QDesktopWidget>
#include <QAction>

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
    //checkAppDirectory();

    // Make vars, create wizard.
    scene = new QGraphicsScene();

    QString awayName, homeName, awayRank, homeRank, homeFile, awayFile, sponsor, announcer,
            goalies, statcrewName;
    QColor awayColor, homeColor,  bg;
    int pk, pkopp, ppg, ppopp;

    homeColor.setRgb(226, 24, 54);
    bg.setRgb(0,120,0);
    announcer = "Steve Baker and Terry Bridge";
    sponsor = "Miami IMG Sports Network";
    homeName = "MIAMI";
    QDesktopWidget desktop;
    QRect graphicsScreen = desktop.screenGeometry(1);
    SetupWizard wizard(&awayName, &homeName, &awayFile, &homeFile, &sponsor,
                       &announcer, &awayRank, &homeRank, &awayColor, &homeColor,
                       &bg, &pk, &pkopp, &ppg, &ppopp, &goalies, &statcrewName);
    wizard.exec();
    game = new BasketballGame(awayName, homeName, awayColor, homeColor,
                          awayFile, homeFile, sponsor, announcer, awayRank,
                          homeRank, graphicsScreen.width() + 1);
    BasketballTeam* team = game->getAwayTeam();


    scene->addItem(game->getSb());

    scene->addItem(game->getLt());
    commercial = new CommercialGraphic(game, graphicsScreen.width());
    scene->addItem(commercial);
    game->getLt()->setX((graphicsScreen.width() / 2) - 214);
    game->getLt()->setY(graphicsScreen.height() - 160);
    game->getSb()->setY(80);
    game->getSb()->setX((graphicsScreen.width() / 2) - 551);
    commercial->setY(graphicsScreen.height() - 230);
    //commercial->setX(460);
    tv = new QGraphicsView(scene);



    tv->setGeometry(graphicsScreen);
    tv->setSceneRect(0, 0,graphicsScreen.width(), graphicsScreen.height());
    tv->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    tv->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // Get desktop set up and wizard val later...
    tv->setBackgroundBrush(bg);
    //tv->setFixedSize(1600,900);
    //tv->show();
    tv->setFrameShape(QFrame::NoFrame);
    tv->showFullScreen();

    if (!statcrewName.isEmpty())
        stats = new StatCrewScanner(game, statcrewName);

    controlPanel = new MainWindow(game, commercial);
    controlPanel->show();
    return QApplication::exec();
}


