/*
 * Esta biblioteca contém o código que implementa funções mais básicas
 * relevantes ao baralho de uma partida de bisca.
 *
 */

 #include <sys/time.h>
 #include "../include/Cartas.h"

// Guard para evitar dupla inclusão
#ifndef __BARALHO_ENCADEADO_H
#define __BARALHO_ENCADEADO_H


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


void FMVazio (tMonte *monte);
void CriaMonte (tMonte *monte);
int EstaVazio (tMonte *monte);
tCelula CriaCelulaVazia ( );
int QuantidadeMonte (tMonte *monte);
void Insere (tCarta x, tMonte *monte);
void Retira (char valor, char naipe, tMonte *monte, tCarta *cartaRetirada);
void Corta (char valor, char naipe, tMonte *monte, tCarta *cartaCorte);
int Recupera (char valor, char naipe, tMonte *monte);
void MoveCelula (tMonte *monte, tCelula *celula, int pos);
void Embaralha (tMonte *monte);
void ImprimeMonte (tMonte *monte);
void DestroiMonte (tMonte *monte);
void Pop (tMonte *monte, tCarta *cartaRetirada);
void Deleta (char valor, char naipe, tMonte *monte);
void DeletaNaipe (char naipe, tMonte *monte);
void DeletaValor (char valor, tMonte *monte);
int IndiceCarta (char valor, char naipe, tMonte *monte);
tCarta CartaNoIndice (int pos, tMonte *monte);
void SwapCelulas (int pos1, int pos2, tMonte *monte);

#endif
