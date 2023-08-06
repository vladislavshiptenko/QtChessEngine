#include "knight.h"

namespace qtchess {

QList<QList<int>> Knight::Moves(const QSharedPointer<ChessPiece> board[][8], int posx, int posy) {
    QList<QList<int>> moves;

    if (posx - 1 >= 0 && posy - 2 >= 0) {
        PushValidMove(board, moves, {posx - 1, posy - 2}, posx, posy);
    }
    if (posx + 1 < 8 && posy - 2 >= 0) {
        PushValidMove(board, moves, {posx + 1, posy - 2}, posx, posy);
    }
    if (posx - 1 >= 0 && posy + 2 < 8) {
        PushValidMove(board, moves, {posx - 1, posy + 2}, posx, posy);
    }
    if (posx + 1 < 8 && posy + 2 < 8) {
        PushValidMove(board, moves, {posx + 1, posy + 2}, posx, posy);
    }

    if (posx - 2 >= 0 && posy - 1 >= 0) {
        PushValidMove(board, moves, {posx - 2, posy - 1}, posx, posy);
    }
    if (posx + 2 < 8 && posy - 1 >= 0) {
        PushValidMove(board, moves, {posx + 2, posy - 1}, posx, posy);
    }
    if (posx - 2 >= 0 && posy + 1 < 8) {
        PushValidMove(board, moves, {posx - 2, posy + 1}, posx, posy);
    }
    if (posx + 2 < 8 && posy + 1 < 8) {
        PushValidMove(board, moves, {posx + 2, posy + 1}, posx, posy);
    }

    return moves;
}

}
