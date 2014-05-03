#include <iostream>
#include "Numeropeli.h"

using namespace std;

int main(int, char **) {
    Numeropeli test;
    /*
    if( test.siirto(11))
        cerr << "Virhe 11" << endl;
    if( !test.siirto(15))
        cerr << "Virhe 15" << endl;
    if( !test.siirto(12))
        cerr << "Virhe 12" << endl;
    */
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
