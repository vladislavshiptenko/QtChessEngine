#include "bishop.h"

namespace qtchess {

std::list<position> Bishop::Moves() {
    if (!player_info->YourTurn())
        return std::list<position>();

    std::list<position> moves;

    for (char i = 1; pos.posx - i >= 'a' && pos.posy - i >= '0'; i++) {
        moves.push_back({char(pos.posx - i), char(pos.posy - i)});
    }
    for (char i = 1; pos.posx - i >= 'a' && pos.posy + i <= '8'; i++) {
        moves.push_back({char(pos.posx - i), char(pos.posy + i)});
    }
    for (char i = 1; pos.posx + i <= 'h' && pos.posy - i >= '0'; i++) {
        moves.push_back({char(pos.posx + i), char(pos.posy - i)});
    }
    for (char i = 1; pos.posx + i <= 'h' && pos.posy + i <= '8'; i++) {
        moves.push_back({char(pos.posx + i), char(pos.posy + i)});
    }

    return moves;
}

}
