#ifndef CHESSPIECE_H
#define CHESSPIECE_H
#include <list>
#include <QSharedPointer>
#include "GameLogic/player.h"

namespace qtchess {

struct position {
    char posx;
    char posy;
};

class ChessPiece {
public:
    ChessPiece(char posx, char posy, QString image_source, PlayerInfo* player_info = nullptr) : pos{posx, posy}, player_info(player_info), image_source(image_source)  { }
    virtual std::list<position> Moves() = 0;
    QString GetImageSource() { return image_source; }

protected:
    position pos;
    QString image_source;
    QSharedPointer<PlayerInfo> player_info;
};

}

#endif // CHESSPIECE_H
