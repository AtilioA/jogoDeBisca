#ifndef MAOS_H_
#define MAOS_H_

#include "Cartas.h"

typedef struct {
    tCarta *carta;
    int n;
} tMao;

void CriaMao (tMao *mao);

void LiberaMao (tMao *mao);

tCarta PegaCartaMao (int p, tMao mao);

int EstaNaMao (char valor, char naipe, tMao mao);

void ColocaNaMao (tCarta carta, tMao *mao);

void RetiraDaMao (tCarta carta, tMao *mao);

int TamanhoMao (tMao mao);

void ImprimeMao (tMao mao);

void OrdenaMao (tMao *mao);

#endif
