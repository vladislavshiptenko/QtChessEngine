import QtQuick
import QtQuick.Controls

Item {
    visible: false

    function declareCheck(newIsCheckVal) {
        isCheck.visible = newIsCheckVal;
    }

    ListView {
        id: movesList
        width: parent.width
        height: parent.height / 2
        anchors.top: parent.top
    }
    Item {
        id: gameOverMenu
        width: parent.width
        height: parent.height / 6
        anchors.top: movesList.bottom

        Text {
            id: isCheck
            text: "Check"
            color: "red"
            visible: false
        }
        Button {
            text: "Replay"
            visible: false
        }
    }
    ListView {
        width: parent.width
        height: parent.height / 3
    }
}
