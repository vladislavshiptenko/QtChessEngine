#ifndef KNIGHT_H
#define KNIGHT_H
#include "chesspiece.h"

namespace qtchess {

class Knight : public ChessPiece {
public:
    Knight(char posx, char posy, Player* player = nullptr) : ChessPiece(posx, posy, player)  { }
    std::list<position> Moves() override;
};

}

#endif // KNIGHT_H
