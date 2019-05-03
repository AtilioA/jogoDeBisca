#ifndef IA4JOGADORES_H_
#define IA4JOGADORES_H_

#include <time.h>
#include "Maos.h"
#include "IA2Jogadores.h"
#include "BaralhoEncadeado.h"

// Verifica se duas cartas são iguais (essa pode ir para o Cartas.c)
int CartasIguais (tCarta carta1, tCarta carta2);

// Retorna a carta que prevalesce na mesa (essa pode ir para o PartidaCircular.c ou BaralhoEncadeado.c)
tCarta MaiorMesa (tMonte *mesa, tCarta corte);

// Retorna a carta que a IA deve jogar quando ela é a segunda a jogar na rodada
tCarta PC4Jogadores1 (tMao *mao, tMonte *monte, tCarta corte, int *seteSaiu);

// Retorna a carta que a IA deve jogar quando ela é a segunda a jogar na rodada
tCarta PC4Jogadores2 (tMao *mao, tMonte *monte, tCarta corte, int *seteSaiu);

// Retorna a carta que a IA deve jogar quando ela é a terceira a jogar na rodada
tCarta PC4Jogadores3 (tMao *mao, tMonte *monte, tCarta corte, int *seteSaiu);

// Retorna a carta que a IA deve jogar quando ela é a quarta jogar na rodada
tCarta PC4Jogadores4 (tMao *mao, tMonte *monte, tCarta corte, int *seteSaiu);

tCarta PC4JogadoresAleatorio (tMao *mao, tMonte *monte, tCarta corte, int *seteSaiu);

#endif
