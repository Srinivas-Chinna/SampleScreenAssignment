import QtQuick 2.12
import QtQuick.Controls 2.0

Item {
    property int buttonHeight: 150
    property int buttonWidth: 200

    Rectangle {
        height: parentId.height - bar.height
        width: parentId.width
        color: "#0C090A"

        Row {

//            anchors.leftMargin: 20
            anchors.centerIn: parent
            spacing: 50

            Button {
                id: alphaButton

                height: buttonHeight
                width: buttonWidth
                property string buttonName: "Alpha"

                Text {
                    id: alphaText
                    anchors.centerIn: parent
                    text: alphaButton.buttonName
                }
                DurationItem {
                    id: alphadurationId
                    anchors.top: alphaText.bottom
                    visible: false
                }

                onPressed: {
                    console.log("alpha button clicked ", alphaButton.buttonName)
                    appData.buttonPressStart(alphaButton.buttonName)

                }
                onReleased: {
                    appData.updateDb(alphaButton.buttonName)
                    gamadurationId.visible = false;
                    betadurationId.visible = false
                    alphadurationId.visible = true
                }
            }


            Button {
                id: betaButton
                property string buttonName: "Beta"

                height: buttonHeight
                width: buttonWidth

                Text {
                    id: betaText
                    anchors.centerIn: parent
                    text: betaButton.buttonName
                }
                DurationItem {
                    id: betadurationId
                    anchors.top: betaText.bottom
                    visible: false
                }

                onPressed: {
                    console.log("alpha button clicked ", betaButton.buttonName)
                    appData.buttonPressStart(betaButton.buttonName)

                }
                onReleased: {
                    appData.updateDb(betaButton.buttonName)
                    alphadurationId.visible = false;
                    gamadurationId.visible = false;
                    betadurationId.visible = true
                }
            }

            Button {
                id: gamaButton

                property string buttonName: "Gama"

                height: buttonHeight
                width: buttonWidth

                Text {
                    id: gamaText
                    anchors.centerIn: parent
                    text: gamaButton.buttonName
                }
                DurationItem {
                    id: gamadurationId
                    anchors.top: gamaText.bottom
                    visible: false
                }

                onPressed: {
                    console.log("alpha button clicked ", gamaButton.buttonName)
                    appData.buttonPressStart(gamaButton.buttonName)

                }
                onReleased: {
                    appData.updateDb(gamaButton.buttonName)
                    alphadurationId.visible = false;
                    betadurationId.visible = false
                    gamadurationId.visible = true
                }
            }
        }
    }
}
