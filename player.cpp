#include "player.h"

namespace qtchess {

void Player::Move() {

}

bool PlayerInfo::IsWhite() const noexcept {
    return is_white;
}

bool PlayerInfo::YourTurn() const noexcept {
    return your_turn;
}

bool PlayerInfo::IsBottom() const noexcept {
    return is_bottom;
}

}
