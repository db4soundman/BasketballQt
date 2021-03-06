#-------------------------------------------------
#
# Project created by QtCreator 2014-11-28T09:55:06
#
#-------------------------------------------------

QT       += core gui serialport widgets network
QT += xml
QMAKE_MAC_SDK = macosx10.9

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Basketball
TEMPLATE = app

DEFINES *= QT_USE_QSTRINGBUILDER
INCLUDEPATH += GUI \
               Wizard \
            GameStatEditors \
            SerialHandler

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
    GUI/StatDisplayControls.cpp \
    Wizard/SetupPage.cpp \
    Wizard/SetupWizard.cpp \
    BasketballTeam.cpp \
    BasketballPlayer.cpp \
    BasketballGame.cpp \
    GUI/TimeoutControl.cpp \
    GUI/ScoreControl.cpp \
    GUI/FoulControl.cpp \
    GUI/PlayerStatControl.cpp \
    RosterXmlHandler.cpp \
    InGameXml.cpp \
    GUI/TeamComparisonControls.cpp \
    Ticker.cpp \
    SerialHandler/SerialConsole.cpp \
    SerialHandler/console.cpp \
    SerialHandler/settingsdialog.cpp \
    TricasterHandler.cpp \
    GUI/CheckboxWidget.cpp

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
    GUI/StatDisplayControls.h \
    Wizard/SetupPage.h \
    Wizard/SetupWizard.h \
    MiamiAllAccessBasketball.h \
    BasketballTeam.h \
    BasketballPlayer.h \
    BasketballGame.h \
    GUI/TimeoutControl.h \
    GUI/ScoreControl.h \
    GUI/FoulControl.h \
    GUI/PlayerStatControl.h \
    RosterXmlHandler.h \
    InGameXml.h \
    GUI/TeamComparisonControls.h \
    Ticker.h \
    SerialHandler/SerialConsole.h \
    SerialHandler/console.h \
    SerialHandler/settingsdialog.h \
    TricasterHandler.h \
    AirSend_api.h \
    GUI/CheckboxWidget.h

RESOURCES += \
    graphics.qrc \
    terminal.qrc

FORMS += \
    SerialHandler/SerialConsole.ui \
    SerialHandler/settingsdialog.ui

INCLUDEPATH += $$PWD/
DEPENDPATH += $$PWD/
unix|win32: LIBS += -L$$PWD/ -lProcessingAirSendx86


