#ifndef PLAYER_H
#define PLAYER_H
#include <QObject>

namespace qtchess {

class Player : public QObject {
    Q_OBJECT

public:
    Player(bool white, bool yourTurn, bool bottom) : white(white)
                                                   , yourTurn(yourTurn)
                                                   , bottom(bottom)
    {}
    virtual void move();
    void setYourTurn();
    bool isWhite() const noexcept;
    bool isYourTurn() const noexcept;
    bool isBottom() const noexcept;
    void setBottom(bool isBottom);

signals:
    void madeMove();

private:
    bool white;
    bool yourTurn;
    bool bottom;
};

}

#endif // PLAYER_H
