class NumberGame {
protected:
    /*
     *  t�nne talletetaan numerotaulukko
     */
    int *m_arvo;
public:
    NumberGame();
    /*
     *  copy-constructor
     */
    NumberGame(NumberGame &alkuperainen);
    ~NumberGame();
    /* sekoittaa pelin
     * esiehto : true
     * j�lkiehto : taulukko sis�lt�� luvut 1-15 ja tyhj�n
     */
    void sekoita();
    /*
     *  Siirt�� yksitt�isen numeron vapaaseen ruutuun jos mahdollista
     *  Esiehto : 1 <= numero && numero <= 15
     *  J�lkiehto : jos numeron vieress� oli 0, ne ovat vaihtaneet paikkaa => return true
     *            : joe ei => return false
     */
    bool siirto(int numero);
    /*
     *  testaa onko peli lopussa
     *  esiehto : true
     *  j�lkiehto : numerot ovat j�rjestyksess�
     */
    bool isFinished() const;
    /*
     *  saantifunktio eli "getteri"
     */
    int *getVals() const;
};
