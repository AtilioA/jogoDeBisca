/*
 * Esta biblioteca contém o código que permite manipular o baralho de um jogo de bisca.
 * Auxilia a biblioteca Jogo.h. Esta biblioteca é mais específica,
 * lidando com funções mais básicas relevantes a uma partida.
 *
 * EM CONSTRUÇÃO
 *
 */

/* Módulo com funções para manipulação do baralho */

// Guard para evitar dupla inclusão
#ifndef __BARALHO_H
#define __BARALHO_H

// Estrutura de dados que abstrai uma carta, que possui valor e naipe
typedef struct
{
    int Chave;
    char valor;
    char naipe;
} tCarta;

// Lista encadeada que abstrai um conjunto de cartas
typedef struct {
  tCarta cartas[MAXTAM];
  Posicao primeiro, ultimo;
} tBaralho;

#include "Jogo.h"

// Cria o vetor com todas as cartas do baralho
tCarta *escreveBaralho();

// Imprime todas as cartas da mão de um jogador
void imprimeMao(tJogador jogador);

// Exibe todas as cartas de um baralho
void imprimeBaralho(tCarta *baralho, int nCartas);

// Rearranja as cartas de um baralho em ordem aleatória
void embaralhaBaralho(tCarta *baralho);

#endif
