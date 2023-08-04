#ifndef PAWN_H
#define PAWN_H
#include "chesspiece.h"

namespace qtchess {

class Pawn : public ChessPiece {
public:
    Pawn(char posx, char posy, QString image_source, Player* player = nullptr) : ChessPiece(posx, posy, image_source, player)  { }
    std::list<position> Moves() override;

private:
    bool is_moved = false;
};

}

#endif // PAWN_H
