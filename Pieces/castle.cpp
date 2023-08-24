#include "castle.h"

namespace qtchess {

QList<QList<int>> Castle::moves(const QSharedPointer<ChessPiece> board[][8], int posX, int posY)
{
    QList<QList<int>> moves;

    for (int x = posX + 1; x < 8; x++) {
        if (!pushValidMove(board, moves, {x, posY}, posX, posY)) {
            break;
        }
    }
    for (int x = posX - 1; x >= 0; x--) {
        if (!pushValidMove(board, moves, {x, posY}, posX, posY)) {
            break;
        }
    }
    for (int y = posY + 1; y < 8; y++) {
        if (!pushValidMove(board, moves, {posX, y}, posX, posY)) {
            break;
        }
    }
    for (int y = posY - 1; y >= 0; y--) {
        if (!pushValidMove(board, moves, {posX, y}, posX, posY)) {
            break;
        }
    }

    return moves;
}

}
