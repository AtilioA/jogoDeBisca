/* Biblioteca que implementa IA para partidas de bisca com 2 jogadores */


#ifndef IA2JOGADORES_H_
#define IA2JOGADORES_H_

#include "MaosSimples.h"
#include "BaralhoEncadeado.h"

// Retorna a carta que a IA deve jogar quando ela é a primeira a jogar na rodada
tCarta PC2Jogadores1 (tMao *mao, tMonte *monte, tCarta corte, int *seteSaiu);

// Retorna a carta que a IA deve jogar quando ela é a segunda a jogar na rodada
tCarta PC2Jogadores2 (tMao *mao, tMonte *monte, tCarta corte, int *seteSaiu);

// Retorna uma carta aleatória para a IA jogar
tCarta PCXJogadoresAleatorio (tMao *mao, tMonte *monte, tCarta corte, int *seteSaiu);

#endif
