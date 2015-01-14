#ifndef TRICASTERHANDLER_H
#define TRICASTERHANDLER_H

#include <QThread>
#include <QGraphicsView>
#include <QColor>
#include <stdio.h>
#include <tchar.h>
#include <windows.h>
#include "AirSend_api.h"
#include <QImage>

class TricasterHandler : public QThread
{
    Q_OBJECT
public:
    TricasterHandler(QGraphicsView* view, QColor pAlphaBlack);

    void run();

signals:

public slots:
    void srun();
    void ensureUpdate();
    void updatePortion(int x, int y, int w, int h);
private:

    void* tricaster;
    QGraphicsView* screen;
    const QColor alphaBlack;
    BYTE* pixels;
    QImage view;
};

#endif // TRICASTERHANDLER_H
