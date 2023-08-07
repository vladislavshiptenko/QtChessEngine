#include "chessboard.h"
#include "Pieces/bishop.h"
#include "Pieces/castle.h"
#include "Pieces/king.h"
#include "Pieces/knight.h"
#include "Pieces/pawn.h"
#include "Pieces/queen.h"
#include <QRandomGenerator>

namespace qtchess {

ChessBoard::ChessBoard()
{
    for (size_t i = 0; i < mCellCount; i++) {
        for (size_t j = 0; j < mCellCount; j++) {
            board[i][j] = nullptr;
        }
    }
    setDefaultBoard();
}

QString ChessBoard::getImage(size_t posX, size_t posY)
{
    if (board[posY][posX] == nullptr)
        return QString();
    return board[posY][posX]->getImageSource();
}

void ChessBoard::setDefaultBoard(QSharedPointer<Player> p1, QSharedPointer<Player> p2)
{
    if (p1 == nullptr || p2 == nullptr) {
        board[0][0] = QSharedPointer<ChessPiece>(new Castle("castle_black"));
        board[0][1] = QSharedPointer<ChessPiece>(new Knight("knight_black"));
        board[0][2] = QSharedPointer<ChessPiece>(new Bishop("bishop_black"));
        board[0][3] = QSharedPointer<ChessPiece>(new Queen("queen_black"));
        board[0][4] = QSharedPointer<ChessPiece>(new King("king_black"));
        board[0][5] = QSharedPointer<ChessPiece>(new Bishop("bishop_black"));
        board[0][6] = QSharedPointer<ChessPiece>(new Knight("knight_black"));
        board[0][7] = QSharedPointer<ChessPiece>(new Castle("castle_black"));
        for (size_t i = 0; i < mCellCount; i++) {
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
        for (size_t i = 0; i < mCellCount; i++) {
            board[6][i] = QSharedPointer<ChessPiece>(new Pawn("pawn_white"));
        }
    } else {
        board[0][0] = QSharedPointer<ChessPiece>(new Castle(p2));
        board[0][1] = QSharedPointer<ChessPiece>(new Knight(p2));
        board[0][2] = QSharedPointer<ChessPiece>(new Bishop(p2));
        board[0][3] = QSharedPointer<ChessPiece>(new Queen(p2));
        board[0][4] = QSharedPointer<ChessPiece>(new King(p2));
        board[0][5] = QSharedPointer<ChessPiece>(new Bishop(p2));
        board[0][6] = QSharedPointer<ChessPiece>(new Knight(p2));
        board[0][7] = QSharedPointer<ChessPiece>(new Castle(p2));
        for (size_t i = 0; i < mCellCount; i++) {
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
        for (size_t i = 0; i < mCellCount; i++) {
            board[6][i] = QSharedPointer<ChessPiece>(new Pawn(p1));
        }
    }
}

void ChessBoard::startGame(const QString& mode)
{
    started = true;

    if (mode == "Offline") {
        this->mode = Offline;
    } else if (mode == "Online") {
        this->mode = Online;
    } else if (mode == "Computer") {
        this->mode = Computer;
    } else {
        throw std::exception();
    }

    bool is_white = QRandomGenerator::global()->generate() % 2;
    p1 = QSharedPointer<Player>(new Player(is_white, is_white, true));
    p2 = QSharedPointer<Player>(new Player(!is_white, !is_white, false));
    setDefaultBoard(p1, p2);
    connect(p1.get(), &Player::madeMove, p2.get(), &Player::setYourTurn);
    connect(p2.get(), &Player::madeMove, p1.get(), &Player::setYourTurn);

    emit gameStarted();
}

bool ChessBoard::isYourPiece(size_t posX, size_t posY)
{
    if (board[posY][posX] == nullptr)
        return false;
    return board[posY][posX]->getPlayerInfo() != nullptr && board[posY][posX]->getPlayerInfo()->isYourTurn();
}

QList<QList<int>> ChessBoard::validMoves()
{
    if (!board[mSelectedY][mSelectedX]->getPlayerInfo()->isYourTurn())
        return QList<QList<int>>();

    QList<QList<int>> moves = board[mSelectedY][mSelectedX]->moves(board, mSelectedX, mSelectedY);
    QList<QList<int>> validMoves;

    QSharedPointer<ChessPiece> pieceOnPos = nullptr;
    for (const QList<int>& move : moves) {
        int moveX = move[0];
        int moveY = move[1];
        pieceOnPos = board[moveY][moveX];
        board[moveY][moveX] = board[mSelectedY][mSelectedX];
        board[mSelectedY][mSelectedX] = nullptr;

        if ((p1->isYourTurn() && !isCheck(p1)) || (p2->isYourTurn() && !isCheck(p2))) {
            validMoves.push_back(move);
        }

        board[mSelectedY][mSelectedX] = board[moveY][moveX];
        board[moveY][moveX] = pieceOnPos;
    }

    return validMoves;
}

void ChessBoard::move() {
    if (p1->isYourTurn()) {
        p1->move();
    } else {
        p2->move();
    }

    board[mSelectedY][mSelectedX] = board[mSelectedPieceY][mSelectedPieceX];
    board[mSelectedPieceY][mSelectedPieceX] = nullptr;
    if (dynamic_cast<Pawn*>(board[mSelectedY][mSelectedX].get())) {
        dynamic_cast<Pawn*>(board[mSelectedY][mSelectedX].get())->setMadeMove();
    }

    if (isCheck(p1) || isCheck(p2)) {
        emit declareCheck();
    }
}

bool ChessBoard::isCheck(QSharedPointer<Player> p) const
{
    for (size_t i = 0; i < mCellCount; i++) {
        for (size_t j = 0; j < mCellCount; j++) {
            if (board[i][j] == nullptr || (board[i][j] != nullptr && board[i][j]->getPlayerInfo() == p))
                continue;

            QList<QList<int>> piece_move = board[i][j]->moves(board, j, i);
            for (const QList<int>& move : piece_move) {
                int posX = move[0];
                int posY = move[1];

                if (dynamic_cast<King*>(board[posY][posX].get())) {
                    return true;
                }
            }
        }
    }

    return false;
}

QString ChessBoard::getChessBoardImage() const
{
    if (p1 == nullptr && p2 == nullptr) {
        return chessBoardWhiteBottom;
    } else if (p1 == nullptr || p2 == nullptr) {
        throw std::exception();
    }

    if ((p1->isBottom() && p1->isWhite()) || (p2->isBottom() && p2->isWhite())) {
        return chessBoardWhiteBottom;
    } else {
        return chessboardBlackBottom;
    }
}

}
