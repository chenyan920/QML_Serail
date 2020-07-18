import QtQuick 2.12
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1
import QtQuick.Window 2.2

ApplicationWindow {
    id:rootwin
    height: 480
    width: 640
    title: qsTr("串口小助手")
    visible: true
    CMenuBar{id:myMenuBar}
    Rectangle{
        anchors.fill: parent
        enabled: true
        focus: true
        Keys.onPressed: {
            switch(event.key){
            case Qt.Key_1: console.log(1);serial.sendData('a');break
            case Qt.Key_2: console.log(2);serial.sendData('b');break
            default:break;
            }
        }
    }
    menuBar: myMenuBar.menuBar
}


