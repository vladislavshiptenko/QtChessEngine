#ifndef CASTLE_H
#define CASTLE_H
#include "chesspiece.h"

namespace qtchess {

class Castle : public ChessPiece {
public:
    Castle(QString imageName)
    {
        this->imageName = imageName + ".png";
    }
    Castle(QSharedPointer<const Player> player) : ChessPiece(player)
    {
        pieceName = "castle_";
        if (this->player->isWhite()) {
            this->imageName = pieceName + whitePieceName + ".png";
        } else {
            this->imageName = pieceName + blackPieceName + ".png";
        }
    }
    QList<QList<int>> moves(const QSharedPointer<ChessPiece> board[][8], int posX, int posY) override;
};

}

#endif // CASTLE_H
