import QtQuick

Item {
    property string name: "Vlad"
    anchors.horizontalCenter: parent.horizontalCenter
    width: board.width
    height: (parent.height - board.height) / 2

    function stopTimer() {
        elapsedTimer.stop()
        timeLeft.color = "#989795"
    }

    function runTimer() {
        elapsedTimer.start()
        timeLeft.color = "white"
    }

    Text {
        anchors.left: parent.left
        text: name
        anchors.verticalCenter: parent.verticalCenter
        anchors.leftMargin: 10
        color: "#b1b0af"
        font.pixelSize: 25
    }
    Rectangle {
        id: timeLeft
        width: 100
        height: parent.height - 15
        anchors.right: parent.right
        radius: 3
        anchors.verticalCenter: parent.verticalCenter
        color: "#989795"

        Text {
            text: getTime()
            property int timer: 10 * 60
            anchors.centerIn: parent
            color: "#2b2722"
            font.pixelSize: 25

            function getTime() {
                if (timer / 3600 < 1) {
                    var minutes = timer / 60;
                    var seconds = timer % 60;
                    if (seconds < 10)
                        seconds = "0" + seconds;

                    return parseInt(minutes) + ":" + seconds;
                } else {
                    var hours = parseInt(timer / 3600);
                    minutes = parseInt(timer / 60) % 60;
                    if (minutes < 10)
                        minutes = "0" + minutes;
                    seconds = timer % 60;
                    if (seconds < 10)
                        seconds = "0" + seconds;

                    return parseInt(hours) + ":" + minutes + ":" + seconds;
                }
            }

            Timer {
                id: elapsedTimer
                interval: 1000
                onTriggered: {
                    parent.timer = parent.timer - 1
                    restart()
                }
            }
        }
    }
}
