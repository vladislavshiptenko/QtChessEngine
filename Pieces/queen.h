#ifndef QUEEN_H
#define QUEEN_H
#include "chesspiece.h"

namespace qtchess {

class Queen : public ChessPiece {
public:
    Queen(QString image_name) {
        this->image_name = image_name + ".png";
    }
    Queen(QSharedPointer<const Player> player) : ChessPiece(player) {
        piece_name = "queen_";
        if (this->player->IsWhite())
            this->image_name = piece_name + white_piece_name + ".png";
        else
            this->image_name = piece_name + black_piece_name + ".png";
    }
    QList<QList<int>> Moves(const QSharedPointer<ChessPiece> board[][8], int posx, int posy) override;
};

}

#endif // QUEEN_H
