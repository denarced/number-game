#include "NumberGame.h"

#include <cstdlib>
#include <ctime>

NumberGame::NumberGame() {
    board = (int *)malloc(16 * sizeof(int));
    for (int i = 0; i < 15; ++i) {
        board[i] = i + 1;
    }
    board[15] = 0;
}

NumberGame::~NumberGame() {
    free(board);
}

void NumberGame::shuffle() {
    for (int i = 0; i < 16; ++i)
        *(board + i) = i;
    srand(time(0));
    int from, to, temp;
    for (int i = 0; i < 500; ++i) {
        from = rand() % 16;
        to = rand() % 16;
        if (from == to)
            continue;
        temp = *(board + to);
        *(board + to) = *(board + from);
        *(board + from) = temp;
    }
}

bool NumberGame::move(int number) {
    if (number < 1 || number > 15)
        return false;
    int num_loc, zero_loc;
    for (int i = 0; i < 16; ++i) {
        if (*(board + i) == number)
            num_loc = i;
        if (*(board + i) == 0)
            zero_loc = i;
    }
    bool top, bottom, right, left;
    top = bottom = right = left = true;
    if (zero_loc < 4)
        top = false;
    if (zero_loc > (15 - 4))
        bottom = false;
    if (zero_loc % 4 == 0)
        left = false;
    if (zero_loc % 4 == 3)
        right = false;
    bool numIsAcceptable = false;
    if (top) {
        if (zero_loc - 4 == num_loc)
            numIsAcceptable = true;
    } else if (right) {
        if (zero_loc + 1 == num_loc)
            numIsAcceptable = true;
    } else if (bottom) {
        if (zero_loc + 4 == num_loc)
            numIsAcceptable = true;
    } else if (left)
        if (zero_loc - 1 == num_loc)
            numIsAcceptable = true;
    if (!numIsAcceptable)
        return false;
    *(board + zero_loc) = number;
    *(board + num_loc) = 0;
    return false;
}

bool NumberGame::isFinished() const {
    for (int i = 0; i < 15; ++i)
        if (board[i] != (i + 1))
            return false;
    return true;
}

int *NumberGame::getVals() const {
    return this->board;
}

NumberGame::NumberGame(NumberGame &rhs) {
    board = (int *) malloc(16 * sizeof(int));
    for (int i = 0; i < 15; ++i) {
        board[i] = i + 1;
    }
    board[15] = 0;
}
