#include "chessboard.h"
#include "Pieces/bishop.h"
#include "Pieces/castle.h"
#include "Pieces/king.h"
#include "Pieces/knight.h"
#include "Pieces/pawn.h"
#include "Pieces/queen.h"
#include <QRandomGenerator>

namespace qtchess {

ChessBoard::ChessBoard() : players(QList<QSharedPointer<Player>>(countPlayers, nullptr))
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

void ChessBoard::setDefaultBoard(QSharedPointer<Player> pBottom, QSharedPointer<Player> pTop)
{
    if (players[0] == nullptr && players[0] == nullptr) {
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
    } else if (players[0] == nullptr || players[1] == nullptr) {
        throw std::exception();
    } else {
        board[0][0] = QSharedPointer<ChessPiece>(new Castle(pTop));
        board[0][1] = QSharedPointer<ChessPiece>(new Knight(pTop));
        board[0][2] = QSharedPointer<ChessPiece>(new Bishop(pTop));
        board[0][3] = QSharedPointer<ChessPiece>(new Queen(pTop));
        board[0][4] = QSharedPointer<ChessPiece>(new King(pTop));
        board[0][5] = QSharedPointer<ChessPiece>(new Bishop(pTop));
        board[0][6] = QSharedPointer<ChessPiece>(new Knight(pTop));
        board[0][7] = QSharedPointer<ChessPiece>(new Castle(pTop));
        for (size_t i = 0; i < mCellCount; i++) {
            board[1][i] = QSharedPointer<ChessPiece>(new Pawn(pTop));
        }

        board[7][0] = QSharedPointer<ChessPiece>(new Castle(pBottom));
        board[7][1] = QSharedPointer<ChessPiece>(new Knight(pBottom));
        board[7][2] = QSharedPointer<ChessPiece>(new Bishop(pBottom));
        board[7][3] = QSharedPointer<ChessPiece>(new Queen(pBottom));
        board[7][4] = QSharedPointer<ChessPiece>(new King(pBottom));
        board[7][5] = QSharedPointer<ChessPiece>(new Bishop(pBottom));
        board[7][6] = QSharedPointer<ChessPiece>(new Knight(pBottom));
        board[7][7] = QSharedPointer<ChessPiece>(new Castle(pBottom));
        for (size_t i = 0; i < mCellCount; i++) {
            board[6][i] = QSharedPointer<ChessPiece>(new Pawn(pBottom));
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
    players[0] = QSharedPointer<Player>(new Player(is_white, is_white, is_white));
    players[1] = QSharedPointer<Player>(new Player(!is_white, !is_white, !is_white));
    if (players[0]->isWhite()) {
        mCurrentPlayerIndex = 0;
        mYourPlayerIndex = 0;
    } else {
        mCurrentPlayerIndex = 1;
        mYourPlayerIndex = 1;
    }

    if (players[0]->isBottom()) {
        setDefaultBoard(players[0], players[1]);
    } else {
        setDefaultBoard(players[1], players[0]);
    }
    connect(players[0].get(), &Player::madeMove, players[1].get(), &Player::setYourTurn);
    connect(players[1].get(), &Player::madeMove, players[0].get(), &Player::setYourTurn);

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

        if (!isCheck(players[mCurrentPlayerIndex])) {
            validMoves.push_back(move);
        }

        board[mSelectedY][mSelectedX] = board[moveY][moveX];
        board[moveY][moveX] = pieceOnPos;
    }

    return validMoves;
}

void ChessBoard::move() {
    players[mCurrentPlayerIndex]->move();
    mCurrentPlayerIndex = (mCurrentPlayerIndex + 1) % countPlayers;

    board[mSelectedY][mSelectedX] = board[mSelectedPieceY][mSelectedPieceX];
    board[mSelectedPieceY][mSelectedPieceX] = nullptr;
    if (dynamic_cast<Pawn*>(board[mSelectedY][mSelectedX].get())) {
        dynamic_cast<Pawn*>(board[mSelectedY][mSelectedX].get())->setMadeMove();
    }

    if (mode == Offline) {
        bool tmp = players[1]->isBottom();
        players[1]->setBottom(players[0]->isBottom());
        players[0]->setBottom(tmp);
        mYourPlayerIndex = (mYourPlayerIndex + 1) % 2;
        flipBoard();
    }

    mCheck = isCheck(players[mCurrentPlayerIndex]);
    setCheckPos(players[mCurrentPlayerIndex]);

    emit moved();
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
    if (players[0] == nullptr && players[0] == nullptr) {
        return chessBoardWhiteBottom;
    } else if (players[0] == nullptr || players[0] == nullptr) {
        throw std::exception();
    }

    if ((players[0]->isBottom() && players[0]->isWhite()) || (players[1]->isBottom() && players[1]->isWhite())) {
        return chessBoardWhiteBottom;
    } else {
        return chessboardBlackBottom;
    }
}

void ChessBoard::flipBoard()
{
    for (size_t i = 0; i < mCellCount; i++) {
        for (size_t j = 0; j < mCellCount - i - 1; j++) {
            std::swap(board[i][j], board[mCellCount - i - 1][mCellCount - j - 1]);
        }
    }

    for (size_t i = 0; i < mCellCount / 2; i++) {
        std::swap(board[mCellCount - i - 1][i], board[i][mCellCount - i - 1]);
    }
}

void ChessBoard::setCheckPos(QSharedPointer<Player> p) {
    for (size_t i = 0; i < mCellCount; i++) {
        for (size_t j = 0; j < mCellCount; j++) {
            if (board[i][j] == nullptr || (board[i][j] != nullptr && board[i][j]->getPlayerInfo() == p))
                continue;

            QList<QList<int>> piece_move = board[i][j]->moves(board, j, i);
            for (const QList<int>& move : piece_move) {
                int posX = move[0];
                int posY = move[1];

                if (dynamic_cast<King*>(board[posY][posX].get())) {
                    mCheckPosX = posX;
                    mCheckPosY = posY;
                    return;
                }
            }
        }
    }
}

}
