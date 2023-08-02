import QtQuick
import QtQuick.Window
import QtQuick.Layouts
import QtQuick.Controls

Window {
    minimumWidth: 1280
    minimumHeight: 720
    visible: true
    title: qsTr("QtChessEngine")

    GridLayout {
        id: grid
        columns: 3
        columnSpacing: 0
        anchors.fill: parent

        Rectangle {
            id: settingsMenu

            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.column: 0
            Layout.minimumWidth: 100
            Layout.preferredWidth: 200
            Layout.maximumWidth: 200

            color: "#272522"

            Image {
                id: icon
                width: 100
                height: 100
                source: "qrc:/Assets/icon.png"
                anchors.top: parent.top
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.topMargin: 20
            }
            ListView {
                width: parent.width
                height: 75
                anchors.top: icon.bottom
                anchors.topMargin: 30
                interactive: false
                spacing: 3
                model: ChessMode {}
                delegate: Button {
                    text: buttonText
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }
            ListView {
                width: parent.width
                height: 100
                anchors.bottom: parent.bottom
                interactive: false
                spacing: 3
                model: Settings {}
                delegate: Button {
                    text: buttonText
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }
        }
        Rectangle {
            Layout.column: 1
            Layout.fillHeight: true
            Layout.fillWidth: true

            color: "#312e2b"

            Image {
                id: board
                width: Math.min(parent.width - 100, parent.height - 100)
                height: width
                source: "qrc:/Assets/chessboard.png"
                anchors.centerIn: parent
            }
        }
        Rectangle {
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.column: 2
            Layout.minimumWidth: 200
            Layout.preferredWidth: 300
            Layout.maximumWidth: 300
            color: "#272522"
            Button {
                id: playButton
                text: "Play"
                anchors.centerIn: parent
            }
            ComboBox {
                currentIndex: 0
                model: ["Bullet", "Blitz", "Rapid", "Classical"]
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.bottom: playButton.top
                anchors.bottomMargin: 20
                width: 200
            }
        }
    }
}
