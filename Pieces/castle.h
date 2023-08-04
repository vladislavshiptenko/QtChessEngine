#ifndef CASTLE_H
#define CASTLE_H
#include "chesspiece.h"

namespace qtchess {

class Castle : public ChessPiece {
public:
    Castle(char posx, char posy, QString image_source, Player* player = nullptr) : ChessPiece(posx, posy, image_source, player)  { }
    std::list<position> Moves() override;
};

}

#endif // CASTLE_H
