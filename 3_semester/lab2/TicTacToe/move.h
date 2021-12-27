#ifndef MOVE_H
#define MOVE_H

#include "sequence.h"
#include "arraysequence.h"

class Move {
public:
    Move();
    Move(int s);
    int score;
    int location;

};

#endif // MOVE_H
