#include "queen.h"

namespace qtchess {

QList<QList<int>> Queen::moves(const QSharedPointer<ChessPiece> board[][8], int posX, int posY)
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
