#include "../include/IA2Jogadores.h"
#include "../include/Cartas.h"
#include <sys/time.h>
#include <stdio.h>

tCarta PC2Jogadores1(tMao *mao, tMonte *monte, tCarta corte, int *seteSaiu)
{
    OrdenaMao(mao);
    tCarta jogada;

    for (int i = TamanhoMao(*mao); i >= 1; i--)
    {
        jogada = PegaCarta(i, *mao);
        if ((PontoBaixo(jogada)) && (!(ETrunfo(jogada, corte))))
        {
            MaoParaMonte(jogada, monte, mao);
            return (jogada);
        }
    }
    for (int i = 1; i <= TamanhoMao(*mao); i++)
    {
        jogada = PegaCarta(i, *mao);
        if ((Valor(jogada) <= '6') && (!(ETrunfo(jogada, corte))))
        {
            MaoParaMonte(jogada, monte, mao);
            return (jogada);
        }
    }
    for (int i = 1; i <= TamanhoMao(*mao); i++)
    {
        jogada = PegaCarta(i, *mao);
        if (Valor(jogada) <= '6')
        {
            MaoParaMonte(jogada, monte, mao);
            return (jogada);
        }
    }
    for (int i = 1; i <= TamanhoMao(*mao); i++)
    {
        jogada = PegaCarta(i, *mao);
        if ((PontoAlto(jogada)) && (!(ETrunfo(jogada, corte))))
        {
            MaoParaMonte(jogada, monte, mao);
            return (jogada);
        }
    }
    for (int i = 1; i <= TamanhoMao(*mao); i++)
    {
        jogada = PegaCarta(i, *mao);
        if (PontoBaixo(jogada))
        {
            MaoParaMonte(jogada, monte, mao);
            return (jogada);
        }
    }
    jogada = PegaCarta(1, *mao);
    for (int i = 1; (((Valor(jogada) == 'A') && (ETrunfo(jogada, corte)) && (!(*seteSaiu)) && i <= TamanhoMao(*mao))); i ++) {
        jogada = PegaCarta(i, *mao);
    }
    MaoParaMonte(jogada, monte, mao);
    if ((ETrunfo(jogada, corte)) && (Valor(jogada) == '7'))
        *seteSaiu = 1;
    return (jogada);
}

