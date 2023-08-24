import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Dialog {
    title: "New game"
    property string mode: ""

    function open(newMode) {
        visible = true;
        if (newMode === "Online") {
            onlineFields.visible = true;
        } else {
            onlineFields.visible = false;
        }
        mode = newMode;    
    }
    x: Math.round((parent.width - width) / 2)
    y: Math.round((parent.height - height) / 2)
    visible: false
    standardButtons: Dialog.Ok | Dialog.Cancel
    modal: true

    ColumnLayout {
        id: onlineFields
        visible: false

        TextField {
            id: ipField
            placeholderText: "Enter IP"
        }
        TextField {
            id: portField
            placeholderText: "Enter port"
        }
    }

    onAccepted: {
        boardLogic.startGame(mode);
    }
    
    onRejected: {
        startMenu.visible = true;
    }
}
