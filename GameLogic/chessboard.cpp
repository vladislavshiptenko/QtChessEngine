#include "chessboard.h"
#include "Pieces/bishop.h"
#include "Pieces/castle.h"
#include "Pieces/king.h"
#include "Pieces/knight.h"
#include "Pieces/pawn.h"
#include "Pieces/queen.h"
#include <QRandomGenerator>

namespace qtchess {

ChessBoard::ChessBoard() {
    for (size_t i = 0; i < board_width; i++) {
        for (size_t j = 0; j < board_height; j++) {
            board[i][j] = nullptr;
        }
    }
    SetDefaultBoard();
}

QString ChessBoard::getImage(size_t i, size_t j) {
    if (board[i][j] == nullptr)
        return QString();
    return board[i][j]->GetImageSource();
}

void ChessBoard::SetDefaultBoard(QSharedPointer<Player> p1, QSharedPointer<Player> p2) {
    if (p1 == nullptr || p2 == nullptr) {
        board[0][0] = QSharedPointer<ChessPiece>(new Castle('a', '8', "castle_black"));
        board[0][1] = QSharedPointer<ChessPiece>(new Knight('b', '8', "knight_black"));
        board[0][2] = QSharedPointer<ChessPiece>(new Bishop('c', '8', "bishop_black"));
        board[0][3] = QSharedPointer<ChessPiece>(new Queen('d', '8', "queen_black"));
        board[0][4] = QSharedPointer<ChessPiece>(new King('e', '8', "king_black"));
        board[0][5] = QSharedPointer<ChessPiece>(new Bishop('f', '8', "bishop_black"));
        board[0][6] = QSharedPointer<ChessPiece>(new Knight('g', '8', "knight_black"));
        board[0][7] = QSharedPointer<ChessPiece>(new Castle('h', '8', "castle_black"));
        for (size_t i = 0; i < board_width; i++) {
            board[1][i] = QSharedPointer<ChessPiece>(new Pawn('a' + i, '7', "pawn_black"));
        }

        board[7][0] = QSharedPointer<ChessPiece>(new Castle('a', '1', "castle_white"));
        board[7][1] = QSharedPointer<ChessPiece>(new Knight('b', '1', "knight_white"));
        board[7][2] = QSharedPointer<ChessPiece>(new Bishop('c', '1', "bishop_white"));
        board[7][3] = QSharedPointer<ChessPiece>(new Queen('d', '1', "queen_white"));
        board[7][4] = QSharedPointer<ChessPiece>(new King('e', '1', "king_white"));
        board[7][5] = QSharedPointer<ChessPiece>(new Bishop('f', '1', "bishop_white"));
        board[7][6] = QSharedPointer<ChessPiece>(new Knight('g', '1', "knight_white"));
        board[7][7] = QSharedPointer<ChessPiece>(new Castle('h', '1', "castle_white"));
        for (size_t i = 0; i < board_width; i++) {
            board[6][i] = QSharedPointer<ChessPiece>(new Pawn('a' + i, '2', "pawn_white"));
        }
    }
    else {
        board[0][0] = QSharedPointer<ChessPiece>(new Castle('a', '8', p2));
        board[0][1] = QSharedPointer<ChessPiece>(new Knight('b', '8', p2));
        board[0][2] = QSharedPointer<ChessPiece>(new Bishop('c', '8', p2));
        board[0][3] = QSharedPointer<ChessPiece>(new Queen('d', '8', p2));
        board[0][4] = QSharedPointer<ChessPiece>(new King('e', '8', p2));
        board[0][5] = QSharedPointer<ChessPiece>(new Bishop('f', '8', p2));
        board[0][6] = QSharedPointer<ChessPiece>(new Knight('g', '8', p2));
        board[0][7] = QSharedPointer<ChessPiece>(new Castle('h', '8', p2));
        for (size_t i = 0; i < board_width; i++) {
            board[1][i] = QSharedPointer<ChessPiece>(new Pawn('a' + i, '7', p2));
        }

        board[7][0] = QSharedPointer<ChessPiece>(new Castle('a', '1', p1));
        board[7][1] = QSharedPointer<ChessPiece>(new Knight('b', '1', p1));
        board[7][2] = QSharedPointer<ChessPiece>(new Bishop('c', '1', p1));
        board[7][3] = QSharedPointer<ChessPiece>(new Queen('d', '1', p1));
        board[7][4] = QSharedPointer<ChessPiece>(new King('e', '1', p1));
        board[7][5] = QSharedPointer<ChessPiece>(new Bishop('f', '1', p1));
        board[7][6] = QSharedPointer<ChessPiece>(new Knight('g', '1', p1));
        board[7][7] = QSharedPointer<ChessPiece>(new Castle('h', '1', p1));
        for (size_t i = 0; i < board_width; i++) {
            board[6][i] = QSharedPointer<ChessPiece>(new Pawn('a' + i, '2', p1));
        }
    }
}

void ChessBoard::startGame(const QString& mode) {
    is_started = true;

    if (mode == "Offline")
        this->mode = Offline;
    else if (mode == "Online")
        this->mode = Online;
    else if (mode == "Computer")
        this->mode = Computer;
    else
        throw std::exception();

    bool is_white = QRandomGenerator::global()->generate() % 2;
    p1 = QSharedPointer<Player>(new Player(is_white, is_white, true));
    p2 = QSharedPointer<Player>(new Player(!is_white, !is_white, false));
    SetDefaultBoard(p1, p2);

    emit gameStarted();
}

}
