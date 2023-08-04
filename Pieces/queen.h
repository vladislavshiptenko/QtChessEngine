#ifndef QUEEN_H
#define QUEEN_H
#include "chesspiece.h"

namespace qtchess {

class Queen : public ChessPiece {
public:
    Queen(char posx, char posy, QString image_source, Player* player = nullptr) : ChessPiece(posx, posy, image_source, player)  { }
    std::list<position> Moves() override;
};

}

#endif // QUEEN_H
