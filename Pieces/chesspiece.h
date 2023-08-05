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
    ChessPiece(char posx, char posy, QSharedPointer<PlayerInfo> player_info = nullptr) : pos{posx, posy}, player_info(player_info)  { }
    virtual std::list<position> Moves() = 0;
    QString GetImageSource() { return path + image_name; }

protected:
    QString black_piece_name = "black";
    QString white_piece_name = "white";
    QString piece_name;
    position pos;
    QString image_name;
    QSharedPointer<PlayerInfo> player_info;

private:
    QString path = "qrc:/Assets/";
};

}

#endif // CHESSPIECE_H
