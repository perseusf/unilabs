#include "decisionmaker.h"
#include "board.h"

Move DecisionMaker::Minimax(Board board, int boardSize, int depth, int alpha, int beta, int player) {

    switch(board.EvaluateCondition(player)) {
        case WIN: return WIN_SCORE;
        case LOSE: return -WIN_SCORE;
        case TIE: return TIE_SCORE;
    }

    if (player == 1) {
        Move bestMove;
        bestMove.score = -INF;
        for(int i = 0; i < boardSize*boardSize; i++) {
            if(board.GetPlayerFromCell(i) == EMPTY) {
                Move move;
                move.location = i;
                board.SetPlayerToCell(i, player);
                move.score = Minimax(board, boardSize, depth +1, alpha, beta, player).score;
                bestMove.score = std::max(bestMove.score, move.score);
                alpha = std::max(alpha, bestMove.score);
                board.UnsetPlayerFromCell(i);
                std::cout << "beta1 = " << beta << std::endl;
                std::cout << "alpha1 = " << alpha << std::endl;
                if(beta <= alpha){
                    break;
                }
            }
        }
        return bestMove;
    } else {
        Move bestMove;
        bestMove.score = INF;

        for(int i = 0; i < boardSize*boardSize; i++) {
            if(board.GetPlayerFromCell(i) == EMPTY) {
                Move move;

                move.location = i;
                board.SetPlayerToCell(i, player);
                move.score = Minimax(board, boardSize, depth +1, alpha, beta, player).score;
                bestMove.score = std::min(bestMove.score, move.score);
                beta = std::min(beta, bestMove.score);
                board.UnsetPlayerFromCell(i);
                std::cout << "beta2 = " << beta << std::endl;
                std::cout << "alpha2 = " << alpha << std::endl;
                if(beta <= alpha) {

                    break;
                }

            }
        }
        return bestMove;
    }
}

Move DecisionMaker::Minimax(Board board, int boardSize, int player) {

    switch(board.EvaluateCondition(player)) {
    case WIN: return WIN_SCORE;
    case LOSE: return -WIN_SCORE;
    case TIE: return TIE_SCORE;
    }

    Move bestMove;
    bestMove.score = -INF;

    for(int i = 0; i < boardSize*boardSize; i++) {
        if(board.GetPlayerFromCell(i) == EMPTY) {
            Move move;
            move.location = i;
            board.SetPlayerToCell(i, player);
            move.score = -Minimax(board, boardSize, -player).score;
            board.UnsetPlayerFromCell(i);
            if(move.score > bestMove.score)
                bestMove = move;
        }
    }
    return bestMove;

}

