#ifndef KNIGHT_H
#define KNIGHT_H
#include "chesspiece.h"

namespace qtchess {

class Knight : public ChessPiece {
public:
    Knight(QString imageName)
    {
        this->imageName = imageName + ".png";
    }
    Knight(QSharedPointer<const Player> player) : ChessPiece(player)
    {
        pieceName = "knight_";
        if (this->player->isWhite()) {
            this->imageName = pieceName + whitePieceName + ".png";
        } else {
            this->imageName = pieceName + blackPieceName + ".png";
        }
    }
    QList<QList<int>> moves(const QSharedPointer<ChessPiece> board[][8], int posX, int posY) override;
};

}

#endif // KNIGHT_H
