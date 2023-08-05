import QtQuick

Canvas {
    property var pieces: []
    property bool is_selected: false
    property int selected_x: 0
    property int selected_y: 0
    property int cell_count: 8

    function defaultInitialization() {
        for (var i = 0; i < cell_count; i++) {
            board.pieces.push([]);
            for (var j = 0; j < cell_count; j++) {
                board.pieces[i].push(boardLogic.getImage(i, j));
            }
        }
    }

    function changePosition() {
        for (var i = 0; i < cell_count; i++) {
            for (var j = 0; j < cell_count; j++) {
                board.pieces[i][j] = boardLogic.getImage(i, j);
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
        ctx.reset();
        ctx.drawImage("qrc:/Assets/chessboard.png", 0, 0, board.width, board.height);

        var cell_w = board.width / cell_count;
        var cell_h = board.height / cell_count;
        if (is_selected) {
            var selected_col = (selected_x / cell_w) - (selected_x / cell_w) % 1;
            var selected_row = (selected_y / cell_h) - (selected_y / cell_h) % 1;
            ctx.fillStyle = "steelblue";
            ctx.rect(selected_col * cell_w, selected_row * cell_h, cell_w + 1, cell_h + 1);
            ctx.fill();
        }

        for (var i = 0; i < cell_count; i++) {
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
            parent.is_selected = true;
            parent.selected_x = mouseX
            parent.selected_y = mouseY
            parent.requestPaint();
        }
    }
}
