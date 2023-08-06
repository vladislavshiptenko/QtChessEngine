import QtQuick

Canvas {
    property var pieces: []
    property var possible_moves: []
    property bool is_selected: false
    property real selected_x: 0
    property real selected_y: 0
    property real prev_selected_x: 0
    property real prev_selected_y: 0
    property int cell_count: 8
    property real cell_w: width / cell_count
    property real cell_h: height / cell_count

    function defaultInitialization() {
        for (var i = 0; i < cell_count; i++) {
            board.pieces.push([]);
            for (var j = 0; j < cell_count; j++) {
                board.pieces[i].push(boardLogic.getImage(j, i));
            }
        }
    }

    function changePosition() {
        for (var i = 0; i < cell_count; i++) {
            for (var j = 0; j < cell_count; j++) {
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
        ctx.reset();
        ctx.drawImage("qrc:/Assets/chessboard.png", 0, 0, board.width, board.height);

        if (is_selected) {
            ctx.fillStyle = "rgba(70, 130, 180, 0.5)";
            ctx.rect(selected_x * cell_w, selected_y * cell_h, cell_w + 1, cell_h + 1);
            ctx.fill();
            for (var i = 0; i < possible_moves.length; i++) {
                var posx = possible_moves[i][0];
                var posy = possible_moves[i][1];
                if (board.pieces[posy][posx] === "") {
                    ctx.beginPath();
                    ctx.arc(posx * cell_w + cell_w / 2, posy * cell_h + cell_h / 2, 15, 0, 2 * Math.PI);
                }
                else {
                    ctx.rect(posx * cell_w, posy * cell_h, cell_w + 1, cell_h + 1);
                }
                ctx.fill();
            }
        }

        for (i = 0; i < cell_count; i++) {
            for (var j = 0; j < cell_count; j++) {
                if (board.pieces[i][j] === "")
                    continue;
                ctx.drawImage(board.pieces[i][j], j * cell_w, i * cell_h, cell_w, cell_h);
            }
        }
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            selected_x = Math.floor(mouseX / cell_w);
            selected_y = Math.floor(mouseY / cell_h);
            if (boardLogic.isYourPiece(selected_x, selected_y)) {
                parent.possible_moves = boardLogic.validMoves(selected_x, selected_y)
                parent.is_selected = true;
            }
            else {
                if (parent.is_selected && isFind([selected_x, selected_y])) {
                    boardLogic.move(selected_x, selected_y);
                    pieces[selected_y][selected_x] = pieces[prev_selected_y][prev_selected_x]
                    pieces[prev_selected_y][prev_selected_x] = ""
                }

                parent.is_selected = false;
                parent.possible_moves = [];
            }

            prev_selected_x = selected_x
            prev_selected_y = selected_y
            parent.requestPaint();
        }
    }
}
