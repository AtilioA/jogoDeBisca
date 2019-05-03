#ifndef IA2JOGADORES_H_
#define IA2JOGADORES_H_

#include <time.h>
#include "Maos.h"
#include "BaralhoEncadeado.h"

int PontoAlto (tCarta carta);

int PontoBaixo (tCarta carta);

int ETrunfo (tCarta carta, tCarta corte);

tCarta PC2Jogadores1 (tMao *mao, tMonte *monte, tCarta corte, int *seteSaiu);

tCarta PC2Jogadores2 (tMao *mao, tMonte *monte, tCarta corte, int *seteSaiu);

tCarta PC2JogadoresAleatorio (tMao *mao, tMonte *monte, tCarta corte, int *seteSaiu);

#endif
