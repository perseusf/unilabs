#pragma once
#include "structures.h"
#include "sequence.h"
#include "arraysequence.h"
#include "arraysequence.cpp"

enum {
    X = 1,
    O = -1,
    EMPTY = 0,
    WIN = 6,
    LOSE = -6,
    TIE = 0,
    PLAY = 1,
    END = -1
};

class Board {
public:

    Sequence<int>* board = (Sequence<int> *) new ArraySequence<int>;
    void Initialize(int boardSize, int len_to_win);
    void SetPlayerToCell(int id, int player);
    void UnsetPlayerFromCell(int id);
    int GetPlayerFromCell(int id);
    int EvaluateCondition(int player);

private:
    int boardSize;
    int len_to_win;
};

extern Board board;
