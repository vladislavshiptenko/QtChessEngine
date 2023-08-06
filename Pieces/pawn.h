#ifndef PAWN_H
#define PAWN_H
#include "chesspiece.h"

namespace qtchess {

class Pawn : public ChessPiece {
public:
    Pawn(QString image_name)  {
        this->image_name = image_name + ".png";
    }
    Pawn(QSharedPointer<const Player> player) : ChessPiece(player) {
        piece_name = "pawn_";
        if (this->player->IsWhite())
            this->image_name = piece_name + white_piece_name + ".png";
        else
            this->image_name = piece_name + black_piece_name + ".png";
    }
    QList<QList<int>> Moves(const QSharedPointer<ChessPiece> board[][8], int posx, int posy) override;
    void SetMadeMove() { made_move = true; }
    void PushValidStraightMove(const QSharedPointer<ChessPiece> board[][8], QList<QList<int>>& moves, const QList<int>& move);
    void PushValidDiagonalMove(const QSharedPointer<ChessPiece> board[][8], QList<QList<int>>& moves, const QList<int>& move, int posx, int posy);

private:
    bool made_move = false;
};

}

#endif // PAWN_H
