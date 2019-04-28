/*
 * Esta biblioteca contém o código que implementa funções mais básicas
 * relevantes ao baralho de uma partida de bisca.
 *
 */

// Guard para evitar dupla inclusão
#ifndef __BARALHO_ENCADEADO_H
#define __BARALHO_ENCADEADO_H

#include <sys/time.h>
#include "../include/Cartas.h"

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


<<<<<<< HEAD
void FMVazio (tMonte *monte);
void CriaBaralho (tMonte *monte);
int EstaVazio (tMonte *monte);
tCelula CriaCelulaVazia ( );
int QuantidadeMonte (tMonte *monte);
void Insere (tCarta x, tMonte *monte);
void Retira (char valor, char naipe, tMonte *monte, tCarta *cartaRetirada);
void Corta (char valor, char naipe, tMonte *monte, tCarta *cartaCorte);
int Recupera (char valor, char naipe, tMonte *monte);
void MoveCelula (tMonte *monte, tCelula *celula, int pos);

// Para cada célula da monte, gerar uma posição aleatória dentro da monte e mover a célula pra esta posição
void Embaralha (tMonte *monte);
void ImprimeMonte (tMonte *monte);
void DestroiMonte (tMonte *monte);
/* implementando: */

void Pop (tMonte *monte, tCarta *cartaRetirada);
void Deleta (char valor, char naipe, tMonte *monte);
void DeletaNaipe (char naipe, tMonte *monte);
void DeletaValor (char valor, tMonte *monte);
int IndiceCarta (char valor, char naipe, tMonte *monte);
tCarta CartaNoIndice (int pos, tMonte *monte);
void SwapCelulas (int pos1, int pos2, tMonte *monte);
=======
// Faz a lista (monte) ficar vazia
void FMVazio(tMonte *monte);

// Preenche o baralho com todas as cartas possíveis de um baralho padrão de bisca
void CriaBaralho(tMonte *monte);

// Verifica se o monte está vazia
int EstaVazio(tMonte *monte);

// Cria uma célula vazia e retorna-a
tCelula CriaCelulaVazia();

// Retorna a quantidade de elementos dentro do monte
int QuantidadeMonte(tMonte *monte);

// Insere uma carta no monte
void Insere(tCarta x, tMonte *monte);

// Retira uma carta do monte e retorna o elemento por referência
void Retira(char valor, char naipe, tMonte *monte, tCarta *cartaRetirada);

// "Corta" uma carta (caso específico da função retira)
void Corta(char valor, char naipe, tMonte *monte, tCarta *cartaCorte);

// Retorna o naipe de uma carta
int Recupera(char valor, char naipe, tMonte *monte);

// Move uma célula do monte para outra posição
void MoveCelula(tMonte *monte, tCelula *celula, int pos);

// Embaralha as posições das células em umo monte
void Embaralha(tMonte *monte);

// Imprime as cartas do monte
void ImprimeMonte(tMonte *monte);

// Libera as células de um monte e define seu tamanho para 0
void DestroiMonte(tMonte *monte);

void Pop(tMonte *monte, tCarta *cartaRetirada);

void Deleta(char valor, char naipe, tMonte *monte);

void DeletaNaipe(char naipe, tMonte *monte);

void DeletaValor(char valor, tMonte *monte);

// Retorna uma carta do monte dado um índice
int IndiceCarta(char valor, char naipe, tMonte *monte);

// Retorna o índice de uma dada carta do monte
tCarta CartaNoIndice(int pos, tMonte *monte);

// Troca duas células de posição no monte
void SwapCelulas(int pos1, int pos2, tMonte *monte);
>>>>>>> 6814b84a38007cc8fedb2f65d1d302fc569b21d6

#endif
