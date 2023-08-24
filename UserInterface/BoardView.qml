import QtQuick

Canvas {
    property var pieces: []
    property var possibleMoves: []
    property real cellLength: width / boardLogic.cellCount

    function defaultInitialization() {
        for (var i = 0; i < boardLogic.cellCount; i++) {
            board.pieces.push([]);
            for (var j = 0; j < boardLogic.cellCount; j++) {
                board.pieces[i].push(boardLogic.getImage(j, i));
            }
        }
    }

    function changePosition() {
        for (var i = 0; i < boardLogic.cellCount; i++) {
            for (var j = 0; j < boardLogic.cellCount; j++) {
                board.pieces[i][j] = boardLogic.getImage(j, i);
            }
        }
    }

    function isFind(move) {
        for (var i = 0; i < possibleMoves.length; i++) {
            if (possibleMoves[i][0] - 0 % 1 === move[0] - 0 % 1 && possibleMoves[i][1] - 0 % 1 === move[1] - 0 % 1)
                return true;
        }
        return false;
    }

    Component.onCompleted: {
        defaultInitialization()
        loadImage("qrc:/Assets/chessboard_white_bottom.png")
        loadImage("qrc:/Assets/chessboard_black_bottom.png")
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
        ctx.reset();
        ctx.drawImage(boardLogic.chessBoardImage, 0, 0, board.width, board.height);

        if (boardLogic.selected) {
            ctx.fillStyle = "rgba(70, 130, 180, 0.5)";
            ctx.fillRect(boardLogic.selectedX * cellLength, boardLogic.selectedY * cellLength, cellLength + 1, cellLength + 1);
            for (var i = 0; i < possibleMoves.length; i++) {
                var posX = possibleMoves[i][0];
                var posY = possibleMoves[i][1];
                if (board.pieces[posY][posX] === "") {
                    ctx.beginPath();
                    ctx.arc(posX * cellLength + cellLength / 2, posY * cellLength + cellLength / 2, 15, 0, 2 * Math.PI);
                }
                else {
                    ctx.rect(posX * cellLength, posY * cellLength, cellLength + 1, cellLength + 1);
                }
                ctx.fill();
            }
        }

        if (boardLogic.check) {
            ctx.fillStyle = "rgba(255, 0, 0, 0.5)";
            ctx.fillRect(boardLogic.checkPosX * cellLength, boardLogic.checkPosY * cellLength, cellLength + 1, cellLength + 1);
        }

        for (i = 0; i < boardLogic.cellCount; i++) {
            for (var j = 0; j < boardLogic.cellCount; j++) {
                if (board.pieces[i][j] === "")
                    continue;
                ctx.drawImage(board.pieces[i][j], j * cellLength, i * cellLength, cellLength, cellLength);
            }
        }
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            boardLogic.selectedX = Math.floor(mouseX / cellLength);
            boardLogic.selectedY = Math.floor(mouseY / cellLength);
            if (boardLogic.isYourPiece(boardLogic.selectedX, boardLogic.selectedY)) {
                parent.possibleMoves = boardLogic.validMoves(boardLogic.selectedX, boardLogic.selectedY);
                boardLogic.selected = true;
            }
            else {
                if (boardLogic.selected && isFind([boardLogic.selectedX, boardLogic.selectedY])) {
                    boardLogic.move();
                }

                boardLogic.selected = false;
                parent.possibleMoves = [];
            }

            boardLogic.selectedPieceX = boardLogic.selectedX
            boardLogic.selectedPieceY = boardLogic.selectedY
            parent.requestPaint();
        }
    }
}
