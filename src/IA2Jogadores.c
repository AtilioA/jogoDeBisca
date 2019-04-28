#include "../include/BaralhoEncadeado.h"
#include "../include/Cartas.h"
#include "../include/Maos.h"
#include "../include/IA2Jogadores.h"

int PontoAlto (tCarta carta) {
    return ((Valor (carta) == '7') || (Valor (carta) == 'A'));
}

int PontoBaixo (tCarta carta) {
    return ((Valor (carta) == 'Q') || (Valor (carta) == 'J') || (Valor (carta) == 'K'));
}

int ETrunfo (tCarta carta, tCarta corte) {
    return (Naipe (carta) == Naipe (corte));
}

tCarta PC2Jogadores1 (tMao *mao, tMonte *monte, tCarta corte, int seteSaiu) {
    ordenaMao (mao);
    tCarta jogada, mesa;
    mesa = CartaNoIndice (1, monte);

    for (int i = TamanhoMao (*mao); i >= 1; i --) {
        jogada = PegaCarta (i, *mao);
        if ((PontoBaixo (jogada)) && (!(ETrunfo (jogada, corte)))) {
            RetiraDaMao (jogada, mao);
            Insere (jogada, monte);
            return (jogada);
        }
    }
    for (int i = 1; i <= TamanhoMao (*mao); i ++) {
        jogada = PegaCarta (i, *mao);
        if ((Valor (jogada) <= '6') && (!(ETrunfo (jogada, corte)))) {
            RetiraDaMao (jogada, mao);
            Insere (jogada, monte);
            return (jogada);
        }
    }
    for (int i = 1; i <= TamanhoMao (*mao); i ++) {
        jogada = PegaCarta (i, *mao);
        if (Valor (jogada) <= '6') {
            RetiraDaMao (jogada, mao);
            Insere (jogada, monte);
            return (jogada);
        }
    }
    for (int i = 1; i <= TamanhoMao (*mao); i ++) {
        jogada = PegaCarta (i, *mao);
        if ((PontoAlto (jogada)) && (!(ETrunfo (jogada, corte)))) {
            RetiraDaMao (jogada, mao);
            Insere (jogada, monte);
            return (jogada);
        }
    }
    for (int i = 1; i <= TamanhoMao (*mao); i ++) {
        jogada = PegaCarta (i, *mao);
        if (PontoBaixo (jogada)) {
            RetiraDaMao (jogada, mao);
            Insere (jogada, monte);
            return (jogada);
        }
    }
    jogada = PegaCarta (1, *mao);
    while ((Valor (jogada) == 'A') && (ETrunfo (jogada, corte)) && (!(seteSaiu)) && (TamanhoMao (*mao) > 1))
        jogada = PegaCarta (1 , *mao);
    RetiraDaMao (jogada, mao);
    Insere (jogada, monte);
    return (jogada);
}

