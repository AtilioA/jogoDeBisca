/* Módulo com funções para manipulação do baralho */

// Guard para evitar dupla inclusão
#ifndef __BARALHO_H
#define __BARALHO_H

#include "../include/Jogo.h"

// Cria o vetor com todas as cartas do baralho
tCarta *escreveBaralho();

// Imprime todas as cartas da mão de um jogador
void imprimeMao(tJogador jogador);

// Exibe todas as cartas de um baralho
void imprimeBaralho(tCarta *baralho, int nCartas);

// Rearranja as cartas de um baralho em ordem aleatória
void embaralhaBaralho(tCarta *baralho);

#endif
