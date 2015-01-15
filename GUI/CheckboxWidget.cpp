#include "CheckboxWidget.h"
#include <QVBoxLayout>

CheckBoxWidget::CheckBoxWidget(BasketballGame *pgame)
{
    statcrew = new QCheckBox("Stat Crew");
    connect(statcrew, SIGNAL(clicked()), pgame, SIGNAL(toggleStatCrew()));
    connect(pgame, SIGNAL(statusOfStatCrew(bool)), statcrew, SLOT(setChecked(bool)));
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(statcrew);
    setLayout(layout);
}
