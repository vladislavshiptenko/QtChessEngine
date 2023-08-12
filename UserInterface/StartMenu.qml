import QtQuick
import QtQuick.Controls

Item {
    Button {
        id: playButton
        text: "Play"
        anchors.centerIn: parent
        onClicked: {
            parent.visible = false;
            gameDialog.open(mode.model[mode.currentIndex]);
        }
    }
    ComboBox {
        id: mode
        currentIndex: 0
        model: ["Offline", "Online", "Computer"]
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: playButton.top
        anchors.bottomMargin: 20
        width: 200
    }
}
