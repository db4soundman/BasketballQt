#include "SetupPage.h"
#include <QLabel>
#include <QGridLayout>
#include <QFileDialog>
#include <QColorDialog>

SetupPage::SetupPage(QString* pAwayName, QString* pHomeName, QString* pSponsor, QString* pAnnouncer,
                     QString* pAwayRank, QString* pHomeRank, QColor* pAwayColor,
                     QColor* pHomeColor, QColor* pBg, QString* pStatCrew, bool* pUsingTricaster,
                     QString* awayLogo, QString* tricasterIp) {
    chooseAColor.setText("Color");
    chooseHColor.setText("Color");
    chooseBg.setText("Background Color");
    browseStatCrew.setText("File");
    awayName = pAwayName;
    homeName = pHomeName;
    sponsor = (pSponsor);
    announcer = (pAnnouncer);
    awayRank = (pAwayRank);
    homeRank = (pHomeRank);
    awayColor = (pAwayColor);
    homeColor = pHomeColor;
    statCrew = pStatCrew;
    bg = pBg;
    usingTricaster = pUsingTricaster;
    this->awayLogo = awayLogo;
    this->tricasterIp = tricasterIp;
    QGridLayout* mainLayout = new QGridLayout();
    mainLayout->addWidget(new QLabel("Away Team:"), 0, 0);
    mainLayout->addWidget(&awayNameLine, 0, 1);
    mainLayout->addWidget(&chooseAColor, 0, 2);
    browseLogo.setText("Logo");
    mainLayout->addWidget(&browseLogo, 0, 3);

    mainLayout->addWidget(new QLabel("Home Team:"), 1, 0);
    mainLayout->addWidget(&homeNameLine, 1, 1);
    mainLayout->addWidget(&chooseHColor, 1, 2);

    mainLayout->addWidget(new QLabel("Away Team Rank:"), 2, 0);
    mainLayout->addWidget(&awayRankLine, 2, 1);
    mainLayout->addWidget(new QLabel("Home Team Rank:"), 3, 0);
    mainLayout->addWidget(&homeRankLine, 3, 1);
    mainLayout->addWidget(&chooseBg, 4, 0);
    sponsorLine.setText(*sponsor);
    mainLayout->addWidget(new QLabel("Sponsor:"), 5, 0);
    mainLayout->addWidget(&sponsorLine, 5, 1);
    mainLayout->addWidget(new QLabel("Announcers"), 6, 0);
    mainLayout->addWidget(&announcerLine, 6, 1);
    mainLayout->addWidget(new QLabel("StatCrew File"), 7, 0);
    mainLayout->addWidget(&browseStatCrew, 7, 1);
    tricasterBox = new QCheckBox("Using Tricaster");
    tricasterBox->setChecked(true);
    mainLayout->addWidget(tricasterBox, 8, 0);
    mainLayout->addWidget(&tricasterIpLine, 8, 1);

    setLayout(mainLayout);

    connect(&chooseAColor, SIGNAL(clicked()), this, SLOT(awayColorDiag()));
    connect(&chooseHColor, SIGNAL(clicked()), this, SLOT(homeColorDiag()));
    connect(&chooseBg, SIGNAL(clicked()), this, SLOT(bgDiag()));
    connect(&browseStatCrew, SIGNAL(clicked()), this, SLOT(statCrewBrowse()));
    connect(&browseLogo, SIGNAL(clicked()), this, SLOT(logoBrowse()));

    homeNameLine.setText(*homeName);
    announcerLine.setText(*announcer);
    setTitle("Game Information");
}

bool SetupPage::validatePage()
{
    *awayRank = awayRankLine.text();
    *homeRank = homeRankLine.text();
    *sponsor = sponsorLine.text();
    *announcer = announcerLine.text();
    *awayName = awayNameLine.text().toUpper();
    *homeName = homeNameLine.text().toUpper();
    *usingTricaster = tricasterBox->isChecked();
    *tricasterIp = tricasterIpLine.text();
    return true;
}

void SetupPage::statCrewBrowse()
{
    QString file = QFileDialog::getOpenFileName(0, "StatCrew Game File");
    if (!file.isEmpty())
        *statCrew = file;
}

void SetupPage::awayColorDiag()
{
    QColor temp = QColorDialog::getColor(*awayColor, 0, "Away Color");
    if (temp.isValid())
        *awayColor = temp;
}

void SetupPage::homeColorDiag()
{
    QColor temp = QColorDialog::getColor(*homeColor, 0, "Home Color");
    if (temp.isValid())
        *homeColor = temp;
}

void SetupPage::bgDiag()
{
    QColor temp = QColorDialog::getColor(*bg, 0, "Background Color");
    if (temp.isValid())
        *bg = temp;
}

void SetupPage::logoBrowse()
{
    QString file = QFileDialog::getOpenFileName(0, "Away Team Logo");
    if (!file.isEmpty())
        *awayLogo = file;
}
