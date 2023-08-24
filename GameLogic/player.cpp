#include "player.h"

namespace qtchess {

void Player::move()
{
    yourTurn = false;

    emit madeMove();
}

bool Player::isWhite() const noexcept
{
    return white;
}

bool Player::isYourTurn() const noexcept
{
    return yourTurn;
}

bool Player::isBottom() const noexcept
{
    return bottom;
}

void Player::setYourTurn()
{
    yourTurn = true;
}

void Player::setBottom(bool isBottom)
{
    bottom = isBottom;
}

}
