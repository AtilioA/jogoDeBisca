/*
 * Esta biblioteca contém o código que implementa funções mais básicas
 * relevantes ao baralho de uma partida de bisca.
 *
 */

// Guard para evitar dupla inclusão
#ifndef __BARALHO_ENCADEADO_H
#define __BARALHO_ENCADEADO_H

// Chame as bibliotecas necessárias para suas structs antes de declará-las
// Neste caso, a Cartas.h, pois nela está definida a estrutura tCarta
#include "Cartas.h"
#include "Maos.h"
#include <sys/time.h>

// Lista encadeada que abstrai um conjunto de cartas
typedef struct tCelula
{
    tCarta carta;
    struct tCelula *prox;
} tCelula;

typedef struct
{
    int tamanho;
    tCelula *primeiro, *ultimo;
} tMonte;


/* Funções para acessar estrutura opaca */
// Retorna a quantidade de cartas do monte
int QuantidadeMonte(tMonte *monte);
// Retorna a carta de uma célula
tCarta Carta(tCelula *celula);

// Faz a lista (monte) ficar vazia
void FMVazio(tMonte *monte);

// Preenche o baralho com todas as cartas possíveis de um baralho padrão de bisca
void CriaBaralho(tMonte *monte);

// Verifica se o monte está vazia
int EstaVazio(tMonte *monte);

// Cria uma célula vazia e retorna-a
tCelula CriaCelulaVazia();

// Verifica se uma carta existe no monte
int ExisteCarta(tCarta x, tMonte *monte);

// Insere uma carta no monte
void Insere(tCarta x, tMonte *monte);

// Retira uma carta do monte e retorna o elemento por referência
void Retira(tCarta x, tMonte *monte, tCarta *cartaRetirada);

// Retira a primeira carta do monte e retorna o elemento por referência
void Pop(tMonte *monte, tCarta *cartaRetirada);

// "Corta" uma carta
tCarta Corta(tMonte *monte, int pos);

// Troca a célula de uma carta do monte com outra célula
void TrocaCarta(tMonte *monte, tCelula *celula, int pos);

// Embaralha as cartas das células em um monte
void Embaralha(tMonte *monte);

// Imprime as cartas do monte
void ImprimeMonte(tMonte *monte);

// Libera as células de um monte e define seu tamanho para 0
void DestroiMonte(tMonte *monte);

// Retorna uma carta do monte dado um índice
tCarta CartaNoIndice(int pos, tMonte *monte);

// Manda uma carta do monte para a mão
void MonteParaMao(tCarta *carta, tMonte *monte, tMao *mao);

// Manda uma carta da mão para o monte
void MaoParaMonte(tCarta carta, tMonte *monte, tMao *mao);

// Retorna a pontuação de uma carta
int PontuacaoCarta(tCarta x);

// Retorna o total de pontos das cartas de um monte
int ContaPontos(tMonte *monte);

#endif
