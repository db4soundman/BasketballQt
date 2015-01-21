#ifndef SETUPPAGE_H
#define SETUPPAGE_H

#include <QWizardPage>
#include <QPushButton>
#include <QColor>
#include <QCheckBox>
#include <QLineEdit>

class SetupPage : public QWizardPage {
    Q_OBJECT
public:
    SetupPage(QString* pAwayName, QString* pHomeName,
              QString* pSponsor, QString* pAnnouncer, QString* pAwayRank, QString* pHomeRank,
              QColor* pAwayColor, QColor* pHomeColor, QColor* pBg, QString* pStatCrew, bool *pUsingTricaster, QString *awayLogo);
    bool validatePage();

private slots:
    void statCrewBrowse();
    void awayColorDiag();
    void homeColorDiag();
    void bgDiag();
    void logoBrowse();

private:
    QString* awayName, *homeName, *awayRank, *homeRank, *homeFile, *awayFile, *sponsor, *announcer, *statCrew, *awayLogo;
    QColor* awayColor, *homeColor,  *bg;
    QPushButton chooseHColor, chooseAColor, chooseBg, browseStatCrew, browseLogo;
    QLineEdit homeNameLine, awayNameLine, awayRankLine, homeRankLine, sponsorLine, announcerLine, tricasterIp;
    QCheckBox* tricasterBox;
    bool* usingTricaster;
};

#endif // SETUPPAGE_H
