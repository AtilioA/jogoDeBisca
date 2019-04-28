#include "IA4Jogadores.h"

tCarta PC4Jogadores1 (tMao *mao, tMonte *monte, tCarta corte, int seteSaiu) {
    return (PC2Jogadores1 (mao, monte, corte, seteSaiu));
}

tCarta PC4Jogadores2 (tMao *mao, tMonte *monte, tCarta corte, int seteSaiu) {
    return (PC2Jogadores2 (mao, monte, corte, seteSaiu));
}

tCarta PC4Jogadores3 (tMao *mao, tMonte *monte, tCarta corte, int seteSaiu) {
    ordenaMao (mao);
    int pontos;
    tCarta jogada, mesa, heley;
    pontos = 0;

    mesa = CartaNoIndice (2, monte);
    if (ETrunfo (mesa, corte)) {
        if (Valor (mesa) == '7') {
            PreencheCarta ('A', Naipe (corte), &heley);
            if (EstaNaMao (Valor (heley), Naipe (heley), *mao)) {
                RetiraDaMao (heley, mao);
                Insere (heley, monte);
                return (heley);
            }
        }
        jogada = PegaCarta (1, *mao);
        RetiraDaMao (jogada, mao);
        Insere (jogada, monte);
        return (jogada);
    }
    //mais alta da mesa
}

tCarta PC4Jogadores4 (tMao *mao, tMonte *monte, tCarta corte, int seteSaiu) {
    ordenaMao (mao);
    int pontos;
    tCarta jogada, mesa;
    pontos = 0;
    mesa = CartaNoIndice (1, monte);
}

tCarta PC4JogadoresAleatorio (tMao *mao, tMonte *monte, tCarta corte, int seteSaiu) {
    return (PC2JogadoresAleatorio (mao, monte, corte, seteSaiu));
}
