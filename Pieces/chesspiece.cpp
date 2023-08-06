#include "chesspiece.h"

namespace qtchess {

bool ChessPiece::PushValidMove(const QSharedPointer<ChessPiece> board[][8], QList<QList<int>>& moves, const QList<int>& move, int posx, int posy) {
    size_t move_x = move[0];
    size_t move_y = move[1];

    if (!board[move_y][move_x] || (board[move_y][move_x] && board[move_y][move_x]->GetPlayerInfo() != board[posy][posx]->GetPlayerInfo())) {
        moves.push_back(move);
    }

    return board[move_y][move_x] == nullptr;
}

}
