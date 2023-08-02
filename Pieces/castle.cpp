#include "castle.h"

namespace qtchess {

std::list<position> Castle::Moves() {
    if (!player_info->YourTurn())
        return std::list<position>();

    std::list<position> moves;

    for (char x = pos.posx + 1; x <= 'h'; x++) {
        moves.push_back({x, pos.posy});
    }
    for (char x = pos.posx - 1; x >= 'a'; x--) {
        moves.push_back({x, pos.posy});
    }
    for (char y = pos.posy + 1; y <= '8'; y++) {
        moves.push_back({pos.posx, y});
    }
    for (char y = pos.posy - 1; y >= '1'; y--) {
        moves.push_back({pos.posx, y});
    }

    return moves;
}

}
