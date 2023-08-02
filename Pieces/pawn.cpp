#include "pawn.h"

namespace qtchess {

std::list<position> Pawn::Moves() {
    if (!player_info->YourTurn())
        return std::list<position>();

    std::list<position> moves;
    if (player_info->IsBottom()) {
        moves.push_back({pos.posx, char(pos.posy + 1)});
        if (!is_moved)
            moves.push_back({pos.posx, char(pos.posy + 2)});
    }
    else {
        moves.push_back({pos.posx, char(pos.posy - 1)});
        if (!is_moved)
            moves.push_back({pos.posx, char(pos.posy - 2)});
    }

    return moves;
}

}
