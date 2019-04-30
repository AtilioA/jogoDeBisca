#ifndef MAOS_H_
#define MAOS_H_

#include "Cartas.h"

// Chame antes as bibliotecas necessárias para suas structs
// Neste caso, apenas a Cartas.h, pois nela está definida a estrutura tCarta
typedef struct
{
    tCarta *carta;
    int n;
} tMao;

#include "BaralhoEncadeado.h"

void CriaMao(tMao *mao);

void LiberaMao(tMao *mao);

tCarta PegaCarta(int p, tMao mao);

int EstaNaMao(char valor, char naipe, tMao mao);

void ColocaNaMao(tCarta carta, tMao *mao);

void RetiraDaMao(tCarta carta, tMao *mao);

int TamanhoMao(tMao mao);

void ImprimeMao(tMao mao);

void OrdenaMao(tMao *mao);

#endif
