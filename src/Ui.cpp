#include "Ui.h"

#include <iomanip>
#include <iostream>
#include <sstream>

#include <cassert>

using std::cin;
using std::cout;
using std::endl;
using std::string;

Ui::Ui(NumberGame& numberGame):
    numberGame(numberGame),
    quit(false) {
}

Ui::~Ui() {}

void Ui::printBoard() const {
    string templ =
        " -----------\n"
        "|nn|nn|nn|nn|\n"
        "|nn|nn|nn|nn|\n"
        "|nn|nn|nn|nn|\n"
        "|nn|nn|nn|nn|\n"
        " -----------";
    for (int val: this->numberGame.getVals()) {
        string s = this->asVisibleString(val);
        assert(s.size() == 2);
        size_t pos = templ.find("nn");
        assert(pos >= 0);
        templ = templ.replace(pos, s.size(), s);
    }

    cout << templ << endl;
}

string Ui::asVisibleString(int val) const {
    if (val == 0) {
        return "  ";
    } else {
        std::stringstream ss;
        ss << std::setw(2) << val;
        return ss.str();
    }
}

bool Ui::shouldQuit() const {
    return this->quit;
}

void Ui::nextMove() {
    while (true) {
        cout << "Next move (or q to quit): ";
        string line;
        getline(cin, line);
        if (line == "q") {
            this->quit = true;
            break;
        } else if (line == "endgame") {
            this->numberGame.setAlmostInOrder();
            break;
        } else {
            std::istringstream iss(line);
            int num = 0;
            iss >> num;
            bool success = true;
            if (0 < num && num < 16) {
                success = this->numberGame.move(num);
            } else {
                success = false;
            }

            if (success) {
                break;
            } else {
                cout << "Invalid move, try again" << endl;
            }
        }
    }
}

