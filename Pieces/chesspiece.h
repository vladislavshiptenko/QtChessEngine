#ifndef CHESSPIECE_H
#define CHESSPIECE_H
#include <list>
#include <QSharedPointer>
#include "GameLogic/player.h"
#include <QList>

namespace qtchess {

class ChessPiece {
public:
    ChessPiece(QSharedPointer<const Player> player = nullptr) : player(player)  { }
    virtual QList<QList<int>> Moves(const QSharedPointer<ChessPiece> board[][8], int posx, int posy) = 0;
    QString GetImageSource() const noexcept { return path + image_name; }
    QSharedPointer<const Player> GetPlayerInfo() const noexcept { return player; }

protected:
    QString black_piece_name = "black";
    QString white_piece_name = "white";
    QString piece_name;
    QString image_name;
    QSharedPointer<const Player> player;
    bool PushValidMove(const QSharedPointer<ChessPiece> board[][8], QList<QList<int>>& moves, const QList<int>& move, int posx, int posy);

private:
    QString path = "qrc:/Assets/";
};

}

#endif // CHESSPIECE_H
