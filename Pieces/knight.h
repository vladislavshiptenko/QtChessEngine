#ifndef KNIGHT_H
#define KNIGHT_H
#include "chesspiece.h"

namespace qtchess {

class Knight : public ChessPiece {
public:
    Knight(char posx, char posy, QString image_name) : ChessPiece(posx, posy)  {
        this->image_name = image_name + ".png";
    }
    Knight(char posx, char posy, QSharedPointer<PlayerInfo> player_info) : ChessPiece(posx, posy, player_info) {
        piece_name = "knight_";
        if (this->player_info->IsWhite())
            this->image_name = piece_name + white_piece_name + ".png";
        else
            this->image_name = piece_name + black_piece_name + ".png";
    }
    std::list<position> Moves() override;
};

}

#endif // KNIGHT_H
