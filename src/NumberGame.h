#ifndef __NUMBERGAME_H
#define __NUMBERGAME_H

class NumberGame {
protected:
    int *m_arvo;
public:
    NumberGame();
    NumberGame(NumberGame &alkuperainen);
    ~NumberGame();
    /**
     * Shuffle the game.
     *
     * Postcondition: array contains numbers 1 - 15 and an empty one.
     */
    void shuffle();
    /*
     * Move number to a free square if possible.
     *
     * Precondition: 1 <= numero && numbero <= 15.
     * Postcondition: if zero is next to the numero, they have swapped places.
     *                if not => return false.
     */
    bool move(int numero);
    /*
     * Is the game over.
     *
     * Postcondition: the numbers are in order.
     */
    bool isFinished() const;
    int *getVals() const;
};

#endif // __NUMBERGAME_H
