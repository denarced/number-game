#include "NumberGame.h"

int main(int, char **) {
    NumberGame test;
    test.sekoita();
    test.siirto(1);
    test.siirto(3);
    test.siirto(5);
    test.siirto(7);
    test.siirto(9);
    test.siirto(11);
    test.siirto(13);
    test.siirto(15);

    return 0;
}
