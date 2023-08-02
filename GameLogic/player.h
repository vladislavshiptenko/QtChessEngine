#ifndef PLAYER_H
#define PLAYER_H

namespace qtchess {

class PlayerInfo {
public:
    PlayerInfo(bool is_white, bool your_turn, bool is_bottom) : is_white(is_white), your_turn(your_turn), is_bottom(is_bottom) { };
    bool IsWhite() const noexcept;
    bool YourTurn() const noexcept;
    bool IsBottom() const noexcept;

private:
    bool is_white;
    bool your_turn;
    bool is_bottom;
};

class Player : public PlayerInfo {
public:
    Player(bool is_white, bool your_turn, bool is_bottom) : PlayerInfo(is_white, your_turn, is_bottom) { };
    virtual void Move();
};

}

#endif // PLAYER_H
