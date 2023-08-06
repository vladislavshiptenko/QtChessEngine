#include "queen.h"

namespace qtchess {

QList<QList<int>> Queen::Moves(const QSharedPointer<ChessPiece> board[][8], int posx, int posy) {
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
