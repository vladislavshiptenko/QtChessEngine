#include "player.h"

namespace qtchess {

void Player::move() {
    // change is_bottom and timer
    yourTurn = false;

    emit madeMove();
}

bool Player::isWhite() const noexcept {
    return white;
}

bool Player::isYourTurn() const noexcept {
    return yourTurn;
}

bool Player::isBottom() const noexcept {
    return bottom;
}

void Player::setYourTurn() {
    // change is_bottom and timer
    yourTurn = true;
}

}
