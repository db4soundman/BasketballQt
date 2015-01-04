#ifndef SERIALCONSOLE_H
#define SERIALCONSOLE_H

#include <QtCore/QtGlobal>

#include <QMainWindow>

#include <QtSerialPort/QSerialPort>

QT_BEGIN_NAMESPACE

namespace Ui {
class SerialConsole;
}

QT_END_NAMESPACE

class Console;
class SettingsDialog;

class SerialConsole : public QMainWindow
{
    Q_OBJECT

public:
    explicit SerialConsole(QWidget *parent = 0);
    ~SerialConsole();

private slots:
    void openSerialPort();
    void closeSerialPort();
    void about();
    void writeData(const QByteArray &data);
    void readData();

    void handleError(QSerialPort::SerialPortError error);

private:
    void initActionsConnections();

private:
    Ui::SerialConsole *ui;
    Console *console;
    SettingsDialog *settings;
    QSerialPort *serial;
};

#endif // MAINWINDOW_H
