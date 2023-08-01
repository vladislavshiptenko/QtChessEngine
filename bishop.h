#ifndef BISHOP_H
#define BISHOP_H
#include "chesspiece.h"

namespace qtchess {

class Bishop : public ChessPiece {
public:
    Bishop(char posx, char posy, Player* player = nullptr) : ChessPiece(posx, posy, player)  { }
    std::list<position> Moves() override;
};

}

#endif // BISHOP_H
