#ifndef TRICASTERHANDLER_H
#define TRICASTERHANDLER_H

#include <QThread>
#include <QGraphicsView>
#include <QColor>
#include <stdio.h>
#include <tchar.h>
#include <windows.h>
#include "AirSend_api.h"


class TricasterHandler : public QThread
{
    Q_OBJECT
public:
    TricasterHandler(QGraphicsView* view, QColor pAlphaBlack);

    void run();

signals:

public slots:

private:

    void* tricaster;
    QGraphicsView* screen;
    QColor alphaBlack;
    const QColor alpha;
    BYTE* pixels;
};

#endif // TRICASTERHANDLER_H
