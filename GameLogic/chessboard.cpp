#include "chessboard.h"

namespace qtchess {

ChessBoard::ChessBoard() {
    for (size_t i = 0; i < board_width; i++) {
        for (size_t j = 0; j < board_height; j++) {
            board[i][j] = nullptr;
        }
    }
    DefaultBoard();
}

QString ChessBoard::getImage(size_t i, size_t j) {
    if (board[i][j] == nullptr)
        return QString();
    return board[i][j]->GetImageSource();
}

void ChessBoard::DefaultBoard() {
    board[0][0] = QSharedPointer<ChessPiece>(new Castle('a', '8', "qrc:/Assets/castle_black.png"));
    board[0][1] = QSharedPointer<ChessPiece>(new Knight('b', '8', "qrc:/Assets/knight_black.png"));
    board[0][2] = QSharedPointer<ChessPiece>(new Bishop('c', '8', "qrc:/Assets/bishop_black.png"));
    board[0][3] = QSharedPointer<ChessPiece>(new Queen('d', '8', "qrc:/Assets/queen_black.png"));
    board[0][4] = QSharedPointer<ChessPiece>(new King('e', '8', "qrc:/Assets/king_black.png"));
    board[0][5] = QSharedPointer<ChessPiece>(new Bishop('f', '8', "qrc:/Assets/bishop_black.png"));
    board[0][6] = QSharedPointer<ChessPiece>(new Knight('g', '8', "qrc:/Assets/knight_black.png"));
    board[0][7] = QSharedPointer<ChessPiece>(new Castle('h', '8', "qrc:/Assets/castle_black.png"));
    for (size_t i = 0; i < board_width; i++) {
        board[1][i] = QSharedPointer<ChessPiece>(new Pawn('a' + i, '7', "qrc:/Assets/pawn_black.png"));
    }

    board[7][0] = QSharedPointer<ChessPiece>(new Castle('a', '1', "qrc:/Assets/castle_white.png"));
    board[7][1] = QSharedPointer<ChessPiece>(new Knight('b', '1', "qrc:/Assets/knight_white.png"));
    board[7][2] = QSharedPointer<ChessPiece>(new Bishop('c', '1', "qrc:/Assets/bishop_white.png"));
    board[7][3] = QSharedPointer<ChessPiece>(new Queen('d', '1', "qrc:/Assets/queen_white.png"));
    board[7][4] = QSharedPointer<ChessPiece>(new King('e', '1', "qrc:/Assets/king_white.png"));
    board[7][5] = QSharedPointer<ChessPiece>(new Bishop('f', '1', "qrc:/Assets/bishop_white.png"));
    board[7][6] = QSharedPointer<ChessPiece>(new Knight('g', '1', "qrc:/Assets/knight_white.png"));
    board[7][7] = QSharedPointer<ChessPiece>(new Castle('h', '1', "qrc:/Assets/castle_white.png"));
    for (size_t i = 0; i < board_width; i++) {
        board[6][i] = QSharedPointer<ChessPiece>(new Pawn('a' + i, '2', "qrc:/Assets/pawn_white.png"));
    }
}

}
