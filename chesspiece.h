#ifndef CHESSPIECE_H
#define CHESSPIECE_H
#include <list>
#include <QSharedPointer>
#include "player.h"

namespace qtchess {

struct position {
    char posx;
    char posy;
};

class ChessPiece {
public:
    ChessPiece(char posx, char posy, PlayerInfo* player_info = nullptr) : pos{posx, posy}, player_info(player_info)  { }
    virtual std::list<position> Moves() = 0;

protected:
    position pos;
    QSharedPointer<PlayerInfo> player_info;
};

}

#endif // CHESSPIECE_H
