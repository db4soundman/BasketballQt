#include "TricasterHandler.h"
#include "AirSend_api.h"
#include <QHostAddress>

TricasterHandler::TricasterHandler(QGraphicsView *view, QColor pAlphaBlack) : alpha(QColor(0,0,0,0)),
    alphaBlack(pAlphaBlack)
{
    screen = view;
    tricaster = AirSend_Create(1920, 1080,3000,1001,false, 16.0/9.0, false, 0,0);
    // Connect
    QHostAddress ip("10.44.0.171");
    unsigned int blah = ip.toIPv4Address();
    AirSend_request_connection(tricaster, blah, 7000);
    pixels = new BYTE[1920*1080];
}

void TricasterHandler::run()
{
    tricaster = AirSend_Create(1920, 1080,3000,1001,false, 16.0/9.0, false, 0,0);
    // Connect
    QHostAddress ip("10.44.0.171");
    unsigned int blah = ip.toIPv4Address();
    AirSend_request_connection(tricaster, blah, 7000);
   /* QPixmap pix = QPixmap::grabWidget(scene);
    QImage img = pix.toImage(); */
    for (int i = 0; i < 1; i++) {
        ::memset( pixels, 0xffffffff, 1920*1080);
    }
    AirSend_add_frame_bgra(tricaster, pixels);
    //AirSend_Destroy( tricaster );
}
