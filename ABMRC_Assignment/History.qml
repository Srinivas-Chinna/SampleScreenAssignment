import QtQuick 2.0

Item {
    property int textWidth: 110

    Rectangle {
        height: parentId.height - bar.height
        width: parentId.width
        color: "#3B3131"

        ListView {
//            height: 300
//            width: 600
            anchors.fill: parent

            model: appData.historylistmodel
            clip: true
            snapMode: ListView.SnapToItem
            header: Row {
                    spacing: 10
                    height: 40
                    width: parent.width

                    Text {
                        id: boxName
                        width: textWidth
                        text: qsTr("BoxName")
                        color: "white"
                    }
                    Text {
                        id: startTime
                        width: textWidth
                        color: "white"
                        text: qsTr("StartTimeEpoc")
                    }
                    Text {
                        id: endTime
                        color: "white"
                        width: textWidth
                        text: qsTr("EndTimeEpoc")
                    }
                    Text {
                        id: currentDuration
                        color: "white"
                        width: textWidth
                        text: qsTr("curDuration")
                    }
                    Text {
                        id: cumuDuration
                        width: textWidth
                        color: "white"
                        text: qsTr("cummuDuration")
                    }
                }

            delegate: Rectangle {
                border.width: 2
                height: 50
                width: parent.width
                color: "#454545"
                Row {
                    spacing: 10
                    Text {
                        id: textId
                        color: "#CECECE"
                        width: textWidth
                        text: model.boxName
                    }
                    Text {
                        id: textId2
                        color: "#CECECE"
                        width: textWidth
                        text: model.startTime
                    }
                    Text {
                        id: textId3
                        color: "#CECECE"
                        width: textWidth
                        text: model.endTime
                    }
                    Text {
                        id: textId4
                        color: "#CECECE"
                        width: textWidth
                        text: model.currentDuration
                    }
                    Text {
                        id: textId5
                        color: "#CECECE"
                        width: textWidth
                        text: model.cummulativeDuration
                    }
                }
            }
        }

        ListModel {
            id: modelId
            ListElement {
                name: "chinna"
            }
            ListElement {
                name: "vasu"
            }
            ListElement {
                name: "vasu"
            }
            ListElement {
                name: "chinna"
            }
            ListElement {
                name: "vasu"
            }
            ListElement {
                name: "chinna"
            }
            ListElement {
                name: "gayathri"
            }
        }
    }
}
