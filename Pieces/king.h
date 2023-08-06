#ifndef KING_H
#define KING_H
#include "chesspiece.h"

namespace qtchess {

class King : public ChessPiece {
public:
    King(QString image_name) {
        this->image_name = image_name + ".png";
    }
    King(QSharedPointer<const Player> player) : ChessPiece(player) {
        piece_name = "king_";
        if (this->player->IsWhite())
            this->image_name = piece_name + white_piece_name + ".png";
        else
            this->image_name = piece_name + black_piece_name + ".png";
    }
    QList<QList<int>> Moves(const QSharedPointer<ChessPiece> board[][8], int posx, int posy) override;
};

}

#endif // KING_H
