#ifndef IA4JOGADORES_H_
#define IA4JOGADORES_H_

#include <time.h>
#include "Maos.h"
#include "IA2Jogadores.h"

typedef struct tBaralho tBaralho;
struct {
    tCarta carta;
    struct tBaralho *proxima;
};

typedef struct {
  tBaralho *primeira, *ultima;
} tMonte;

tCarta PC4Jogadores1 (tMao *mao, tCarta corte, int seteSaiu);

tCarta PC4Jogadores2 (tMao *mao, tBaralho *mesa, tCarta corte, int seteSaiu);

tCarta PC4Jogadores3 (tMao *mao, tBaralho *mesa, tCarta corte, int seteSaiu);

tCarta PC4Jogadores4 (tMao *mao, tBaralho *mesa, tCarta corte, int seteSaiu);

tCarta PC4JogadoresAleatorio (tMao *mao, tCarta corte, int seteSaiu);

#endif
