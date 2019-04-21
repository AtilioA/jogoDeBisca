#ifndef IA2JOGADORES_H_
#define IA2JOGADORES_H_

#include <time.h>
#include "maos.h"

int PontoAlto (tCarta carta);

int PontoBaixo (tCarta carta);

int ETrunfo (tCarta carta, tCarta corte);

tCarta PC2Jogadores (tMao *mao, tCarta mesa, tCarta corte, int seteSaiu);

tCarta PC2JogadoresAleatorio (tMao *mao);

#endif
