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

public:
    Q_INVOKABLE void printInfo();
    Q_INVOKABLE void initPort();

    Q_INVOKABLE void sendData(QString text);
    Q_INVOKABLE bool connectPort(QString text);
    Q_INVOKABLE QStringList getSerialName();

private:
     QSerialPort *sp = new QSerialPort;

private slots:
    void receiveData();

signals:
    void readyReceive(QString string);

};

#endif // CSERIAL_H
