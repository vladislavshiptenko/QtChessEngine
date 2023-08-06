import QtQuick

Canvas {
    property var pieces: []
    property var possible_moves: []
    property real cell_length: width / boardLogic.cell_count

    function defaultInitialization() {
        for (var i = 0; i < boardLogic.cell_count; i++) {
            board.pieces.push([]);
            for (var j = 0; j < boardLogic.cell_count; j++) {
                board.pieces[i].push(boardLogic.getImage(j, i));
            }
        }
    }

    function changePosition() {
        for (var i = 0; i < boardLogic.cell_count; i++) {
            for (var j = 0; j < boardLogic.cell_count; j++) {
                board.pieces[i][j] = boardLogic.getImage(j, i);
            }
        }
    }

    function isFind(move) {
        for (var i = 0; i < possible_moves.length; i++) {
            if (possible_moves[i][0] - 0 % 1 === move[0] - 0 % 1 && possible_moves[i][1] - 0 % 1 === move[1] - 0 % 1)
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
        ctx.drawImage(boardLogic.chessboard_image, 0, 0, board.width, board.height);

        if (boardLogic.selected) {
            ctx.fillStyle = "rgba(70, 130, 180, 0.5)";
            ctx.rect(boardLogic.selected_x * cell_length, boardLogic.selected_y * cell_length, cell_length + 1, cell_length + 1);
            ctx.fill();
            for (var i = 0; i < possible_moves.length; i++) {
                var posx = possible_moves[i][0];
                var posy = possible_moves[i][1];
                if (board.pieces[posy][posx] === "") {
                    ctx.beginPath();
                    ctx.arc(posx * cell_length + cell_length / 2, posy * cell_length + cell_length / 2, 15, 0, 2 * Math.PI);
                }
                else {
                    ctx.rect(posx * cell_length, posy * cell_length, cell_length + 1, cell_length + 1);
                }
                ctx.fill();
            }
        }

        for (i = 0; i < boardLogic.cell_count; i++) {
            for (var j = 0; j < boardLogic.cell_count; j++) {
                if (board.pieces[i][j] === "")
                    continue;
                ctx.drawImage(board.pieces[i][j], j * cell_length, i * cell_length, cell_length, cell_length);
            }
        }
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            boardLogic.selected_x = Math.floor(mouseX / cell_length);
            boardLogic.selected_y = Math.floor(mouseY / cell_length);
            if (boardLogic.isYourPiece(boardLogic.selected_x, boardLogic.selected_y)) {
                parent.possible_moves = boardLogic.validMoves();
                boardLogic.selected = true;
            }
            else {
                if (boardLogic.selected && isFind([boardLogic.selected_x, boardLogic.selected_y])) {
                    boardLogic.move();
                    pieces[boardLogic.selected_y][boardLogic.selected_x] = pieces[boardLogic.selected_piece_y][boardLogic.selected_piece_x]
                    pieces[boardLogic.selected_piece_y][boardLogic.selected_piece_x] = ""
                }

                boardLogic.selected = false;
                parent.possible_moves = [];
            }

            boardLogic.selected_piece_x = boardLogic.selected_x
            boardLogic.selected_piece_y = boardLogic.selected_y
            parent.requestPaint();
        }
    }
}
