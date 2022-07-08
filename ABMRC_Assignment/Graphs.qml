import QtQuick 2.0

Item {
    Rectangle {
        height: parentId.height - bar.height
        width: parentId.width
        color: "#000000"

        /* ChartView {
            id: chartView
            animationOptions: ChartView.NoAnimation
            theme: ChartView.ChartThemeDark
            property bool openGL: true
            property bool openGLSupported: true
            onOpenGLChanged: {
                if (openGLSupported) {
                    series("signal 1").useOpenGL = openGL;
                    series("signal 2").useOpenGL = openGL;
                }
            }
            Component.onCompleted: {
                if (!series("signal 1").useOpenGL) {
                    openGLSupported = false
                    openGL = false
                }
            }

            ValueAxis {
                id: axisY1
                min: -1
                max: 4
            }

            ValueAxis {
                id: axisY2
                min: -10
                max: 5
            }

            ValueAxis {
                id: axisX
                min: 0
                max: 10
            }

            LineSeries {
                id: lineSeries1
                name: "signal 1"
                axisX: axisX
                axisY: axisY1
                useOpenGL: chartView.openGL
            }
            LineSeries {
                id: lineSeries2
                name: "signal 2"
                axisX: axisX
                axisYRight: axisY2
                useOpenGL: chartView.openGL
            }
        } */
    }
}
