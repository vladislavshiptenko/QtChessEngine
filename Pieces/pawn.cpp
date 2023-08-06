#include "pawn.h"

namespace qtchess {

QList<QList<int>> Pawn::Moves(const QSharedPointer<ChessPiece> board[][8], int posx, int posy) {
    QList<QList<int>> moves;

    if (player->IsBottom()) {
        PushValidStraightMove(board, moves, {posx, posy - 1});
        if (!made_move)
            PushValidStraightMove(board, moves, {posx, posy - 2});

        PushValidDiagonalMove(board, moves, {posx - 1, posy - 1}, posx, posy);
        PushValidDiagonalMove(board, moves, {posx + 1, posy - 1}, posx, posy);
    }
    else {
        PushValidStraightMove(board, moves, {posx, posy + 1});
        if (!made_move)
            PushValidStraightMove(board, moves, {posx, posy + 2});

        PushValidDiagonalMove(board, moves, {posx + 1, posy + 1}, posx, posy);
        PushValidDiagonalMove(board, moves, {posx - 1, posy + 1}, posx, posy);
    }

    return moves;
}

void Pawn::PushValidStraightMove(const QSharedPointer<ChessPiece> board[][8], QList<QList<int>>& moves, const QList<int>& move) {
    size_t move_x = move[0];
    size_t move_y = move[1];

    if (!board[move_y][move_x]) {
        moves.push_back(move);
    }
}

void Pawn::PushValidDiagonalMove(const QSharedPointer<ChessPiece> board[][8], QList<QList<int>>& moves, const QList<int>& move, int posx, int posy) {
    size_t move_x = move[0];
    size_t move_y = move[1];

    if (move_x < 0 || move_x > 8 || move_y < 0 || move_y > 8)
        return;

    if ((board[move_y][move_x] && board[move_y][move_x]->GetPlayerInfo() != board[posy][posx]->GetPlayerInfo())) {
        moves.push_back(move);
    }
}

}
