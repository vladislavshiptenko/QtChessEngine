#ifndef KING_H
#define KING_H
#include "chesspiece.h"

namespace qtchess {

class King : public ChessPiece {
public:
    King(char posx, char posy, QString image_source, Player* player = nullptr) : ChessPiece(posx, posy, image_source, player)  { }
    std::list<position> Moves() override;
};

}

#endif // KING_H
