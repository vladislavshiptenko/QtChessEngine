#ifndef CHESSPIECE_H
#define CHESSPIECE_H
#include <list>
#include <QSharedPointer>
#include "GameLogic/player.h"
#include <QList>

namespace qtchess {

class ChessPiece {
public:
    ChessPiece(QSharedPointer<const Player> player = nullptr) : player(player)
    {}
    virtual QList<QList<int>> moves(const QSharedPointer<ChessPiece> board[][8], int posX, int posY) = 0;
    QString getImageSource() const noexcept
    {
        return path + imageName;
    }
    QSharedPointer<const Player> getPlayerInfo() const noexcept
    {
        return player;
    }
    void setPlayerNull()
    {
        player = nullptr;
    }

protected:
    QString blackPieceName = "black";
    QString whitePieceName = "white";
    QString pieceName;
    QString imageName;
    QSharedPointer<const Player> player;
    bool pushValidMove(const QSharedPointer<ChessPiece> board[][8], QList<QList<int>>& moves, const QList<int>& move, int posX, int posY);

private:
    QString path = "qrc:/Assets/";
};

}

#endif // CHESSPIECE_H
