import QtQuick

Item {
    property string name: "Vlad"
    anchors.horizontalCenter: parent.horizontalCenter
    width: board.width
    height: (parent.height - board.height) / 2

    Text {
        anchors.left: parent.left
        text: name
        anchors.verticalCenter: parent.verticalCenter
        anchors.leftMargin: 10
        color: "#b1b0af"
        font.pixelSize: 25
    }
    Rectangle {
        width: 100
        height: parent.height - 15
        anchors.right: parent.right
        radius: 3
        anchors.verticalCenter: parent.verticalCenter
        color: "#989795"

        Text {
            text: parseInt(timer / 60) + ":" + timer % 60
            property int timer: 10 * 60
            anchors.centerIn: parent
            color: "#2b2722"
            font.pixelSize: 25

            Timer {
                id: elapsedTimer
                interval: 1000
                onTriggered: {
                    parent.timer = parent.timer - 1
                    restart()
                }
            }

            Component.onCompleted: {
                elapsedTimer.start()
            }
        }
    }
}
