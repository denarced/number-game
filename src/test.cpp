#include <iostream>
#include <sstream>

#include "NumberGame.h"
#include "TestException.h"

using namespace std;

void testShuffle() {
    NumberGame numberGame;
    numberGame.sekoita();

    for (int i = 0; i <= 15; ++i) {
        int *numbers = numberGame.getVals();
        bool found = false;
        for (int numIndex = 1; numIndex <= 15; ++numIndex) {
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

int main() {
    try {
        testShuffle();
    } catch (const TestException& e) {
        cout << "Test error: " << e.getMessage() << endl;
        cout << "File name: " << e.getFilename() << endl;
        cout << "Line number: " << e.getLineNumber() << endl;
        return 1;
    }
    return 0;
}
