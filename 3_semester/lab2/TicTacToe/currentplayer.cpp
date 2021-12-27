#include "currentplayer.h"

CurrentPlayer::CurrentPlayer() {
    player = 1;
}

void CurrentPlayer::TurnToNextPlayer() {
    player *= -1;
}
