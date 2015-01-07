#include "MiamiAllAccessBasketball.h"
#include <QLCDNumber>
#include <QMainWindow>
int main(int argc, char *argv[]) {
    MiamiAllAccessBasketball a(argc, argv);
    return a.exec();
//    QApplication app(argc, argv);

//        QMainWindow *window = new QMainWindow();
//            window->setAttribute( Qt::WA_TranslucentBackground );
//            window->setWindowFlags(Qt::FramelessWindowHint);
//            //window->setFrameShape(QFrame::NoFrame);
//            window->setWindowTitle(QString::fromUtf8("QMainWindow Transparent Background"));
//            window->resize(800, 250);

//        QLCDNumber *number = new QLCDNumber();
//        number->setFixedSize(800, 245);
//        number->setDigitCount(12);
//        number->display(QTime::currentTime().toString(QString("hh:mm:ss.zzz")));


//        window->setCentralWidget(number);
//        window->show();

//        return app.exec();
}
