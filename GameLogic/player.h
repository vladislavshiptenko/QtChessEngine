#ifndef PLAYER_H
#define PLAYER_H
#include <QObject>

namespace qtchess {

class Player : public QObject {
    Q_OBJECT

public:
    Player(bool is_white, bool your_turn, bool is_bottom) : is_white(is_white), your_turn(your_turn), is_bottom(is_bottom) { };
    virtual void Move();
    void YourTurn();
    bool IsWhite() const noexcept;
    bool IsYourTurn() const noexcept;
    bool IsBottom() const noexcept;

signals:
    void MadeMove();

private:
    bool is_white;
    bool your_turn;
    bool is_bottom;
};

}

#endif // PLAYER_H
