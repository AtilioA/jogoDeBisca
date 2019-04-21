#ifndef MAOS_H_
#define MAOS_H_

#include "cartas.h"

typedef struct {
    tCarta *carta;
    int n;
} tMao;

void CriaMao (tMao *mao);

void LiberaMao (tMao *mao);

tCarta PegaCarta (int p, tMao mao);

int EstaNaMao (tCarta carta, tMao mao);

void ColocaNaMao (tCarta carta, tMao *mao) ;

void RetiraDaMao (tCarta carta, tMao *mao);

int TamanhoMao (tMao mao);

void ImprimeMao (tMao mao);

void ordenaMao (tMao *mao);

#endif
