#include "king.h"

namespace qtchess {

std::list<position> King::Moves() {
    if (!player_info->YourTurn())
        return std::list<position>();

    std::list<position> moves;

    if (pos.posx > 'a') {
        moves.push_back({char(pos.posx - 1), pos.posy});
    }
    if (pos.posx < 'h') {
        moves.push_back({char(pos.posx + 1), pos.posy});
    }
    if (pos.posy > '1') {
        moves.push_back({pos.posx, char(pos.posy - 1)});
    }
    if (pos.posy < '8') {
        moves.push_back({pos.posx, char(pos.posy + 1)});
    }
    if (pos.posx > 'a' && pos.posy > '1') {
        moves.push_back({char(pos.posx - 1), char(pos.posy - 1)});
    }
    if (pos.posx > 'a' && pos.posy < '8') {
        moves.push_back({char(pos.posx - 1), char(pos.posy + 1)});
    }
    if (pos.posx < 'h' && pos.posy > '1') {
        moves.push_back({char(pos.posx + 1), char(pos.posy - 1)});
    }
    if (pos.posx < 'h' && pos.posy < '8') {
        moves.push_back({char(pos.posx + 1), char(pos.posy + 1)});
    }

    return moves;
}

}
