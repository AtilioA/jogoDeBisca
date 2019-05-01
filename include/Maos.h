#ifndef MAOS_H_
#define MAOS_H_

#include "Cartas.h"

// Chame antes as bibliotecas necessárias para suas structs
// Neste caso, apenas a Cartas.h, pois nela está definida a estrutura tCarta
typedef struct
{
    tCarta *carta;
    int n;
} tMao;

#include "BaralhoEncadeado.h"

/* Funções para acessar estrutura opaca */
// Retorna o tamanho da mão
int TamanhoMao(tMao mao);
// Retorna a carta de uma dada posição na mão
tCarta PegaCarta(int p, tMao mao);

// Cria uma mão vazia
void CriaMao(tMao *mao);

// Libera o vetor dinâmico de cartas e zera a quantidade de cartas da mão
void LiberaMao(tMao *mao);

// Verifica se uma carta está na mão
int EstaNaMao(char valor, char naipe, tMao mao);

// Insere uma carta na mão
void ColocaNaMao(tCarta carta, tMao *mao);

// Retira uma carta na mão
void RetiraDaMao(tCarta carta, tMao *mao);

// Imprime as cartas da mão
void ImprimeMao(tMao mao);

// Ordena as cartas da mão
void OrdenaMao(tMao *mao);

#endif
