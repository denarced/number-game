#include "NumberGame.h"

int main(int, char **) {
    NumberGame test;
    test.shuffle();
    test.move(1);
    test.move(3);
    test.move(5);
    test.move(7);
    test.move(9);
    test.move(11);
    test.move(13);
    test.move(15);

    return 0;
}
