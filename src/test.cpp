#include <iostream>
#include <sstream>

#include "NumberGame.h"
#include "TestException.h"

using namespace std;

void testShuffle() {
    NumberGame numberGame;
    numberGame.shuffle();

    for (int i = 0; i <= 15; ++i) {
        int *numbers = numberGame.getVals();
        bool found = false;
        for (int numIndex = 0; numIndex <= 15; ++numIndex) {
            if (numbers[numIndex] == i) {
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

void testCopyConstructor() {
    NumberGame first;
    NumberGame second(first);
    if (first.getVals() == second.getVals()) {
        throw TestException("Objects share internal pointer.", __FILE__, __LINE__);
    }
}

void testCopyConstructorAndBoardValues() {
    NumberGame first;
    first.shuffle();
    NumberGame second(first);

    int *firstBoard = first.getVals();
    int *secondBoard = second.getVals();

    for (int i = 0; i < 16; ++i) {
        if (firstBoard[i] != secondBoard[i]) {
            throw TestException("Copy ctor does not duplicate board.", __FILE__, __LINE__);
        }
    }
}

int main() {
    try {
        testShuffle();
        testCopyConstructor();
        testCopyConstructorAndBoardValues();
    } catch (const TestException& e) {
        cout << "Test error: " << e.getMessage() << endl;
        cout << "File name: " << e.getFilename() << endl;
        cout << "Line number: " << e.getLineNumber() << endl;
        return 1;
    }
    return 0;
}
