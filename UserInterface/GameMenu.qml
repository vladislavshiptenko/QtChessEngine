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
    
    Rectangle {
        id: movesListWrapper
        color: rightMenu.color
        width: parent.width
        height: parent.height / 2
        anchors.top: parent.top

        ListView {
            id: movesList
            anchors.fill: parent
        }
    }
    Rectangle {
        id: gameOverMenuWrapper
        width: parent.width
        height: parent.height / 6
        anchors.top: movesListWrapper.bottom
        color: "#272522"

        Item {
            id: gameOverMenu
            anchors.fill: parent
            
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
    }
    Rectangle {
        anchors.bottom: parent.bottom
        color: rightMenu.color
        width: parent.width
        height: parent.height / 3

        ListView {
            height: parent.height - messageTextField.height
        }
        TextField {
            id: messageTextField
            width: parent.width
            anchors.bottom: parent.bottom
            placeholderText: "Enter your message"
        }
    }
}
