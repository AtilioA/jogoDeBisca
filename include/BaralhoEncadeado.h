/*
 * Esta biblioteca contém o código que implementa funções mais básicas
 * relevantes ao baralho de uma partida de bisca.
 *
 */

// Guard para evitar dupla inclusão
#ifndef __BARALHO_ENCADEADO_H
#define __BARALHO_ENCADEADO_H

// Define os valores possíveis para número e naipe das cartas do baralho
#define VALORES "23456QJK7A"
#define NAIPES "COPE"
#define nVALORES 10
#define nNAIPES 4
// Número padrão de cartas em uma mão
#define nMAO 3

#include "Jogo.h"

// Estrutura de dados que abstrai uma carta, que possui valor e naipe
typedef struct tCarta
{
    char valor;
    char naipe;
} tCarta;

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
} tLista;
// Ou tMonte

// Move uma célula para uma dada posição na lista
void moveCelula(tLista *lista, tCelula *celula, int pos);

// Embaralha as posições das células em uma lista
void embaralhaLista(tLista *lista);

// Faz a lista ficar vazia
void FLVazia(tLista *lista);

// Verifica se a lista está vazia
int estaVazia(tLista *lista);

// Verifica se uma carta é válida
int cartaValida(tCarta *carta);

// Cria uma carta e retorna-a
tCarta criaCarta(char valor, char naipe);

// Cria uma carta vazia e retorna-a
tCarta criaCartaVazia();

// Preenche uma carta já existente
void preencheCarta(char valor, char naipe, tCarta *carta);

// Preenche uma lista com todas as cartas possíveis de um baralho padrão de bisca
void criaListaBaralho(tLista *lista);

// Retorna a quantidade de elementos dentro da lista encadeada
int quantidadeLista(tLista *lista);

// Retorna o valor de uma carta
char valorCarta(tCarta *carta);

// Retorna o naipe de uma carta
char naipeCarta(tCarta *carta);

// Insere uma carta na lista
void insere(tCarta x, tLista *lista);

// Retira uma carta da lista e retorna o elemento por referência
void retira(char valor, char naipe, tLista *lista, tCarta *cartaRetirada);

// "Corta" uma carta (caso específico da função retira)
void corta(char valor, char naipe, tLista *lista, tCarta *cartaCorte);

// Retorna uma carta da lista por referência
void recupera(char valor, char naipe, tLista *lista, tCarta *cartaRetirada);

// Imprime uma carta
void imprimeCarta(tCarta *carta);

// Com caracteres dos naipe
void imprimeCartaLinux(tCarta carta);

// Imprime as cartas da lista
void imprimeLista(tLista *lista);

// Libera as células de uma lista e define seu tamanho para 0
void destroiLista(tLista *lista);

#endif