tCarta PC2Jogadores2(tMao *mao, tMonte *monte, tCarta corte, int *seteSaiu)
{
    OrdenaMao(mao);
    //OrdenaMesa
    tCarta jogada, mesa;
    mesa = CartaNoIndice(1, monte);

    //caida e trunfo
    if (ETrunfo(mesa, corte))
    {
        if (Valor(mesa) == '7')
        {
            tCarta heley = PreencheCarta('A', Naipe(corte));
            if (EstaNaMao(Valor(heley), Naipe(heley), *mao))
            {
                MaoParaMonte(heley, monte, mao);
                return (heley);
            }
        }
        for (int i = 1; i <= TamanhoMao(*mao); i++)
        {
            jogada = PegaCarta(i, *mao);
            if ((Valor(jogada)) < (Valor(mesa)))
            {
                MaoParaMonte(jogada, monte, mao);
                return (jogada);
            }
        }
        for (int i = 1; i <= TamanhoMao(*mao); i++)
        {
            jogada = PegaCarta(i, *mao);
            if ((!(ETrunfo(jogada, corte))) && (!(PontoAlto(jogada))))
            {
                MaoParaMonte(jogada, monte, mao);
                return (jogada);
            }
        }
    }
    //caida nao e trunfo
    else
    {
        if (PontoAlto(mesa))
        {
            if (Valor(mesa) == '7')
            { //A sobre 7
                for (int i = 0; i < 4; i++)
                {
                    tCarta heley = PreencheCarta('A', NAIPES[i]);
                    if (EstaNaMao(Valor(heley), Naipe(heley), *mao))
                    {
                        MaoParaMonte(heley, monte, mao);
                        return (heley);
                    }
                }
            }
            else
            {
                for (int i = 1; i <= TamanhoMao(*mao); i++)
                {
                    jogada = PegaCarta(i, *mao);
                    if (ETrunfo(jogada, corte))
                    {
                        if (Valor(jogada) == 'A')
                        {
                            if (*seteSaiu)
                            {
                                MaoParaMonte(jogada, monte, mao);
                                return (jogada);
                            }
                        }
                        else
                        {
                            MaoParaMonte(jogada, monte, mao);
                            if (Valor(jogada) == '7')
                            {
                                *seteSaiu = 1;
                            }
                            return (jogada);
                        }
                    }
                }
            }
        }
        else if (PontoBaixo(mesa))
        {
            if (Valor(mesa) == 'K')
            {
                for (int i = TamanhoMao(*mao); i > 0; i--)
                {
                    jogada = PegaCarta(i, *mao);
                    if (((Valor(jogada) == '7') || (Valor(jogada) == 'A')) && (Naipe(jogada) == Naipe(mesa)))
                    {
                        MaoParaMonte(jogada, monte, mao);
                        return (jogada);
                    }
                }
                for (int i = 1; i <= TamanhoMao(*mao); i++)
                {
                    jogada = PegaCarta(i, *mao);
                    if ((Valor(jogada) <= '5') && (ETrunfo(jogada, corte)))
                    {
                        MaoParaMonte(jogada, monte, mao);
                        return (jogada);
                    }
                }
            }

            else if (Valor(mesa) == 'J')
            {
                for (int i = TamanhoMao(*mao); i > 0; i--)
                {
                    jogada = PegaCarta(i, *mao);
                    if (((Valor(jogada) == 'K') || (Valor(jogada) == '7') || (Valor(jogada) == 'A')) && (Naipe(jogada) == Naipe(mesa)))
                    {
                        MaoParaMonte(jogada, monte, mao);
                        return (jogada);
                    }
                }
                for (int i = 1; i <= TamanhoMao(*mao); i++)
                {
                    jogada = PegaCarta(i, *mao);
                    if ((Valor(jogada) <= '4') && (ETrunfo(jogada, corte)))
                    {
                        MaoParaMonte(jogada, monte, mao);
                        return (jogada);
                    }
                }
            }

            else
            {
                for (int i = TamanhoMao(*mao); i > 0; i--)
                {
                    jogada = PegaCarta(i, *mao);
                    if (((Valor(jogada) == 'J') || (Valor(jogada) == 'K') || (Valor(jogada) == '7') || (Valor(jogada) == 'A')) && (Naipe(jogada) == Naipe(mesa)))
                    {
                        MaoParaMonte(jogada, monte, mao);
                        return (jogada);
                    }
                }
                for (int i = 1; i <= TamanhoMao(*mao); i++)
                {
                    jogada = PegaCarta(i, *mao);
                    if ((Valor(jogada) <= '3') && (ETrunfo(jogada, corte)))
                    {
                        MaoParaMonte(jogada, monte, mao);
                        return (jogada);
                    }
                }
            }
        }
        else
        {
            for (int i = TamanhoMao(*mao); i > 0; i--)
            {
                jogada = PegaCarta(i, *mao);
                if ((!(ETrunfo(jogada, corte))) && ((PontoAlto(jogada)) || (PontoBaixo(jogada))) && (Naipe(jogada) == Naipe(mesa)))
                {
                    MaoParaMonte(jogada, monte, mao);
                    return (jogada);
                }
            }
        }
    }
    for (int i = 1; i <= TamanhoMao(*mao); i++)
    {
        jogada = PegaCarta(i, *mao);
        if (ETrunfo(jogada, corte))
        {
            if (Valor(jogada) == 'A')
            {
                if (*seteSaiu)
                {
                    MaoParaMonte(jogada, monte, mao);
                    return (jogada);
                }
            }
            if (Valor(jogada) <= '3')
            {
                MaoParaMonte(jogada, monte, mao);
                return (jogada);
            }
        }
    }
    jogada = PegaCarta(1, *mao);
    for (int i = 1; (((Valor(jogada) == 'A') && (ETrunfo(jogada, corte)) && (!(*seteSaiu)) && i <= TamanhoMao(*mao))); i ++) {
        jogada = PegaCarta(i, *mao);
    }
    MaoParaMonte(jogada, monte, mao);
    if ((ETrunfo(jogada, corte)) && (Valor(jogada) == '7'))
        *seteSaiu = 1;
    return (jogada);
}

tCarta PCXJogadoresAleatorio(tMao *mao, tMonte *monte, tCarta corte, int *seteSaiu)
{
    struct timeval t;
    int posAleatoria;
    tCarta jogada;

    gettimeofday(&t, NULL);
    srand((unsigned int)t.tv_usec);
    posAleatoria = (rand() % mao->n) + 1;
    jogada = PegaCarta(posAleatoria, *mao);
    while (ETrunfo(jogada, corte) && (Valor(jogada) == 'A') && (!(*seteSaiu)))
    {
        posAleatoria = (rand() % mao->n) + 1;
        jogada = PegaCarta(posAleatoria, *mao);
    }
    MaoParaMonte(jogada, monte, mao);
    if ((ETrunfo(jogada, corte)) && (Valor(jogada) == '7'))
    {
        *seteSaiu = 1;
    }

    return (jogada);
}
