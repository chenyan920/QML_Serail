import QtQuick 2.12
import QtQuick.Controls 1.4
Item{
    property alias menuBar: myMenuBar

    Component.onCompleted: {
         var serialName = serial.getSerialName()
         for(var i=0;i<serialName.length;++i)
             serialMenu.addItem(serialName[i]).action = cutAction
    }

    Action {
        id: cutAction;
        onTriggered: {
            var result = serial.connectPort(source.text)
            console.log(result)
        }
    }
    MenuBar {
        id:myMenuBar
        Menu {
            title: qsTr("工具")
            Button{
                menu: Menu{
                    id:serialMenu
                    MenuItem{text: "nothing";action: cutAction;checkable: true}
                    title: qsTr("端口:")
                }
            }
        }
    }
}

