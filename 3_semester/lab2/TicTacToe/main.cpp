#include "game.h"
#include "sequence.h"
#include "arraysequence.h"
#include "listsequence.h"
#include <iostream>
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Game game;
    game.show();
    return app.exec();
}