tCarta PC2Jogadores2 (tMao *mao, tMonte *monte, tCarta corte, int seteSaiu) {
    int i = 0;
    char trunfo = Naipe (corte);
    OrdenaMao (mao);
    //OrdenaMesa
    tCarta jogada, mesa;
    mesa = CartaNoIndice (1, monte);

    //caida e trunfo
    if (ETrunfo (mesa, corte)) {
        if (Valor (mesa) == '7') {
            PreencheCarta ('A', Naipe (corte), &heley);
            if (EstaNaMao (Valor (heley), Naipe (heley), *mao)) {
                RetiraDaMao (heley, mao);
                Insere (heley, monte);
                return (heley);
            }
        }
        for (int i = 1; i <= TamanhoMao (*mao); i ++) {
            jogada = PegaCarta (i, *mao);
            if ((Valor (jogada) <= '3') && (Valor (jogada) < Valor (mesa))) {
                RetiraDaMao (jogada, mao);
                Insere (jogada, monte);
                return (jogada);
            }
        }
        for (int i = 1; i <= TamanhoMao (*mao); i ++) {
            jogada = PegaCarta (i, *mao);
            if ((!(ETrunfo (jogada, corte))) && (!(PontoAlto (jogada)))) {
                RetiraDaMao (jogada, mao);
                Insere (jogada, monte);
                return (jogada);
            }
        }
    }
    //caida nao e trunfo
    else {
        if (PontoAlto (mesa)) {
            if (Valor (mesa) == '7') { //A sobre 7
                for (int i = 0; i < 4; i ++) {
                    PreencheCarta ('A', NAIPES[i], &heley);
                    if (EstaNaMao (Valor (heley), Naipe (heley), *mao)) {
                        RetiraDaMao (heley, mao);
                        Insere (jogada, monte);
                        return (heley);
                    }
                }
            }
            else {
                for (int i = 1; i <= TamanhoMao (*mao); i ++) {
                    jogada = PegaCarta (i, *mao);
                    if (ETrunfo (jogada, corte)) {
                        if (Valor (jogada) == 'A') {
                            if (seteSaiu) {
                                RetiraDaMao (jogada, mao);
                                Insere (jogada, monte);
                                return (jogada);
                            }
                        }
                        else {
                            RetiraDaMao (jogada, mao);
                            Insere (jogada, monte);
                            return (jogada);
                        }
                    }
                }
            }
        }
        else if (PontoBaixo (mesa)) {
            if (Valor (mesa) == 'K') {
                for (int i = TamanhoMao (*mao); i > 0; i --) {
                    jogada = PegaCarta (i, *mao);
                    if (((Valor (jogada) == '7') || (Valor (jogada) == 'A')) && (Naipe (jogada) == Naipe (mesa))) {
                        RetiraDaMao (jogada, mao);
                        Insere (jogada, monte);
                        return (jogada);
                    }
                }
                for (int i = 1; i <= TamanhoMao (*mao); i ++) {
                    jogada = PegaCarta (i, *mao);
                    if ((Valor (jogada) <= '5') && (ETrunfo (jogada, corte))) {
                        RetiraDaMao (jogada, mao);
                        Insere (jogada, monte);
                        return (jogada);
                    }
                }
            }

            else if (Valor (mesa) == 'J') {
                for (int i = TamanhoMao (*mao); i > 0; i --) {
                    jogada = PegaCarta (i, *mao);
                    if (((Valor (jogada) == 'K') || (Valor (jogada) == '7') || (Valor (jogada) == 'A')) && (Naipe (jogada) == Naipe (mesa))) {
                        RetiraDaMao (jogada, mao);
                        Insere (jogada, monte);
                        return (jogada);
                    }
                }
                for (int i = 1; i <= TamanhoMao (*mao); i ++) {
                    jogada = PegaCarta (i, *mao);
                    if ((Valor (jogada) <= '4') && (ETrunfo (jogada, corte))) {
                        RetiraDaMao (jogada, mao);
                        Insere (jogada, monte);
                        return (jogada);
                    }
                }
            }

            else {
                for (int i = TamanhoMao (*mao); i > 0; i --) {
                    jogada = PegaCarta (i, *mao);
                    if (((Valor (jogada) == 'J') || (Valor (jogada) == 'K') || (Valor (jogada) == '7') || (Valor (jogada) == 'A')) && (Naipe (jogada) == Naipe (mesa))) {
                        RetiraDaMao (jogada, mao);
                        Insere (jogada, monte);
                        return (jogada);
                    }
                }
                for (int i = 1; i <= TamanhoMao (*mao); i ++) {
                    jogada = PegaCarta (i, *mao);
                    if ((Valor (jogada) <= '3') && (ETrunfo (jogada, corte))) {
                        RetiraDaMao (jogada, mao);
                        Insere (jogada, monte);
                        return (jogada);
                    }
                }
            }
        }
        else {
            for (int i = TamanhoMao (*mao); i > 0; i --) {
                jogada = PegaCarta (i, *mao);
                if ((!(ETrunfo (jogada, corte))) && ((PontoAlto (jogada)) || (PontoBaixo (jogada))) && (Naipe (jogada) == Naipe (mesa))) {
                    RetiraDaMao (jogada, mao);
                    Insere (jogada, monte);
                    return (jogada);
                }
            }
        }
    }
    for (int i = 1; i <= TamanhoMao (*mao); i ++) {
        jogada = PegaCarta (i, *mao);
        if (ETrunfo (jogada, corte)) {
            if (Valor (jogada) == 'A') {
                if (seteSaiu) {
                    RetiraDaMao (jogada, mao);
                    Insere (jogada, monte);
                    return (jogada);
                }
            }
            if (Valor (jogada) <= '3') {
                RetiraDaMao (jogada, mao);
                Insere (jogada, monte);
                return (jogada);
            }
        }
        RetiraDaMao (jogada, mao);
        Insere (jogada, monte);
        return (jogada);
    }
    jogada = PegaCarta (1, *mao);
    RetiraDaMao (jogada, mao);
    Insere (jogada, monte);
    return (jogada);
}

tCarta PC2JogadoresAleatorio (tMao *mao, tMonte *monte, tCarta corte, int seteSaiu) {
    tCarta jogada;
    srand (time (NULL));
    jogada = PegaCartaMao ((rand ( ) % mao->n)+1, *mao);
    while (ETrunfo (jogada) && (Valor (jogada) == 'A') && (! (seteSaiu))) {
        srand (time (NULL));
        jogada = PegaCartaMao ((rand ( ) % mao->n)+1 , *mao);
    }
    RetiraDaMao (jogada, mao);
    Insere (jogada, monte);

    return (jogada);
}
