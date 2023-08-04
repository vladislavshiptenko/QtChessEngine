import QtQuick
import QtQuick.Window
import QtQuick.Layouts
import QtQuick.Controls
import ChessEngine

Window {
    minimumWidth: 1280
    minimumHeight: 720
    visible: true
    title: qsTr("QtChessEngine")

    ChessBoard {
        id: logicBoard
    }

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

            Canvas {
                id: board
                width: Math.min(parent.width - 100, parent.height - 100)
                height: width
                anchors.centerIn: parent

                property var pieces: []
                property int board_width: 8
                property int board_height: 8

                function defaultInitialization() {
                    for (var i = 0; i < board_width; i++) {
                        board.pieces.push([]);
                        for (var j = 0; j < board_height; j++) {
                            board.pieces[i].push(logicBoard.getImage(i, j));
                        }
                    }
                }

                Component.onCompleted: {
                    defaultInitialization()
                    loadImage("qrc:/Assets/chessboard.png")
                    loadImage("qrc:/Assets/pawn_white.png")
                    loadImage("qrc:/Assets/bishop_white.png")
                    loadImage("qrc:/Assets/castle_white.png")
                    loadImage("qrc:/Assets/king_white.png")
                    loadImage("qrc:/Assets/knight_white.png")
                    loadImage("qrc:/Assets/queen_black.png")
                    loadImage("qrc:/Assets/pawn_black.png")
                    loadImage("qrc:/Assets/bishop_black.png")
                    loadImage("qrc:/Assets/castle_black.png")
                    loadImage("qrc:/Assets/king_black.png")
                    loadImage("qrc:/Assets/knight_black.png")
                    loadImage("qrc:/Assets/queen_black.png")
                }

                onPaint: {
                    var ctx = getContext("2d");
                    ctx.drawImage("qrc:/Assets/chessboard.png", 0, 0, board.width, board.height);

                    var cell_w = board.width / board_width;
                    var cell_y = board.height / board_width;
                    for (var i = 0; i < board_width; i++) {
                        for (var j = 0; j < board_height; j++) {
                            if (board.pieces[i][j] === "")
                                continue;
                            ctx.drawImage(board.pieces[i][j], j * cell_w, i * cell_y, cell_w, cell_y);
                        }
                    }
                }
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
