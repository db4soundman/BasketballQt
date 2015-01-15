#ifndef CHECKBOXWIDGET_H
#define CHECKBOXWIDGET_H

#include <QWidget>
#include <QCheckBox>
#include "BasketballGame.h"

class CheckBoxWidget : public QWidget
{
    Q_OBJECT
public:
    CheckBoxWidget(BasketballGame* pgame);

private:
    QCheckBox* statcrew;
};

#endif // CHECKBOXWIDGET_H
