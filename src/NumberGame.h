#ifndef __NUMBERGAME_H
#define __NUMBERGAME_H

#include <vector>

class NumberGame {
public:
    // CREATORS
    NumberGame();
    ~NumberGame();

    // MUTATORS
    /**
     * Shuffle the game.
     *
     * Postcondition: array contains numbers 1 - (SIZE - 1) and an empty one.
     */
    void shuffle();

    /**
     * Move number to a free square if possible.
     *
     * Precondition: 1 <= number && number < SIZE.
     * Postcondition: if zero is next to the number, they have swapped places.
     *                if not => return false.
     */
    bool move(int number);
    void setAlmostInOrder();

    // ACCESSORS
    /**
     * Is the game over.
     *
     * Postcondition: the numbers are in order.
     */
    bool isFinished() const;
    std::vector<int> getVals() const;

    // CONSTANTS
    const static int SIZE = 16;

private:
    std::vector<int> board;
};

#endif // __NUMBERGAME_H
