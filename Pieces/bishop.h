#ifndef BISHOP_H
#define BISHOP_H
#include "chesspiece.h"

namespace qtchess {

class Bishop : public ChessPiece {
public:
    Bishop(QString imageName)
    {
        this->imageName = imageName + ".png";
    }
    Bishop(QSharedPointer<const Player> player) : ChessPiece(player)
    {
        pieceName = "bishop_";
        if (this->player->isWhite()) {
            this->imageName = pieceName + whitePieceName + ".png";
        } else {
            this->imageName = pieceName + blackPieceName + ".png";
        }
    }
    QList<QList<int>> moves(const QSharedPointer<ChessPiece> board[][8], int posX, int posY) override;
};

}

#endif // BISHOP_H
