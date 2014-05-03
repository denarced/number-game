#ifndef __NUMBERGAME_H
#define __NUMBERGAME_H

class NumberGame {
public:
    // CREATORS
    NumberGame();
    NumberGame(NumberGame &rhs);
    ~NumberGame();

    // MUTATORS
    /**
     * Shuffle the game.
     *
     * Postcondition: array contains numbers 1 - 15 and an empty one.
     */
    void shuffle();

    /**
     * Move number to a free square if possible.
     *
     * Precondition: 1 <= number && number <= 15.
     * Postcondition: if zero is next to the number, they have swapped places.
     *                if not => return false.
     */
    bool move(int number);

    // ACCESSORS
    /**
     * Is the game over.
     *
     * Postcondition: the numbers are in order.
     */
    bool isFinished() const;
    int *getVals() const;

    // CONSTANTS
    const static int SIZE = 16;

protected:
    int *board;
};

#endif // __NUMBERGAME_H
