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

#include "Jogo.h"

// Estrutura de dados que abstrai uma carta, que possui valor e naipe
typedef struct
{
    int chave;
    char valor;
    char naipe;
} tCarta;

// typedef struct tCelula *tApontador;

// Lista encadeada que abstrai um conjunto de cartas
typedef struct tCelula
{
    tCarta carta;
    struct tCelula *prox;
} tCelula;

typedef struct
{
    tCelula *primeiro, *ultimo;
} tLista;

// Faz a lista ficar vazia
void FLVazia(tLista *Lista);

// Verifica se a lista está vazia
int estaVazia(tLista Lista);

// Insere uma carta na lista
void insere(tCarta x, tLista *Lista);

// Retira uma carta da lista e retorna o elemento por referência
void retira(tCelula *p, tLista *Lista, tCarta *Carta);

// Imprime as cartas da lista
void imprimeLista(tLista Lista);


// Cria o vetor com todas as cartas do baralho
tCarta *escreveBaralho();

// Imprime todas as cartas da mão de um jogador
// void imprimeMao(tJogador jogador);

// Exibe todas as cartas de um baralho
void imprimeBaralho(tCarta *baralho, int nCartas);

// Rearranja as cartas de um baralho em ordem aleatória
void embaralhaBaralho(tCarta *baralho);

#endif
