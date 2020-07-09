#include "cserial.h"
#include <QDebug>
#include <QSerialPort>
#include <QSerialPortInfo>

ASerial::ASerial(){
   initPort();

   serialPort->setPortName("COM5");//暂时直接打开已知串口，待进一步完善UI功能。
   serialPort->open(QIODevice::ReadWrite);
   connect(serialPort,SIGNAL(readyRead()),this,SLOT(receiveData()));
}

ASerial::~ASerial(){ //析构时应该释放
    if(!serialPort->isOpen())
        serialPort->close();
    delete serialPort;
}

void ASerial::printInfo(){
    qDebug()<<"hello world";
}

void ASerial::initPort(){
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setBaudRate(QSerialPort::Baud9600);
}

void ASerial::receiveData(){
    QByteArray info = serialPort->readAll();
    emit readyReceive(QString(info));//发射UI层可识别信号
}

void ASerial::sendData(QString text){
    QByteArray array=text.toLatin1();
    serialPort->write(array);
}
