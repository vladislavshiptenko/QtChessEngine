#include "bishop.h"

namespace qtchess {

QList<QList<int>> Bishop::moves(const QSharedPointer<ChessPiece> board[][8], int posX, int posY)
{
    QList<QList<int>> moves;

    for (int i = 1; posX - i >= 0 && posY - i >= 0; i++) {
        if (!pushValidMove(board, moves, {posX - i, posY - i}, posX, posY)) {
            break;
        }
    }
    for (int i = 1; posX - i >= 0 && posY + i < 8; i++) {
        if (!pushValidMove(board, moves, {posX - i, posY + i}, posX, posY)) {
            break;
        }
    }
    for (int i = 1; posX + i < 8 && posY - i >= 0; i++) {
        if (!pushValidMove(board, moves, {posX + i, posY - i}, posX, posY)) {
            break;
        }
    }
    for (int i = 1; posX + i < 8 && posY + i < 8; i++) {
        if (!pushValidMove(board, moves, {posX + i, posY + i}, posX, posY)) {
            break;
        }
    }

    return moves;
}

}
