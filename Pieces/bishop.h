#ifndef BISHOP_H
#define BISHOP_H
#include "chesspiece.h"

namespace qtchess {

class Bishop : public ChessPiece {
public:
    Bishop(QString image_name) {
        this->image_name = image_name + ".png";
    }
    Bishop(QSharedPointer<const Player> player) : ChessPiece(player) {
        piece_name = "bishop_";
        if (this->player->IsWhite())
            this->image_name = piece_name + white_piece_name + ".png";
        else
            this->image_name = piece_name + black_piece_name + ".png";
    }
    QList<QList<int>> Moves(const QSharedPointer<ChessPiece> board[][8], int posx, int posy) override;
};

}

#endif // BISHOP_H
