#include "cserial.h"
#include <QDebug>
#include <QSerialPort>
#include <QSerialPortInfo>

ASerial::ASerial(){
    initPort();

    connect(sp,SIGNAL(readyRead()),this,SLOT(receiveData()));
}


ASerial::~ASerial(){ //析构时应该释放
    if(!sp->isOpen())
        sp->close();
    delete sp;
}

void ASerial::printInfo(){
    qDebug()<<"hello world";
}

bool ASerial::connectPort(QString text){
    sp->setPortName(text);//暂时直接打开已知串口，待进一步完善UI功能。
    bool result = sp->open(QIODevice::ReadWrite);
    return result;
}

void ASerial::initPort(){
    sp->setParity(QSerialPort::NoParity);
    sp->setDataBits(QSerialPort::Data8);
    sp->setStopBits(QSerialPort::OneStop);
    sp->setBaudRate(QSerialPort::Baud9600);
}

void ASerial::receiveData(){
    QByteArray info = sp->readAll();
    emit readyReceive(QString(info));//发射UI层可识别信号
}

void ASerial::sendData(QString text){
    QByteArray array=text.toLatin1();
    sp->write(array);
}

QStringList ASerial::getSerialName(){
    QStringList m_serialPortName;
    foreach(const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
    {
        m_serialPortName << info.portName();
        qDebug()<<"serialPortName:"<<info.portName();
    }
    return m_serialPortName;
}
