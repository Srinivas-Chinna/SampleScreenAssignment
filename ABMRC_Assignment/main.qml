import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.12

Rectangle {
    id: parentId
    width: 800
    height: 350
    visible: true
//    title: qsTr("ABMRC Assignment")

    TabBar {
        id: bar
        width: parent.width

//        currentIndex: 2 //represents Graphs tab

        TabButton {
            text: qsTr("Activity")

        }
        TabButton {
            text: qsTr("History")
        }
        TabButton {
            text: qsTr("Graphs")
        }
    }

    StackLayout {
        anchors.top: bar.bottom

        width: parent.width
        currentIndex: bar.currentIndex

        ActivityTabInfo {
            id: alphaTab
        }

        History {
            id: historyTab
        }

        Graphs {
            id: graphTab
        }
    }
}
