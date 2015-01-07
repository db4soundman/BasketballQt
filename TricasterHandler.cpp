#include "TricasterHandler.h"
#include "AirSend_api.h"

TricasterHandler::TricasterHandler(QGraphicsView *view, QColor pAlphaBlack) : alpha(QColor(0,0,0,0)),
    alphaBlack(pAlphaBlack)
{
    screen = view;
    tricaster = AirSend_Create(1920, 1080,3000,1001,false, 16.0/9.0, false, 0,0);
    // Connect
    //AirSend_request_connection(tricaster);
    pixels = new BYTE[1920*1080*2];
}

void TricasterHandler::run()
{
   /* QPixmap pix = QPixmap::grabWidget(scene);
    QImage img = pix.toImage(); */
    for (int i = 0; i < 1920*1080*2; i++) {
        pixels[i] = 0xff;
    }
    AirSend_add_frame_bgra(tricaster, pixels);
}
