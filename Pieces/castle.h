#ifndef CASTLE_H
#define CASTLE_H
#include "chesspiece.h"

namespace qtchess {

class Castle : public ChessPiece {
public:
    Castle(QString image_name)  {
        this->image_name = image_name + ".png";
    }
    Castle(QSharedPointer<const Player> player) : ChessPiece(player) {
        piece_name = "castle_";
        if (this->player->IsWhite())
            this->image_name = piece_name + white_piece_name + ".png";
        else
            this->image_name = piece_name + black_piece_name + ".png";
    }
    QList<QList<int>> Moves(const QSharedPointer<ChessPiece> board[][8], int posx, int posy) override;
};

}

#endif // CASTLE_H
