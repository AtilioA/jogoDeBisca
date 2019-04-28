#include "IA4Jogadores.h"

tCarta PC4Jogadores1 (tMao *mao, tMonte *monte, tCarta corte, int seteSaiu) {
    return (PC2Jogadores1 (mao, monte, corte, seteSaiu));
}

tCarta PC4Jogadores2 (tMao *mao, tMonte *monte, tCarta corte, int seteSaiu);

tCarta PC4Jogadores3 (tMao *mao, tMonte *monte, tCarta corte, int seteSaiu);

tCarta PC4Jogadores4 (tMao *mao, tMonte *monte, tCarta corte, int seteSaiu);

tCarta PC4JogadoresAleatorio (tMao *mao, tMonte *monte, tCarta corte, int seteSaiu) {
    return (PC2JogadoresAleatorio (mao, monte, corte, seteSaiu));
}
