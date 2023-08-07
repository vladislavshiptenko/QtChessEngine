#ifndef PAWN_H
#define PAWN_H
#include "chesspiece.h"

namespace qtchess {

class Pawn : public ChessPiece {
public:
    Pawn(QString imageName)
    {
        this->imageName = imageName + ".png";
    }
    Pawn(QSharedPointer<const Player> player) : ChessPiece(player)
    {
        pieceName = "pawn_";
        if (this->player->isWhite()) {
            this->imageName = pieceName + whitePieceName + ".png";
        } else {
            this->imageName = pieceName + blackPieceName + ".png";
        }
    }
    QList<QList<int>> moves(const QSharedPointer<ChessPiece> board[][8], int posX, int posY) override;
    void setMadeMove()
    {
        madeMove = true;
    }
    void pushValidStraightMove(const QSharedPointer<ChessPiece> board[][8], QList<QList<int>>& moves, const QList<int>& move);
    void pushValidDiagonalMove(const QSharedPointer<ChessPiece> board[][8], QList<QList<int>>& moves, const QList<int>& move, int posX, int posY);

private:
    bool madeMove = false;
};

}

#endif // PAWN_H
