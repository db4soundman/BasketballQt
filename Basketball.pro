#-------------------------------------------------
#
# Project created by QtCreator 2014-11-28T09:55:06
#
#-------------------------------------------------

QT       += core gui
QT += xml
QMAKE_MAC_SDK = macosx10.9

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Basketball
TEMPLATE = app

DEFINES *= QT_USE_QSTRINGBUILDER
INCLUDEPATH += GUI \
               Wizard \
            GameStatEditors

SOURCES += main.cpp\
        MainWindow.cpp \
    Clock.cpp \
    CommercialGraphic.cpp \
    LowerThird.cpp \
    LowerThirdCreator.cpp \
    MiamiAllAccessBasketball.cpp \
    Scoreboard.cpp \
    StatCrewScanner.cpp \
    GameStatEditors/PlayerEditor.cpp \
    GameStatEditors/TeamEditor.cpp \
    GUI/ClockControls.cpp \
    GUI/ClockDialog.cpp \
    GUI/ControlPanel.cpp \
    GUI/DisplayControls.cpp \
    GUI/GameInfo.cpp \
    GUI/GoalDisplayWidget.cpp \
    GUI/Goalies.cpp \
    GUI/HomeStatControl.cpp \
    GUI/PenaltyControl.cpp \
    GUI/PenaltyDisplay.cpp \
    GUI/PowerPlayUpdaters.cpp \
    GUI/ScoreControl.cpp \
    GUI/SogControl.cpp \
    GUI/StatDisplayControls.cpp \
    GUI/VisitingGameStatControl.cpp \
    Wizard/SetupPage.cpp \
    Wizard/SetupWizard.cpp \
    BasketballTeam.cpp \
    BasketballPlayer.cpp \
    BasketballGame.cpp

HEADERS  += MainWindow.h \
    Clock.h \
    CommercialGraphic.h \
    LowerThird.h \
    LowerThirdCreator.h \
    Scoreboard.h \
    StatCrewScanner.h \
    GameStatEditors/PlayerEditor.h \
    GameStatEditors/TeamEditor.h \
    GUI/ClockControls.h \
    GUI/ClockDialog.h \
    GUI/ControlPanel.h \
    GUI/DisplayControls.h \
    GUI/GameInfo.h \
    GUI/GoalDisplayWidget.h \
    GUI/Goalies.h \
    GUI/HomeStatControl.h \
    GUI/PenaltyControl.h \
    GUI/PenaltyDisplay.h \
    GUI/PowerPlayUpdaters.h \
    GUI/ScoreControl.h \
    GUI/SogControl.h \
    GUI/StatDisplayControls.h \
    GUI/VisitingGameStatControl.h \
    Wizard/SetupPage.h \
    Wizard/SetupWizard.h \
    MiamiAllAccessBasketball.h \
    BasketballTeam.h \
    BasketballPlayer.h \
    BasketballGame.h

RESOURCES += \
    graphics.qrc
