#ifndef KING_H
#define KING_H
#include "chesspiece.h"

namespace qtchess {

class King : public ChessPiece {
public:
    King(QString imageName)
    {
        this->imageName = imageName + ".png";
    }
    King(QSharedPointer<const Player> player) : ChessPiece(player)
    {
        pieceName = "king_";
        if (this->player->isWhite()) {
            this->imageName = pieceName + whitePieceName + ".png";
        } else {
            this->imageName = pieceName + blackPieceName + ".png";
        }
    }
    QList<QList<int>> moves(const QSharedPointer<ChessPiece> board[][8], int posX, int posY) override;
};

}

#endif // KING_H
