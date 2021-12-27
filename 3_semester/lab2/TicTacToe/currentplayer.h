#ifndef CURRENTPLAYER_H
#define CURRENTPLAYER_H

#include "sequence.h"
#include "arraysequence.h"

class CurrentPlayer {
public:
    CurrentPlayer();

    int player;
    void TurnToNextPlayer();
};

#endif // CURRENTPLAYER_H
