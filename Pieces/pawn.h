#ifndef PAWN_H
#define PAWN_H
#include "chesspiece.h"

namespace qtchess {

class Pawn : public ChessPiece {
public:
    Pawn(char posx, char posy, QString image_name) : ChessPiece(posx, posy)  {
        this->image_name = image_name + ".png";
    }
    Pawn(char posx, char posy, QSharedPointer<PlayerInfo> player_info) : ChessPiece(posx, posy, player_info) {
        piece_name = "pawn_";
        if (this->player_info->IsWhite())
            this->image_name = piece_name + white_piece_name + ".png";
        else
            this->image_name = piece_name + black_piece_name + ".png";
    }
    std::list<position> Moves() override;

private:
    bool is_moved = false;
};

}

#endif // PAWN_H
