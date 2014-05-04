#include "NumberGame.h"

#include <sstream>
#include <stdexcept>

#include <cassert>
#include <cstdlib>
#include <ctime>

using std::vector;

NumberGame::NumberGame() {
    for (int i = 0; i < 15; ++i) {
        board.push_back(i + 1);
    }
    board.push_back(0);
}

NumberGame::~NumberGame() {
}

void NumberGame::shuffle() {
    for (int i = 0; i < NumberGame::SIZE; ++i) {
        board.at(i) = i;
    }
    srand(time(0));
    int from, to, temp;
    for (int i = 0; i < 500; ++i) {
        from = rand() % NumberGame::SIZE;
        to = rand() % NumberGame::SIZE;
        if (from == to)
            continue;
        temp = board.at(to);
        board.at(to) = board.at(from);
        board.at(from) = temp;
    }
}

bool NumberGame::move(int number) {
    if (number < 1 || number > 15)
        return false;
    int num_loc = -1;
    for (int i = 0; i < NumberGame::SIZE; ++i) {
        if (board.at(i) == number) {
            num_loc = i;
            break;
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
            if (board.at(loc) == 0) {
                board.at(loc) = number;
                board.at(num_loc) = 0;

                return true;
            }
        }
    }
    return false;
}

bool NumberGame::isFinished() const {
    int next = 1;
    for (int i = 0; i < NumberGame::SIZE; ++i) {
        int num = board.at(i);
        if (num == 0) {
            continue;
        }

        if (num != next) {
            return false;
        } else {
            ++next;
        }
    }
    return true;
}

vector<int> NumberGame::getVals() const {
    return this->board;
}

