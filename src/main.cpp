#include "NumberGame.h"
#include "Ui.h"

int main() {
    NumberGame numberGame;
    numberGame.shuffle();
    Ui ui(numberGame);

    while (!numberGame.isFinished()) {
        ui.printBoard();
        ui.nextMove();
        if (ui.shouldQuit()) {
            break;
        }
    }

    // Show the board if the game was "won"
    // Don't if the game was aborted with "q"
    if (numberGame.isFinished()) {
        ui.printBoard();
    }
    return 0;
}
