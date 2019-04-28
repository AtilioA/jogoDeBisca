#include "../include/Maos.h"

void CriaMao(tMao *mao)
{
    mao->carta = (tCarta *)malloc(nMAO * sizeof(tCarta));
    mao->n = 0;
    if (mao->carta == NULL)
    {
        printf("ERRO! memoria insuficiente.\n");
        return;
    }
}

void LiberaMao(tMao *mao)
{
    free(mao->carta);
    mao->n = 0;
}

tCarta PegaCartaMaoMaoMao(int p, tMao mao)
{
    tCarta escolhida;

    if ((p > TamanhoMao(mao)) || (p <= 0))
        escolhida.valor = escolhida.naipe = ' ';
    else
        escolhida = mao.carta[p - 1];

    return (escolhida);
}

int EstaNaMao(char valor, char naipe, tMao mao)
{
    for (int i = 0; i < (TamanhoMao(mao)); i++)
    {
        if (valor == Valor(PegaCartaMaoMao(i + 1, mao))) &&
            (naipe == Naipe(PegaCartaMaoMao(i + 1, mao))))
            return (1);
    }
    return (0);
}

void ColocaNaMao(tCarta carta, tMao *mao)
{
    if ((TamanhoMao(*mao) >= nMAO) || (!(CartaValida(carta))) || (EstaNaMao(carta, *mao)))
        return;

    mao->carta[mao->n].valor = carta.valor;
    mao->carta[mao->n].naipe = carta.naipe;
    mao->n++;
}

void RetiraDaMao(tCarta carta, tMao *mao)
{
    if (!(EstaNaMao(carta, *mao)))
        return;

    for (int i = 0; i < (TamanhoMao(*mao)); i++)
    {
        if ((Valor(carta) == Valor(PegaCartaMaoMao(i + 1, *mao))) &&
            (Naipe(carta) == Naipe(PegaCartaMaoMao(i + 1, *mao))))
        {
            mao->n--;
            for (int j = i; j < (TamanhoMao(*mao)); j++)
                mao->carta[j] = mao->carta[j + 1];
        }
    }
}

int TamanhoMao(tMao mao)
{
    return (mao.n);
}

void ImprimeMao(tMao mao)
{
    for (int i = 0; i < (TamanhoMao(mao)); i++)
    {
        ImprimeCarta(mao.carta[i]);
        printf("\n");
    }
}

void OrdenaMao(tMao *mao)
{
    int valori, valorj;
    tCarta aux;

    for (int i = 0; i < (TamanhoMao(*mao)); i++)
    {
        for (int j = 0; j < (TamanhoMao(*mao) - 1); j++)
        {
            for (int k = 0; k < nVALORES; k++)
            {
                if (mao->carta[i].valor == VALORES[k])
                    valori = k;
                if (mao->carta[j].valor == VALORES[k])
                    valorj = k;
            }
            if (valori < valorj)
            {
                aux = mao->carta[j];
                mao->carta[j] = mao->carta[i];
                mao->carta[i] = aux;
            }
        }
    }
}
