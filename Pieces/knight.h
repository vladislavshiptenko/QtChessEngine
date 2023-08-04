#ifndef KNIGHT_H
#define KNIGHT_H
#include "chesspiece.h"

namespace qtchess {

class Knight : public ChessPiece {
public:
    Knight(char posx, char posy, QString image_source, Player* player = nullptr) : ChessPiece(posx, posy, image_source, player)  { }
    std::list<position> Moves() override;
};

}

#endif // KNIGHT_H
