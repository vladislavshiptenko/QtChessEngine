#ifndef QUEEN_H
#define QUEEN_H
#include "chesspiece.h"

namespace qtchess {

class Queen : public ChessPiece {
public:
    Queen(QString imageName)
    {
        this->imageName = imageName + ".png";
    }
    Queen(QSharedPointer<const Player> player) : ChessPiece(player)
    {
        pieceName = "queen_";
        if (this->player->isWhite()) {
            this->imageName = pieceName + whitePieceName + ".png";
        } else {
            this->imageName = pieceName + blackPieceName + ".png";
        }
    }
    QList<QList<int>> moves(const QSharedPointer<ChessPiece> board[][8], int posX, int posY) override;
};

}

#endif // QUEEN_H
