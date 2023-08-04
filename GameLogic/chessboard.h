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
    ChessBoard();
    void StartGame(const Mode& mode);
    Q_INVOKABLE QString getImage(size_t i, size_t j);
    void DefaultBoard();

private:
    size_t board_width = 8;
    size_t board_height = 8;
    bool is_started = false;
    bool is_check = false;
    bool is_checkmate = false;
    QSharedPointer<Player> p1 = nullptr;
    QSharedPointer<Player> p2 = nullptr;
    QSharedPointer<ChessPiece> board[8][8];
};

}

#endif // CHESSBOARD_H
