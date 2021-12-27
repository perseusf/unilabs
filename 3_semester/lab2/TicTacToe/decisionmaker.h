#pragma once
#include "structures.h"
#include "board.h"
#include "move.h"
#include "sequence.h"
#include "arraysequence.h"

enum {
    WIN_SCORE = 100,
    TIE_SCORE = 0,
    INF = 999999
};

class DecisionMaker {
public:
    Move Minimax(Board board, int boardSize, int depth, int alpha, int beta, int player);
    Move Minimax(Board board, int boardSize, int player);

};
