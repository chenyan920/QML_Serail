#ifndef CSERIAL_H
#define CSERIAL_H

#include <QDebug>
#include <QSerialPort>
#include <QSerialPortInfo>

class ASerial: public QObject{
     Q_OBJECT

public:
    explicit ASerial();
    ~ASerial();

    void printInfo();
    void initPort();

private:
    QSerialPort *serialPort;

private slots:
    void receiveData();

signals:
    void readyReceive(QString string);

};

#endif // CSERIAL_H
