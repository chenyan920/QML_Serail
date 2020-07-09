import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    Rectangle{
        id:root
        anchors.fill: parent
        Component.onCompleted: {
            root.enabled = true
            root.forceActiveFocus()
        }
        Keys.onPressed:{
            switch(event.key){
            case Qt.Key_1:serial.sendData('1')
            }
        }
    }
}
