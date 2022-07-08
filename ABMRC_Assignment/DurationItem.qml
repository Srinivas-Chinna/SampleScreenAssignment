import QtQuick 2.0

Item {
    property string currentDuration: "currentDuration: " + appData.currentDuration

    property string cummulativeDuration: "cummulativeDuration: " + appData.cummuilativeDuration
    Text {
        id: currentDurationId
        text: currentDuration
    }
    Text {
        id: cummulativeDurationId
        anchors.top: currentDurationId.bottom
        text: cummulativeDuration
    }
}
