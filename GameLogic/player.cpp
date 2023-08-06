#include "player.h"

namespace qtchess {

void Player::Move() {
    // change is_bottom and timer
    your_turn = false;

    emit MadeMove();
}

bool Player::IsWhite() const noexcept {
    return is_white;
}

bool Player::IsYourTurn() const noexcept {
    return your_turn;
}

bool Player::IsBottom() const noexcept {
    return is_bottom;
}

void Player::YourTurn() {
    // change is_bottom and timer
    your_turn = true;
}

}
