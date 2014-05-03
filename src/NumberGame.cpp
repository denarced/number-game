#include "NumberGame.h"

#include <cstdlib>
#include <ctime>

NumberGame::NumberGame() {
    m_arvo = (int *)malloc(16 * sizeof(int));
    for (int i = 0; i < 15; ++i) {
        m_arvo[i] = i + 1;
    }
    m_arvo[15] = 0;
}

NumberGame::~NumberGame() {
    free(m_arvo);
}

void NumberGame::sekoita() {
    for (int i = 0; i < 16; ++i)
        *(m_arvo + i) = i;
    srand(time(0));
    int mista, mihin, temp;
    for (int i = 0; i < 500; ++i) {
        mista = rand() % 16;
        mihin = rand() % 16;
        if (mista == mihin)
            continue;
        temp = *(m_arvo + mihin);
        *(m_arvo + mihin) = *(m_arvo + mista);
        *(m_arvo + mista) = temp;
    }
}

bool NumberGame::siirto(int numero) {
    if (numero < 1 || numero > 15)
        return false;
    int num_loc, zero_loc;
    for (int i = 0; i < 16; ++i) {
        if (*(m_arvo + i) == numero)
            num_loc = i;
        if (*(m_arvo + i) == 0)
            zero_loc = i;
    }
    bool top, bottom, right, left;
    top = bottom = right = left = true;
    if (zero_loc < 4)
        top = false;
    if (zero_loc > (15 - 4))
        bottom = false;
    if (zero_loc % 4 == 0)
        left = false;
    if (zero_loc % 4 == 3)
        right = false;
    bool numIsAcceptable = false;
    if (top) {
        if (zero_loc - 4 == num_loc)
            numIsAcceptable = true;
    } else if (right) {
        if (zero_loc + 1 == num_loc)
            numIsAcceptable = true;
    } else if (bottom) {
        if (zero_loc + 4 == num_loc)
            numIsAcceptable = true;
    } else if (left)
        if (zero_loc - 1 == num_loc)
            numIsAcceptable = true;
    if (!numIsAcceptable)
        return false;
    *(m_arvo + zero_loc) = numero;
    *(m_arvo + num_loc) = 0;
    return false;
}

bool NumberGame::isFinished() const {
    for (int i = 0; i < 15; ++i)
        if (m_arvo[i] != (i + 1))
            return false;
    return true;
}

int *NumberGame::getVals() const {
    return this->m_arvo;
}

NumberGame::NumberGame(NumberGame &alkuperainen) {
    // sis��nrakennettu tekisi n�in :
    // m_arvo = alkuper�inen.m_arvo;
    m_arvo = (int *) malloc(16 * sizeof(int));
    for (int i = 0; i < 15; ++i) {
        m_arvo[i] = i + 1;
    }
    m_arvo[15] = 0;
}
