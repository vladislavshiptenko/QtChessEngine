#include "king.h"

namespace qtchess {

QList<QList<int>> King::moves(const QSharedPointer<ChessPiece> board[][8], int posX, int posY)
{
    QList<QList<int>> moves;

    if (posX - 1 >= 0) {
        pushValidMove(board, moves, {posX - 1, posY}, posX, posY);
    }
    if (posX + 1 < 8) {
        pushValidMove(board, moves, {posX + 1, posY}, posX, posY);
    }
    if (posY - 1 >= 0) {
        pushValidMove(board, moves, {posX, posY - 1}, posX, posY);
    }
    if (posY + 1 < 8) {
        pushValidMove(board, moves, {posX, posY + 1}, posX, posY);
    }
    if (posX - 1 >= 0  && posY - 1 >= 0) {
        pushValidMove(board, moves, {posX - 1, posY - 1}, posX, posY);
    }
    if (posX - 1 >= 0 && posY + 1 < 8) {
        pushValidMove(board, moves, {posX - 1, posY + 1}, posX, posY);
    }
    if (posX + 1 < 8 && posY - 1 >= 0) {
        pushValidMove(board, moves, {posX + 1, posY - 1}, posX, posY);
    }
    if (posX + 1 < 8 && posY + 1 < 8) {
        pushValidMove(board, moves, {posX + 1, posY + 1}, posX, posY);
    }

    return moves;
}

}
