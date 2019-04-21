#include "IA2Jogadores.h"

int PontoAlto (tCarta carta) {
    return ((Valor (carta) == '7') || (Valor (carta) == 'A'));
}

int PontoBaixo (tCarta carta) {
    return ((Valor (carta) == 'Q') || (Valor (carta) == 'J') || (Valor (carta) == 'K'));
}

int ETrunfo (tCarta carta, tCarta corte) {
    return (Naipe (carta) == Naipe (corte));
}

tCarta PC2Jogadores (tMao *mao, tCarta mesa, tCarta corte, int seteSaiu) {
    ordenaMao (mao);
    tCarta jogada, heley;

    //caida e trunfo
    if (ETrunfo (mesa, corte)) {
        if (Valor (mesa) == '7') {
            PreencheCarta ('A', Naipe (corte), &heley);
            if (EstaNaMao (heley, *mao)) {
                RetiraDaMao (heley, mao);
                return (heley);
            }
        }
        for (int i = 1; i <= TamanhoMao (*mao); i ++) {
            jogada = PegaCarta (i, *mao);
            if ((Valor (jogada) <= '3') && (Valor (jogada) < Valor (mesa))) {
                RetiraDaMao (jogada, mao);
                return (jogada);
            }
        }
        for (int i = 1; i <= TamanhoMao (*mao); i ++) {
            jogada = PegaCarta (i, *mao);
            if ((!(ETrunfo (jogada, corte))) && (!(PontoAlto (jogada)))) {
                RetiraDaMao (jogada, mao);
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
                    if (EstaNaMao (heley, *mao)) {
                        RetiraDaMao (heley, mao);
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
                                return (jogada);
                            }
                        }
                        else {
                            RetiraDaMao (jogada, mao);
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
                        return (jogada);
                    }
                }
                for (int i = 1; i <= TamanhoMao (*mao); i ++) {
                    jogada = PegaCarta (i, *mao);
                    if ((Valor (jogada) <= '5') && (ETrunfo (jogada, corte))) {
                        RetiraDaMao (jogada, mao);
                        return (jogada);
                    }
                }
            }

            else if (Valor (mesa) == 'J') {
                for (int i = TamanhoMao (*mao); i > 0; i --) {
                    jogada = PegaCarta (i, *mao);
                    if (((Valor (jogada) == 'K') || (Valor (jogada) == '7') || (Valor (jogada) == 'A')) && (Naipe (jogada) == Naipe (mesa))) {
                        RetiraDaMao (jogada, mao);
                        return (jogada);
                    }
                }
                for (int i = 1; i <= TamanhoMao (*mao); i ++) {
                    jogada = PegaCarta (i, *mao);
                    if ((Valor (jogada) <= '4') && (ETrunfo (jogada, corte))) {
                        RetiraDaMao (jogada, mao);
                        return (jogada);
                    }
                }
            }

            else {
                for (int i = TamanhoMao (*mao); i > 0; i --) {
                    jogada = PegaCarta (i, *mao);
                    if (((Valor (jogada) == 'J') || (Valor (jogada) == 'K') || (Valor (jogada) == '7') || (Valor (jogada) == 'A')) && (Naipe (jogada) == Naipe (mesa))) {
                        RetiraDaMao (jogada, mao);
                        return (jogada);
                    }
                }
                for (int i = 1; i <= TamanhoMao (*mao); i ++) {
                    jogada = PegaCarta (i, *mao);
                    if ((Valor (jogada) <= '3') && (ETrunfo (jogada, corte))) {
                        RetiraDaMao (jogada, mao);
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
                    return (jogada);
                }
            }
            if (Valor (jogada) <= '3') {
                RetiraDaMao (jogada, mao);
                return (jogada);
            }
        }
        RetiraDaMao (jogada, mao);
        return (jogada);
    }
    jogada = PegaCarta (1, *mao);
    RetiraDaMao (jogada, mao);
    return (jogada);
}

tCarta PC2JogadoresAleatorio (tMao *mao) {
    tCarta jogada;
    srand (time (NULL));
    jogada = PegaCarta ((rand ( ) % mao->n)+1 , *mao);
    RetiraDaMao (jogada, mao);

    return (jogada);
}
