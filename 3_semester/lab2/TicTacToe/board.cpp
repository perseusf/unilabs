#include "board.h"
#include "sequence.h"
#include "arraysequence.h"

void Board::Initialize(int boardSize, int len_to_win) {
    this->boardSize = boardSize;
    this->len_to_win = len_to_win;
    for(int i = 0; i < boardSize*boardSize; i++)
        board->Append(0);
}

void Board::SetPlayerToCell(int id, int player) {
    board->Set(id, player);
}


int Board::GetPlayerFromCell(int id) {
    return board->Get(id);
}


void Board::UnsetPlayerFromCell(int id) {
    board->Set(id, EMPTY);
}


int Board::EvaluateCondition(int player) {

    int count;
    //check MAIN diagonals
    for (int i = 0; i < (boardSize - len_to_win + 1) * boardSize; i += boardSize) {
        for (int j = 0; j < boardSize - len_to_win + 1; ++j) {
            count = 0;
            for (int k = 0; k < len_to_win; ++k) {
                if(board->Get(i + j + (boardSize + 1) * k) == player)
                    ++count;
            }
            if(count == len_to_win)
                return (board->Get(i + j + (boardSize + 1)) == player) ? WIN : LOSE;
        }
    }

    //check NOTMAIN diagonals
    for (int i = len_to_win - 1; i < (boardSize - len_to_win + 1) * boardSize; i += boardSize) {
        for (int j = 0; j < boardSize - len_to_win + 1; ++j) {
            count = 0;
            for (int k = 0; k < len_to_win; ++k) {

                if(board->Get(i + j + (boardSize - 1) * k) == player)
                    ++count;
            }
            if(count == len_to_win)
                return (board->Get(i + j + (boardSize - 1)) == player)? WIN : LOSE;
        }
    }

    //check columns
    for (int i = 0; i < boardSize*boardSize; i += boardSize) { //i пробегает по верхней строке
        for (int j = 0; j < boardSize - len_to_win + 1; ++j) {
            count = 0;
            for (int k = 0; k < len_to_win; ++k) {
                if(board->Get(i + j + k) == player) {
                    ++count;
                }
            }
            if(count == len_to_win) {
                return (board->Get(i + j) == player)? WIN : LOSE;
            }
        }
    }

    //check strings
    for (int i = 0; i < (boardSize - len_to_win + 1) * boardSize; i += boardSize) {
        for (int j = 0; j < boardSize; ++j) {
            count = 0;
            for (int k = 0; k < len_to_win; ++k) {
                if(board->Get(i + j + boardSize * k) == player)
                    ++count;
            }
            if(count == len_to_win) {
                return (board->Get(i + j + boardSize) == player)? WIN : LOSE;
            }
        }
    }


    //if all the cells are occupied => end game
    for(int i = 0; i < boardSize*boardSize; i++){
        if (board->Get(i) == EMPTY){
            return PLAY;
        }
    }

    // if we're here, it means no one has won
    return TIE;
}
