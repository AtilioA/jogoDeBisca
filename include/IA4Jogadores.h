/* Biblioteca que implementa IA para partidas de bisca com 4 jogadores */

#ifndef IA4JOGADORES_H_
#define IA4JOGADORES_H_

#include "IA2Jogadores.h"

// Retorna a carta que prevalece na mesa (essa pode ir para o PartidaCircular.c ou BaralhoEncadeado.c)
tCarta MaiorMesa (tMonte *mesa, tCarta corte);

/* MODO DIFÍCIL */
// Retorna a melhor carta que a IA pode jogar quando ela é a segunda a jogar na rodada
tCarta PC4Jogadores1 (tMao *mao, tMonte *monte, tCarta corte, int *seteSaiu);
// Retorna a melhor carta que a IA pode jogar quando ela é a segunda a jogar na rodada
tCarta PC4Jogadores2 (tMao *mao, tMonte *monte, tCarta corte, int *seteSaiu);
// Retorna a melhor carta que a IA pode jogar quando ela é a terceira a jogar na rodada
tCarta PC4Jogadores3 (tMao *mao, tMonte *monte, tCarta corte, int *seteSaiu);
// Retorna a melhor carta que a IA pode jogar quando ela é a quarta jogar na rodada
tCarta PC4Jogadores4 (tMao *mao, tMonte *monte, tCarta corte, int *seteSaiu);

/* MODO INTERMEDIÁRIO */
// Retorna uma carta aleatória da mão para a IA jogar
tCarta PC4JogadoresAleatorio (tMao *mao, tMonte *monte, tCarta corte, int *seteSaiu);

#endif
