#include "../include/IA4Jogadores.h"

int CartasIguais (tCarta carta1, tCarta carta2) {
    return ((Valor (carta1) == Valor (carta2)) && (Naipe (carta1) == Naipe (carta2)));
}

tCarta PC4Jogadores1 (tMao *mao, tMonte *monte, tCarta corte, int seteSaiu) {
    return (PC2Jogadores1 (mao, monte, corte, seteSaiu));
}

tCarta PC4Jogadores2 (tMao *mao, tMonte *monte, tCarta corte, int seteSaiu) {
    OrdenaMao (mao);
    //OrdenaMesa;
    int pontos;
    tCarta jogada, mesa;
    pontos = 0;

    mesa = CartaNoIndice (1, monte);
    if (pontos >= 10) {
        for (int i = 1; i <= TamanhoMao (*mao); i ++) {
            jogada = PegaCarta (i, *mao);
            if ((ETrunfo (jogada, corte)) && (! (ETrunfo (mesa, corte)))) {
                RetiraDaMao (jogada, mao);
                Insere (jogada, monte);
                return (jogada);
            }
        }
    }
    return (PC2Jogadores2 (mao, monte, corte, seteSaiu));
}

tCarta PC4Jogadores3 (tMao *mao, tMonte *monte, tCarta corte, int seteSaiu) {
    OrdenaMao (mao);
    //OrdenaMesa;
    int pontos;
    tCarta jogada, mesa, heley;
    pontos = 0;

    mesa = CartaNoIndice (1, monte);
    if (CartasIguais (mesa, CartaNoIndice (2, monte))) {
        if (ETrunfo (mesa, corte)) {
            if (Valor (mesa) == '7') {
                tCarta heley = PreencheCarta ('A', Naipe (corte));
                if (EstaNaMao (Valor (heley), Naipe (heley), *mao)) {
                    RetiraDaMao (heley, mao);
                    Insere (heley, monte);
                    return (heley);
                }
            }
            else if (pontos >= 10) {
                for (int i = 1; i <= TamanhoMao (*mao); i ++) {
                    jogada = PegaCarta (i, *mao);
                    if ((Valor (jogada) <= '6') && (ETrunfo (jogada, corte)) && (Valor (jogada) > Valor (mesa))) {
                        RetiraDaMao (jogada, mao);
                        Insere (jogada, monte);
                        return (jogada);
                    }
                }
            }
            jogada = PegaCarta (1, *mao);
            RetiraDaMao (jogada, mao);
            Insere (jogada, monte);
            return (jogada);
        }
        else
            return (PC2Jogadores2 (mao, monte, corte, seteSaiu));
    }
    else {
        for (int i = TamanhoMao (*mao); i >= 1; i --) {
            jogada = PegaCarta (i, *mao);
            if (! (ETrunfo (jogada, corte))) {
                RetiraDaMao (jogada, mao);
                Insere (jogada, monte);
                return (jogada);
            }
        }
    }
    jogada = PegaCarta (1, *mao);
    RetiraDaMao (jogada, mao);
    Insere (jogada, monte);
    return (jogada);
}

tCarta PC4Jogadores4 (tMao *mao, tMonte *monte, tCarta corte, int seteSaiu) {
    OrdenaMao (mao);
    //OrdenaMesa;
    int pontos;
    tCarta jogada, mesa;
    pontos = 0;

    mesa = CartaNoIndice (1, monte);
    if ((CartasIguais (mesa, CartaNoIndice (3, monte))) || (CartasIguais (mesa, CartaNoIndice (1, monte)))) {
        if (ETrunfo (mesa, corte)) {
            if ((Valor (mesa) == '7') && (CartasIguais (mesa, CartaNoIndice (3, monte)))) {
                tCarta heley = PreencheCarta ('A', Naipe (corte));
                if (EstaNaMao (Valor (heley), Naipe (heley), *mao)) {
                    RetiraDaMao (heley, mao);
                    Insere (heley, monte);
                    return (heley);
                }
            }
            else if (pontos >= 10) {
                for (int i = 1; i <= TamanhoMao (*mao); i ++) {
                    jogada = PegaCarta (i, *mao);
                    if ((Valor (jogada) <= '6') && (ETrunfo (jogada, corte)) && (Valor (jogada) > Valor (mesa))) {
                        RetiraDaMao (jogada, mao);
                        Insere (jogada, monte);
                        return (jogada);
                    }
                }
            }
            jogada = PegaCarta (1, *mao);
            RetiraDaMao (jogada, mao);
            Insere (jogada, monte);
            return (jogada);
        }
        else
            return (PC2Jogadores2 (mao, monte, corte, seteSaiu));
    }
    else {
        for (int i = TamanhoMao (*mao); i >= 1; i --) {
            jogada = PegaCarta (i, *mao);
            if (! (ETrunfo (jogada, corte))) {
                RetiraDaMao (jogada, mao);
                Insere (jogada, monte);
                return (jogada);
            }
        }
    }
    RetiraDaMao (jogada, mao);
    Insere (jogada, monte);
    return (jogada);
}

tCarta PC4JogadoresAleatorio (tMao *mao, tMonte *monte, tCarta corte, int seteSaiu) {
    return (PC2JogadoresAleatorio (mao, monte, corte, seteSaiu));
}
