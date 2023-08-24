#include "chesspiece.h"

namespace qtchess {

bool ChessPiece::pushValidMove(const QSharedPointer<ChessPiece> board[][8], QList<QList<int>>& moves, const QList<int>& move, int posX, int posY)
{
    size_t moveX = move[0];
    size_t moveY = move[1];

    if (!board[moveY][moveX] || (board[moveY][moveX] && board[moveY][moveX]->getPlayerInfo() != board[posY][posX]->getPlayerInfo())) {
        moves.push_back(move);
    }

    return board[moveY][moveX] == nullptr;
}

}
