#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include <QQmlEngine>
#include "Pieces/chesspiece.h"
#include "Pieces/bishop.h"
#include "Pieces/castle.h"
#include "Pieces/king.h"
#include "Pieces/knight.h"
#include "Pieces/pawn.h"
#include "Pieces/queen.h"
#include "player.h"

namespace qtchess {

struct Mode {
    enum Opponent {
        Offline,
        Online,
        Computer
    } opponent;
}; // что насчёт таймера?

class ChessBoard : public QObject {
    Q_OBJECT
    QML_ELEMENT
public:
    ChessBoard() {};
    void StartGame(const Mode& mode);
    void DefautBoard(QSharedPointer<Player> p1, QSharedPointer<Player> p2);

private:
    bool is_started;
    bool is_check;
    bool is_checkmate;
    QSharedPointer<Player> p1;
    QSharedPointer<Player> p2;
    QSharedPointer<ChessPiece> board[8][8];
};

}

#endif // CHESSBOARD_H
