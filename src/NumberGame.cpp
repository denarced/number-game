#include "NumberGame.h"

#include <sstream>
#include <stdexcept>

#include <cstdlib>
#include <ctime>

NumberGame::NumberGame() {
    board = (int *)malloc(NumberGame::SIZE * sizeof(int));
    for (int i = 0; i < 15; ++i) {
        board[i] = i + 1;
    }
    board[15] = 0;
}

NumberGame::~NumberGame() {
    free(board);
}

void NumberGame::shuffle() {
    for (int i = 0; i < NumberGame::SIZE; ++i)
        *(board + i) = i;
    srand(time(0));
    int from, to, temp;
    for (int i = 0; i < 500; ++i) {
        from = rand() % NumberGame::SIZE;
        to = rand() % NumberGame::SIZE;
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
    int num_loc = -1;
    for (int i = 0; i < NumberGame::SIZE; ++i) {
        if (*(board + i) == number) {
            num_loc = i;
        }
    }
    if (num_loc < 0) {
        std::stringstream ss;
        ss << "Internal error " << __FILE__ << " " << __LINE__ << ".";
        throw std::runtime_error(ss.str());
    }

    int zeroLocations[4] = {
        num_loc + 1,
        num_loc + 4,
        num_loc - 1,
        num_loc - 4
    };

    for (int i = 0; i < 4; ++i) {
        int loc = zeroLocations[i];
        if (0 <= loc && loc < NumberGame::SIZE) {
            if (board[loc] == 0) {
                *(board + loc) = number;
                *(board + num_loc) = 0;

                return true;
            }
        }
    }
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
    board = (int *) malloc(NumberGame::SIZE * sizeof(int));
    for (int i = 0; i < NumberGame::SIZE; ++i) {
        board[i] = rhs.board[i];
    }
}
