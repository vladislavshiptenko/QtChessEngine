#include "pawn.h"

namespace qtchess {

QList<QList<int>> Pawn::moves(const QSharedPointer<ChessPiece> board[][8], int posX, int posY)
{
    QList<QList<int>> moves;

    if (player->isBottom()) {
        pushValidStraightMove(board, moves, {posX, posY - 1});
        if (!madeMove)
            pushValidStraightMove(board, moves, {posX, posY - 2});

        pushValidDiagonalMove(board, moves, {posX - 1, posY - 1}, posX, posY);
        pushValidDiagonalMove(board, moves, {posX + 1, posY - 1}, posX, posY);
    }
    else {
        pushValidStraightMove(board, moves, {posX, posY + 1});
        if (!madeMove)
            pushValidStraightMove(board, moves, {posX, posY + 2});

        pushValidDiagonalMove(board, moves, {posX + 1, posY + 1}, posX, posY);
        pushValidDiagonalMove(board, moves, {posX - 1, posY + 1}, posX, posY);
    }

    return moves;
}

void Pawn::pushValidStraightMove(const QSharedPointer<ChessPiece> board[][8], QList<QList<int>>& moves, const QList<int>& move) {
    size_t moveX = move[0];
    size_t moveY = move[1];

    if (!board[moveY][moveX]) {
        moves.push_back(move);
    }
}

void Pawn::pushValidDiagonalMove(const QSharedPointer<ChessPiece> board[][8], QList<QList<int>>& moves, const QList<int>& move, int posX, int posY) {
    size_t moveX = move[0];
    size_t moveY = move[1];

    if (moveX < 0 || moveX > 8 || moveY < 0 || moveY > 8)
        return;

    if ((board[moveY][moveX] && board[moveY][moveX]->getPlayerInfo() != board[posY][posX]->getPlayerInfo())) {
        moves.push_back(move);
    }
}

}
