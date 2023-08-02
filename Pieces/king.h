#ifndef KING_H
#define KING_H
#include "chesspiece.h"

namespace qtchess {

class King : public ChessPiece {
public:
    King(char posx, char posy, Player* player = nullptr) : ChessPiece(posx, posy, player)  { }
    std::list<position> Moves() override;
};

}

#endif // KING_H
