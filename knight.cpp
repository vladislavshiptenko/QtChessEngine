#include "knight.h"

namespace qtchess {

std::list<position> Knight::Moves() {
    if (!player_info->YourTurn())
        return std::list<position>();

    std::list<position> moves;
    if (pos.posx - 1 >= 'a' && pos.posy - 2 >= '1') {
        moves.push_back({char(pos.posx - 1), char(pos.posy - 2)});
    }
    if (pos.posx + 1 <= 'h' && pos.posy - 2 >= '1') {
        moves.push_back({char(pos.posx + 1), char(pos.posy - 2)});
    }
    if (pos.posx - 1 >= 'a' && pos.posy + 2 <= '8') {
        moves.push_back({char(pos.posx - 1), char(pos.posy + 2)});
    }
    if (pos.posx + 1 <= 'h' && pos.posy + 2 <= '8') {
        moves.push_back({char(pos.posx + 1), char(pos.posy + 2)});
    }

    if (pos.posx - 2 >= 'a' && pos.posy - 1 >= '1') {
        moves.push_back({char(pos.posx - 2), char(pos.posy - 1)});
    }
    if (pos.posx + 2 <= 'h' && pos.posy - 1 >= '1') {
        moves.push_back({char(pos.posx + 2), char(pos.posy - 1)});
    }
    if (pos.posx - 2 >= 'a' && pos.posy + 1 <= '8') {
        moves.push_back({char(pos.posx - 2), char(pos.posy + 1)});
    }
    if (pos.posx + 2 <= 'h' && pos.posy + 1 <= '8') {
        moves.push_back({char(pos.posx + 2), char(pos.posy + 1)});
    }

    return moves;
}

}
