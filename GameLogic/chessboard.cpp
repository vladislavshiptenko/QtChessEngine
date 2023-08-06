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
    for (size_t i = 0; i < m_cell_count; i++) {
        for (size_t j = 0; j < m_cell_count; j++) {
            board[i][j] = nullptr;
        }
    }
    SetDefaultBoard();
}

QString ChessBoard::getImage(size_t posx, size_t posy) {
    if (board[posy][posx] == nullptr)
        return QString();
    return board[posy][posx]->GetImageSource();
}

void ChessBoard::SetDefaultBoard(QSharedPointer<Player> p1, QSharedPointer<Player> p2) {
    if (p1 == nullptr || p2 == nullptr) {
        board[0][0] = QSharedPointer<ChessPiece>(new Castle("castle_black"));
        board[0][1] = QSharedPointer<ChessPiece>(new Knight("knight_black"));
        board[0][2] = QSharedPointer<ChessPiece>(new Bishop("bishop_black"));
        board[0][3] = QSharedPointer<ChessPiece>(new Queen("queen_black"));
        board[0][4] = QSharedPointer<ChessPiece>(new King("king_black"));
        board[0][5] = QSharedPointer<ChessPiece>(new Bishop("bishop_black"));
        board[0][6] = QSharedPointer<ChessPiece>(new Knight("knight_black"));
        board[0][7] = QSharedPointer<ChessPiece>(new Castle("castle_black"));
        for (size_t i = 0; i < m_cell_count; i++) {
            board[1][i] = QSharedPointer<ChessPiece>(new Pawn("pawn_black"));
        }

        board[7][0] = QSharedPointer<ChessPiece>(new Castle("castle_white"));
        board[7][1] = QSharedPointer<ChessPiece>(new Knight("knight_white"));
        board[7][2] = QSharedPointer<ChessPiece>(new Bishop("bishop_white"));
        board[7][3] = QSharedPointer<ChessPiece>(new Queen("queen_white"));
        board[7][4] = QSharedPointer<ChessPiece>(new King("king_white"));
        board[7][5] = QSharedPointer<ChessPiece>(new Bishop("bishop_white"));
        board[7][6] = QSharedPointer<ChessPiece>(new Knight("knight_white"));
        board[7][7] = QSharedPointer<ChessPiece>(new Castle("castle_white"));
        for (size_t i = 0; i < m_cell_count; i++) {
            board[6][i] = QSharedPointer<ChessPiece>(new Pawn("pawn_white"));
        }
    }
    else {
        board[0][0] = QSharedPointer<ChessPiece>(new Castle(p2));
        board[0][1] = QSharedPointer<ChessPiece>(new Knight(p2));
        board[0][2] = QSharedPointer<ChessPiece>(new Bishop(p2));
        board[0][3] = QSharedPointer<ChessPiece>(new Queen(p2));
        board[0][4] = QSharedPointer<ChessPiece>(new King(p2));
        board[0][5] = QSharedPointer<ChessPiece>(new Bishop(p2));
        board[0][6] = QSharedPointer<ChessPiece>(new Knight(p2));
        board[0][7] = QSharedPointer<ChessPiece>(new Castle(p2));
        for (size_t i = 0; i < m_cell_count; i++) {
            board[1][i] = QSharedPointer<ChessPiece>(new Pawn(p2));
        }

        board[7][0] = QSharedPointer<ChessPiece>(new Castle(p1));
        board[7][1] = QSharedPointer<ChessPiece>(new Knight(p1));
        board[7][2] = QSharedPointer<ChessPiece>(new Bishop(p1));
        board[7][3] = QSharedPointer<ChessPiece>(new Queen(p1));
        board[7][4] = QSharedPointer<ChessPiece>(new King(p1));
        board[7][5] = QSharedPointer<ChessPiece>(new Bishop(p1));
        board[7][6] = QSharedPointer<ChessPiece>(new Knight(p1));
        board[7][7] = QSharedPointer<ChessPiece>(new Castle(p1));
        for (size_t i = 0; i < m_cell_count; i++) {
            board[6][i] = QSharedPointer<ChessPiece>(new Pawn(p1));
        }
    }
}

void ChessBoard::startGame(const QString& mode) {
    started = true;

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
    connect(p1.get(), &Player::MadeMove, p2.get(), &Player::YourTurn);
    connect(p2.get(), &Player::MadeMove, p1.get(), &Player::YourTurn);

    emit gameStarted();
}

bool ChessBoard::isYourPiece(size_t posx, size_t posy) {
    if (board[posy][posx] == nullptr)
        return false;
    return board[posy][posx]->GetPlayerInfo() != nullptr && board[posy][posx]->GetPlayerInfo()->IsYourTurn();
}

QList<QList<int>> ChessBoard::validMoves() {
    if (!board[m_selected_y][m_selected_x]->GetPlayerInfo()->IsYourTurn())
        return QList<QList<int>>();

    QList<QList<int>> moves = board[m_selected_y][m_selected_x]->Moves(board, m_selected_x, m_selected_y);
    QList<QList<int>> valid_moves;

    QSharedPointer<ChessPiece> piece_on_pos = nullptr;
    for (const QList<int>& move : moves) {
        int move_x = move[0];
        int move_y = move[1];
        piece_on_pos = board[move_y][move_x];
        board[move_y][move_x] = board[m_selected_y][m_selected_x];
        board[m_selected_y][m_selected_x] = nullptr;

        if ((p1->IsYourTurn() && !IsCheck(p1)) || (p2->IsYourTurn() && !IsCheck(p2))) {
            valid_moves.push_back(move);
        }

        board[m_selected_y][m_selected_x] = board[move_y][move_x];
        board[move_y][move_x] = piece_on_pos;
    }

    return valid_moves;
}

void ChessBoard::move() {
    if (p1->IsYourTurn()) {
        p1->Move();
    }
    else {
        p2->Move();
    }

    board[m_selected_y][m_selected_x] = board[m_selected_piece_y][m_selected_piece_x];
    board[m_selected_piece_y][m_selected_piece_x] = nullptr;
    if (dynamic_cast<Pawn*>(board[m_selected_y][m_selected_x].get())) {
        dynamic_cast<Pawn*>(board[m_selected_y][m_selected_x].get())->SetMadeMove();
    }

    if (IsCheck(p1) || IsCheck(p2)) {
        emit check();
    }
}

bool ChessBoard::IsCheck(QSharedPointer<Player> p) const {
    for (size_t i = 0; i < m_cell_count; i++) {
        for (size_t j = 0; j < m_cell_count; j++) {
            if (board[i][j] == nullptr || (board[i][j] != nullptr && board[i][j]->GetPlayerInfo() == p))
                continue;

            QList<QList<int>> piece_move = board[i][j]->Moves(board, j, i);
            for (const QList<int>& move : piece_move) {
                int posx = move[0];
                int posy = move[1];

                if (dynamic_cast<King*>(board[posy][posx].get())) {
                    return true;
                }
            }
        }
    }

    return false;
}

}
