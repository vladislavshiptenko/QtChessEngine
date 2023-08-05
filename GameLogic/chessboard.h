#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include <QQmlEngine>
#include "Pieces/chesspiece.h"
#include "player.h"

namespace qtchess {

enum Mode {
    Offline,
    Online,
    Computer
};

class ChessBoard : public QObject {
    Q_OBJECT
    Q_PROPERTY(NOTIFY gameStarted)
    QML_ELEMENT
public:
    ChessBoard();
    Q_INVOKABLE void startGame(const QString& mode);
    Q_INVOKABLE QString getImage(size_t i, size_t j);
    void SetDefaultBoard(QSharedPointer<Player> p1 = nullptr, QSharedPointer<Player> p2 = nullptr);

signals:
    void gameStarted();

private:
    size_t board_width = 8;
    size_t board_height = 8;
    bool is_started = false;
    bool is_check = false;
    bool is_checkmate = false;
    Mode mode;
    QSharedPointer<Player> p1 = nullptr;
    QSharedPointer<Player> p2 = nullptr;
    QSharedPointer<ChessPiece> board[8][8];
};

}

#endif // CHESSBOARD_H
