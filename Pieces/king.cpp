#include "king.h"

namespace qtchess {

QList<QList<int>> King::Moves(const QSharedPointer<ChessPiece> board[][8], int posx, int posy) {
    QList<QList<int>> moves;

    if (posx - 1 >= 0) {
        PushValidMove(board, moves, {posx - 1, posy}, posx, posy);
    }
    if (posx + 1 < 8) {
        PushValidMove(board, moves, {posx + 1, posy}, posx, posy);
    }
    if (posy - 1 >= 0) {
        PushValidMove(board, moves, {posx, posy - 1}, posx, posy);
    }
    if (posy + 1 < 8) {
        PushValidMove(board, moves, {posx, posy + 1}, posx, posy);
    }
    if (posx - 1 >= 0  && posy - 1 >= 0) {
        PushValidMove(board, moves, {posx - 1, posy - 1}, posx, posy);
    }
    if (posx - 1 >= 0 && posy + 1 < 8) {
        PushValidMove(board, moves, {posx - 1, posy + 1}, posx, posy);
    }
    if (posx + 1 < 8 && posy - 1 >= 0) {
        PushValidMove(board, moves, {posx + 1, posy - 1}, posx, posy);
    }
    if (posx + 1 < 8 && posy + 1 < 8) {
        PushValidMove(board, moves, {posx + 1, posy + 1}, posx, posy);
    }

    return moves;
}

}
