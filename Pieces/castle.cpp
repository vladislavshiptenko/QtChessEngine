#include "castle.h"

namespace qtchess {

QList<QList<int>> Castle::Moves(const QSharedPointer<ChessPiece> board[][8], int posx, int posy) {
    QList<QList<int>> moves;

    for (int x = posx + 1; x < 8; x++) {
        if (!PushValidMove(board, moves, {x, posy}, posx, posy)) {
            break;
        }
    }
    for (int x = posx - 1; x >= 0; x--) {
        if (!PushValidMove(board, moves, {x, posy}, posx, posy)) {
            break;
        }
    }
    for (int y = posy + 1; y < 8; y++) {
        if (!PushValidMove(board, moves, {posx, y}, posx, posy)) {
            break;
        }
    }
    for (int y = posy - 1; y >= 0; y--) {
        if (!PushValidMove(board, moves, {posx, y}, posx, posy)) {
            break;
        }
    }

    return moves;
}

}
