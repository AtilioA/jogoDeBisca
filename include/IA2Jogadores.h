#ifndef IA2JOGADORES_H_
#define IA2JOGADORES_H_

#include <time.h>
#include "Maos.h"
#include "BaralhoEncadeado.h"

// (essa pode ir para o Cartas.c ou PartidaCircular.c)
// Verifica se uma carta é ponto alto (7 ou A)
int PontoAlto (tCarta carta);

// (essa pode ir para o Cartas.c ou PartidaCircular.c)
// Verifica se uma carta é ponto baixo (J, Q ou K)
int PontoBaixo (tCarta carta);

// Verifica se uma carta é trunfo (essa pode ir para o PartidaCircular.c)
int ETrunfo (tCarta carta, tCarta corte);

// Retorna a carta que a IA deve jogar quando ela é a primeira a jogar na rodada
tCarta PC2Jogadores1 (tMao *mao, tMonte *monte, tCarta corte, int *seteSaiu);

// Retorna a carta que a IA deve jogar quando ela é a segunda a jogar na rodada
tCarta PC2Jogadores2 (tMao *mao, tMonte *monte, tCarta corte, int *seteSaiu);

// Retorna uma carta aleatória para a IA jogar
tCarta PC2JogadoresAleatorio (tMao *mao, tMonte *monte, tCarta corte, int *seteSaiu);

#endif
