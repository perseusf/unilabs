#include "game.h"
#include "board.h"
#include "decisionmaker.h"
#include "sequence.h"
#include "arraysequence.h"
#include "currentplayer.h"
#include <iostream>
#include <QPainter>
#include <QMouseEvent>
#include <QMessageBox>

Game::Game(QWidget *parent) : QDialog(parent) {

    std::cout << "ENTER NUMBER OF CELLS: ";
    std::cin >> boardSize;

    std::cout << std::endl << "ENTER LENGHT TO WIN: ";
    std::cin >> len_to_win;

    this->setWindowTitle("XO");
    this->setFixedSize(boardSize*30, boardSize*30);
    QSize size(30, 30);
    for(int i = 0; i < boardSize; i++) {
        for(int k = 0; k < boardSize; k++) {
            displayBoard->Append(0);
            board.board->Append(0);
            cells.push_back(QRect(QPoint(i*30, k*30), size));
        }
    }
    board.Initialize(boardSize, len_to_win);
    player = 1;
}

Game::~Game() {

}

void Game::paintEvent(QPaintEvent *e) {
    painter = new QPainter(this);

    painter->fillRect(this->rect(), QColor(200, 200, 200));

    QPen borderPen(Qt::white);
    borderPen.setWidth(1);

    painter->setPen(borderPen);
    painter->drawRects(&cells[0], boardSize*boardSize);

    for(int i = 0; i < boardSize*boardSize; i++) {
        QString path;
        switch(displayBoard->Get(i)) {
        case 0: path = "";
            break;
        case 1: path = ":/images/X.png";
            break;
        case -1: path = ":/images/O.png";
            break;
        }
        painter->drawPixmap(cells[i].x()+10, cells[i].y()+10,
                           cells[i].width()-20, cells[i].height()-20,
                           QPixmap(path));
    }
    painter->end();
}

void Game::mousePressEvent(QMouseEvent *e) {
    for(int i = 0; i < boardSize*boardSize; i++) {
        if(cells[i].contains(e->pos()) && displayBoard->Get(i) == 0) {

            if(EvaluateGame(board) == PLAY) {
                board.SetPlayerToCell(i, currentplayer.player);
                displayBoard->Set(i, currentplayer.player);
                QWidget::update();
            }

            if(EvaluateGame(board) == WIN) {
                if(currentplayer.player == player)
                    Won();
                else
                    Lost();
                return;
            }

            if(EvaluateGame(board) == LOSE) {
                if(currentplayer.player == player)
                    Lost();
                else
                    Won();
                return;
            }

            if(EvaluateGame(board) == TIE) {
                Tie();
                return;
            }

            if(EvaluateGame(board) == PLAY) {
                currentplayer.TurnToNextPlayer();

                MoveMaker();
                QWidget::update();
            }

            if(EvaluateGame(board) == WIN) {
                if(currentplayer.player == player)
                    Won();
                else
                    Lost();
                return;
            }

            if(EvaluateGame(board) == LOSE) {
                if(currentplayer.player == player)
                    Lost();
                else
                    Won();
                return;
            }

            if(EvaluateGame(board) == TIE) {
                Tie();
                return;
            }

            if(EvaluateGame(board) == PLAY) {

                currentplayer.TurnToNextPlayer();
                return;
            }

            break;
        }
    }
}

void Game::Tie() {
    QMessageBox tie;
    tie.setWindowTitle("Tic Tac Toe");
    tie.setText("Let's play one more time!");
    tie.setFixedSize(400, 400);
    tie.exec();
    Reinitialize();
}

void Game::Lost() {
    QMessageBox lose;
    lose.setWindowTitle("Tic Tac Toe");
    lose.setText("Unfortunately, you lost! =(");
    lose.setFixedSize(400, 400);
    lose.exec();
    Reinitialize();
}

void Game::Won() {
    QMessageBox win;
    win.setWindowTitle("Tic Tac Toe");
    win.setText("You won! =)");
    win.setFixedSize(400, 400);
    win.exec();
    Reinitialize();
}

int Game::EvaluateGame(Board board) {
    return board.EvaluateCondition(currentplayer.player);
}

void Game::Reinitialize() {
    board.Initialize(boardSize, len_to_win);
    currentplayer.player = X;
    for(int i = 0; i < boardSize*boardSize; i++) {
        displayBoard->Set(i, EMPTY);
        board.board->Set(i, EMPTY);
    }
}

void Game::MoveMaker() {
//    Move bestMove = decisionmaker.Minimax(board, boardSize, 0, -INF, INF, currentPly.player);
    Move bestMove = decisionmaker.Minimax(board, boardSize, currentplayer.player);

    board.SetPlayerToCell(bestMove.location, currentplayer.player);
    displayBoard->Set(bestMove.location, currentplayer.player);
}
