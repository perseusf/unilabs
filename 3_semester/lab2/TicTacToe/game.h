#pragma once

#include "board.h"
#include "decisionmaker.h"
#include "currentplayer.h"
#include "sequence.h"
#include "arraysequence.h"
#include <QDialog>
#include <QPainter>
#include <vector>

class Game : public QDialog {
    Q_OBJECT

public:
    Game(QWidget *parent = 0);
    ~Game();

private:
    bool userTurn;
    int player;
    int boardSize;
    int len_to_win;

    QPainter *painter;
    std::vector<QRect> cells;

    void paintEvent(QPaintEvent *e);
    void mousePressEvent(QMouseEvent *e);

    Sequence<int> *displayBoard = (Sequence<int> *) new ArraySequence<int>;
    CurrentPlayer currentplayer;
    DecisionMaker decisionmaker;
    Board board;

    int EvaluateGame(Board board);
    void Reinitialize();
    void Tie();
    void Lost();
    void Won();

    void MoveMaker();
};


