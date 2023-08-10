import QtQuick
import QtQuick.Controls

Item {
    visible: false

    function declareCheck(newIsCheckVal) {
        isCheck.visible = newIsCheckVal;
    }
    function declareStalemate() {
        gameOverText.visible = true;
        gameOverText.text = "Stalemate"
        gamePlayMenu.players[boardLogic.currentPlayerIndex].stopTimer();
    }
    function declareCheckmate() {
        gameOverText.visible = true;
        gameOverText.text = "Checkmate. " + gamePlayMenu.players[(boardLogic.currentPlayerIndex + 1) % 2].name + " wins!"
        gamePlayMenu.players[boardLogic.currentPlayerIndex].stopTimer();
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
            anchors.centerIn: parent
            font.pixelSize: 20
        }
        Text {
            id: gameOverText
            color: "red"
            visible: false
            anchors.centerIn: parent
            font.pixelSize: 20
        }
    }
    ListView {
        width: parent.width
        height: parent.height / 3
    }
}
