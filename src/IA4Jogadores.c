#include "../include/IA4Jogadores.h"

int CartasIguais (tCarta carta1, tCarta carta2) {
    return ((Valor (carta1) == Valor (carta2)) && (Naipe (carta1) == Naipe (carta2)));
}

tCarta MaiorMesa (tMonte *mesa, tCarta corte) {
    int valorMaior, valorAux;
    tCarta maior, aux;

    valorMaior = valorAux = 0;
    maior = CartaNoIndice (1, mesa);
    for (int i = 1; i <= QuantidadeMonte (mesa); i ++) {
        aux = CartaNoIndice (i, mesa);
        for (int k = 0; k < nVALORES; k ++) {
            if (Valor (maior) == VALORES[k]) {
                valorMaior = k;
                if (ETrunfo (maior, corte))
                    valorMaior = valorMaior + nVALORES;
            }
            if (Valor (aux) == VALORES[k]) {
                valorAux = k;
                if (ETrunfo (aux, corte))
                    valorAux = valorAux + nVALORES;
            }
        }
        if (((ETrunfo (aux, corte)) && (! (ETrunfo (maior, corte)))) ||
            ((valorAux > valorMaior) && (Naipe (aux) == Naipe (maior))))
            maior = aux;
    }
    return (maior);
}

tCarta PC4Jogadores1 (tMao *mao, tMonte *monte, tCarta corte, int *seteSaiu) {
    return (PC2Jogadores1 (mao, monte, corte, seteSaiu));
}

tCarta PC4Jogadores2 (tMao *mao, tMonte *monte, tCarta corte, int *seteSaiu) {
    OrdenaMao (mao);
    int pontos;
    tCarta jogada, mesa;
    pontos = 0;

    mesa = MaiorMesa (monte, corte);
    if (pontos >= 10) {
        for (int i = 1; i <= TamanhoMao (*mao); i ++) {
            jogada = PegaCarta (i, *mao);
            if ((ETrunfo (jogada, corte)) && (! (ETrunfo (mesa, corte)))) {
                MaoParaMonte (jogada, monte, mao);
                if (Valor (jogada) == '7')
                    *seteSaiu = 1;
                return (jogada);
            }
        }
    }
    return (PC2Jogadores2 (mao, monte, corte, seteSaiu));
}

tCarta PC4Jogadores3 (tMao *mao, tMonte *monte, tCarta corte, int *seteSaiu) {
    OrdenaMao (mao);
    int pontos;
    tCarta jogada, mesa;
    pontos = 0;

    mesa = MaiorMesa (monte, corte);
    if (CartasIguais (mesa, CartaNoIndice (2, monte))) {
        if (ETrunfo (mesa, corte)) {
            if (Valor (mesa) == '7') {
                tCarta heley = PreencheCarta ('A', Naipe (corte));
                if (EstaNaMao (Valor (heley), Naipe (heley), *mao)) {
                    MaoParaMonte (jogada, monte, mao);
                    return (heley);
                }
            }
            else if (pontos >= 10) {
                for (int i = 1; i <= TamanhoMao (*mao); i ++) {
                    jogada = PegaCarta (i, *mao);
                    if ((Valor (jogada) <= '6') && (ETrunfo (jogada, corte)) && (Valor (jogada) > Valor (mesa))) {
                        MaoParaMonte (jogada, monte, mao);
                        return (jogada);
                    }
                }
            }
        }
        else
            return (PC2Jogadores2 (mao, monte, corte, *seteSaiu));
    }
    else {
        for (int i = TamanhoMao (*mao); i >= 1; i --) {
            jogada = PegaCarta (i, *mao);
            if (! (ETrunfo (jogada, corte))) {
                MaoParaMonte (jogada, monte, mao);
                return (jogada);
            }
        }
    }
    jogada = PegaCarta (1, *mao);
    MaoParaMonte (jogada, monte, mao);
    if ((ETrunfo (jogada, corte)) && (Valor (jogada) == '7'))
        *seteSaiu = 1;
    return (jogada);
}

tCarta PC4Jogadores4 (tMao *mao, tMonte *monte, tCarta corte, int *seteSaiu) {
    OrdenaMao (mao);
    int pontos;
    tCarta jogada, mesa;
    pontos = 0;

    mesa = MaiorMesa (monte, corte);
    if ((CartasIguais (mesa, CartaNoIndice (3, monte))) || (CartasIguais (mesa, CartaNoIndice (1, monte)))) {
        if (ETrunfo (mesa, corte)) {
            if ((Valor (mesa) == '7') && (CartasIguais (mesa, CartaNoIndice (3, monte)))) {
                tCarta heley = PreencheCarta ('A', Naipe (corte));
                if (EstaNaMao (Valor (heley), Naipe (heley), *mao)) {
                    MaoParaMonte (heley, monte, mao);
                    return (heley);
                }
            }
            else if (pontos >= 10) {
                for (int i = 1; i <= TamanhoMao (*mao); i ++) {
                    jogada = PegaCarta (i, *mao);
                    if ((Valor (jogada) <= '6') && (ETrunfo (jogada, corte)) && (Valor (jogada) > Valor (mesa))) {
                        MaoParaMonte (jogada, monte, mao);
                        return (jogada);
                    }
                }
            }
        }
        else
            return (PC2Jogadores2 (mao, monte, corte, *seteSaiu));
    }
    else {
        for (int i = TamanhoMao (*mao); i >= 1; i --) {
            jogada = PegaCarta (i, *mao);
            if (! (ETrunfo (jogada, corte))) {
                MaoParaMonte (jogada, monte, mao);
                return (jogada);
            }
        }
    }
    jogada = PegaCarta (1, *mao);
    MaoParaMonte (jogada, monte, mao);
    if ((ETrunfo (jogada, corte)) && (Valor (jogada) == '7'))
        *seteSaiu = 1;
    return (jogada);
}

tCarta PC4JogadoresAleatorio (tMao *mao, tMonte *monte, tCarta corte, int *seteSaiu) {
    return (PC2JogadoresAleatorio (mao, monte, corte, seteSaiu));
}
