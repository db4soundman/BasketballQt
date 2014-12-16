#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsScene>
#include <QMainWindow>
#include "BasketballGame.h"
#include "ControlPanel.h"
#include "CommercialGraphic.h"
#include "PlayerEditor.h"
#include "TeamEditor.h"
#include "LowerThirdCreator.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(BasketballGame* game, CommercialGraphic* comGraphic, QWidget *parent = 0);
    ~MainWindow();

private:
    ControlPanel panel;
    PlayerEditor awayPlayerEdit, homePlayerEdit;
    TeamEditor awayEdit, homeEdit;
    LowerThirdCreator ltCreator;

    void makeMenu(BasketballGame* game);
};

#endif // MAINWINDOW_H
