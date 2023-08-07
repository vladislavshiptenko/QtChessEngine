#include "knight.h"

namespace qtchess {

QList<QList<int>> Knight::moves(const QSharedPointer<ChessPiece> board[][8], int posX, int posY)
{
    QList<QList<int>> moves;

    if (posX - 1 >= 0 && posY - 2 >= 0) {
        pushValidMove(board, moves, {posX - 1, posY - 2}, posX, posY);
    }
    if (posX + 1 < 8 && posY - 2 >= 0) {
        pushValidMove(board, moves, {posX + 1, posY - 2}, posX, posY);
    }
    if (posX - 1 >= 0 && posY + 2 < 8) {
        pushValidMove(board, moves, {posX - 1, posY + 2}, posX, posY);
    }
    if (posX + 1 < 8 && posY + 2 < 8) {
        pushValidMove(board, moves, {posX + 1, posY + 2}, posX, posY);
    }

    if (posX - 2 >= 0 && posY - 1 >= 0) {
        pushValidMove(board, moves, {posX - 2, posY - 1}, posX, posY);
    }
    if (posX + 2 < 8 && posY - 1 >= 0) {
        pushValidMove(board, moves, {posX + 2, posY - 1}, posX, posY);
    }
    if (posX - 2 >= 0 && posY + 1 < 8) {
        pushValidMove(board, moves, {posX - 2, posY + 1}, posX, posY);
    }
    if (posX + 2 < 8 && posY + 1 < 8) {
        pushValidMove(board, moves, {posX + 2, posY + 1}, posX, posY);
    }

    return moves;
}

}
