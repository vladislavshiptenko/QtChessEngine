#include "bishop.h"

namespace qtchess {

QList<QList<int>> Bishop::Moves(const QSharedPointer<ChessPiece> board[][8], int posx, int posy) {
    QList<QList<int>> moves;

    for (int i = 1; posx - i >= 0 && posy - i >= 0; i++) {
        if (!PushValidMove(board, moves, {posx - i, posy - i}, posx, posy)) {
            break;
        }
    }
    for (int i = 1; posx - i >= 0 && posy + i < 8; i++) {
        if (!PushValidMove(board, moves, {posx - i, posy + i}, posx, posy)) {
            break;
        }
    }
    for (int i = 1; posx + i < 8 && posy - i >= 0; i++) {
        if (!PushValidMove(board, moves, {posx + i, posy - i}, posx, posy)) {
            break;
        }
    }
    for (int i = 1; posx + i < 8 && posy + i < 8; i++) {
        if (!PushValidMove(board, moves, {posx + i, posy + i}, posx, posy)) {
            break;
        }
    }

    return moves;
}

}
