#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H
#include "player.h"
#include "Analyzer/analyzer.h"

namespace qtchess {

class ComputerPlayer : public Player, protected Analyzer {
public:
    ComputerPlayer();
};

}

#endif // COMPUTERPLAYER_H
