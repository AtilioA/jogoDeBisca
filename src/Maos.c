#include "../include/Maos.h"
#include "../include/BaralhoEncadeado.h"

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

tCarta PegaCartaMao(int p, tMao mao)
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
        if ((valor == Valor(PegaCartaMao(i + 1, mao))) &&
            (naipe == Naipe(PegaCartaMao(i + 1, mao))))
            return (1);
    }
    return (0);
}

void ColocaNaMao(tCarta carta, tMao *mao)
{
    if ((TamanhoMao(*mao) >= nMAO) || (!(CartaValida(carta))) || (EstaNaMao(Valor (carta), Naipe (carta), *mao)))
    if ((TamanhoMao(*mao) >= nMAO) || (!(CartaValida(carta))) || (EstaNaMao(Valor(carta), Naipe(carta), *mao)))
        return;

    mao->carta[mao->n].valor = Valor(carta);
    mao->carta[mao->n].naipe = Naipe(carta);
    mao->n++;
}

void RetiraDaMao(char valor, char naipe, tMao *mao, tCarta *cartaRetirada)
{
    if (!(EstaNaMao(valor, naipe, *mao)))
        return;

    cartaRetirada = NULL;
    for (int i = 0; i < (TamanhoMao(*mao)); i++)
    {
        if ((valor == Valor(PegaCartaMao(i + 1, *mao))) &&
            (naipe == Naipe(PegaCartaMao(i + 1, *mao))))
        {
            *cartaRetirada = mao->carta[i];
            mao->n--;
            for (int j = i; j < (TamanhoMao(*mao)); j++)
                mao->carta[j] = mao->carta[j + 1];
        }
    }
}

void DeletaDaMao(tCarta carta, tMao *mao)
{
    if (!(EstaNaMao(Valor(carta), Naipe(carta), *mao)))
        return;

    for (int i = 0; i < (TamanhoMao(*mao)); i++)
    {
        if ((Valor(carta) == Valor(PegaCartaMao(i + 1, *mao))) &&
            (Naipe(carta) == Naipe(PegaCartaMao(i + 1, *mao))))
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
    int valori = 0, valorj = 0;
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


void MaoParaMonte(tMao *mao, tMonte *monte)
{

}
