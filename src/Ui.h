#ifndef __UI_H
#define __UI_H

#include <string>

#include "NumberGame.h"

class Ui {
public:
    // CREATORS
    Ui(NumberGame& numberGame);
    virtual ~Ui();

    // ACCESSORS
    void printBoard() const;
    bool shouldQuit() const;

    // MUTATORS
    void nextMove();

private:
    std::string asVisibleString(int val) const;

    NumberGame& numberGame;
    bool quit;
};

#endif // __UI_H
