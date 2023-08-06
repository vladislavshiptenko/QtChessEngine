import QtQuick
import QtQuick.Controls

Item {
    visible: false

    function declareCheck() {
        isCheck.visible = true;
    }

    ListView {

    }
    Item {
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

    }
}
