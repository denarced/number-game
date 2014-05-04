#include <iomanip>
#include <iostream>
#include <sstream>

#include "NumberGame.h"
#include "TestException.h"

using namespace std;

void testShuffle() {
    NumberGame numberGame;
    numberGame.shuffle();

    for (int i = 0; i < NumberGame::SIZE; ++i) {
        vector<int> numbers = numberGame.getVals();
        bool found = false;
        for (int numIndex = 0; numIndex <= 15; ++numIndex) {
            if (numbers.at(numIndex) == i) {
                found = true;
                break;
            }
        }

        if (!found) {
            std::stringstream ss;
            ss << "Can't find number " << i << ".";
            throw TestException(ss.str(), __FILE__, __LINE__);
        }
    }
}

void testCopyConstructorAndBoardValues() {
    NumberGame first;
    first.shuffle();
    NumberGame second(first);

    vector<int> firstBoard = first.getVals();
    vector<int> secondBoard = second.getVals();

    for (int i = 0; i < NumberGame::SIZE; ++i) {
        if (firstBoard.at(i) != secondBoard.at(i)) {
            throw TestException("Copy ctor does not duplicate board.", __FILE__, __LINE__);
        }
    }
}

void testFirstMove() {
    NumberGame numberGame;
    numberGame.move(1);
    vector<int> board = numberGame.getVals();

    if (board[0] != 1) {
        throw TestException("1 should have been moved.", __FILE__, __LINE__);
    }
}

void testMovingAll() {
    NumberGame numberGame;
    int moves[] = {
        15, 14, 13, 9,
        10, 11, 12, 8,
        7, 6, 5, 1,
        2, 3, 4};
    for (size_t i = 0; i < sizeof(moves) / sizeof(*moves); ++i) {
        const int moved = moves[i];
        bool success = numberGame.move(moved);
        if (!success) {
            std::stringstream ss;
            ss << "Move failed: " << moved << ".";
            throw TestException(ss.str(), __FILE__, __LINE__);
        }
    }

    vector<int> board = numberGame.getVals();
    int expected[] = {
        2, 3, 4, 0,
        1, 5, 6, 7,
        10, 11, 12, 8,
        9, 13, 14, 15
    };
    for (size_t i = 0; i < sizeof(expected) / sizeof(*expected); ++i) {
        if (board[i] != expected[i]) {
            std::stringstream ss;
            ss << "Unexpected value: " << i << "." << endl;
            ss << "Board:" << endl;
            for (int bInx = 0; bInx < NumberGame::SIZE; ++bInx) {
                ss << std::setw(3);
                ss << board[bInx];
                if (bInx % 4 == 3) {
                    ss << endl;
                }
            }
            throw TestException(ss.str(), __FILE__, __LINE__);
        }
    }
}

void testIsFinishedWithoutShuffle() {
    NumberGame numberGame;
    if (!numberGame.isFinished()) {
        throw TestException("testIsFinishedWithoutShuffle failed.", __FILE__, __LINE__);
    }
}


void testIsFinishedAfterShuffle() {
    NumberGame numberGame;
    numberGame.shuffle();
    if (numberGame.isFinished()) {
        throw TestException("testIsFinishedAfterShuffle failed.", __FILE__, __LINE__);
    }
}

void testIsFinishedWithEmptyNotInCorner() {
    NumberGame numberGame;
    numberGame.move(15);
    if (!numberGame.isFinished()) {
        throw TestException("testIsFinishedWithEmptyNotInCorner failed.", __FILE__, __LINE__);
    }
}

int main() {
    try {
        testShuffle();
        testCopyConstructorAndBoardValues();
        testFirstMove();
        testMovingAll();
        testIsFinishedWithoutShuffle();
        testIsFinishedAfterShuffle();
        testIsFinishedWithEmptyNotInCorner();
    } catch (const TestException& e) {
        cout << "Test error: " << e.getMessage() << endl
            << "File name: " << e.getFilename() << endl
            << "Line number: " << e.getLineNumber() << endl;
        return 1;
    } catch (const std::exception& e) {
        cout << "std::exception: " << e.what() << endl;
        return 1;
    } catch (...) {
        cout << "Really nasty: ... caught." << endl;
        return 1;
    }
    return 0;
}
