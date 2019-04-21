/*
 * Esta biblioteca contém o código que permite manipular o baralho de um jogo de bisca.
 * Auxilia a biblioteca Jogo.h. Esta biblioteca é mais específica,
 * lidando com funções mais básicas relevantes a uma partida.
 *
 * EM CONSTRUÇÃO
 *
 */


// Guard para evitar dupla inclusão
#ifndef __BARALHO_ENCADEADO_H
#define __BARALHO_ENCADEADO_H


// Define os valores possíveis para número e naipe das cartas do baralho
#define VALORES "23456QJK7A"
#define NAIPES "COPE"
#define nVALORES 10
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

// Faz a lista ficar vazia
void FLVazia(tLista *lista);

// Verifica se a lista está vazia
int estaVazia(tLista *lista);

int cartaValida(tCarta *carta);

// Cria uma carta e retorna-a
tCarta criaCarta(char valor, char naipe);

// Cria uma carta vazia e retorna-a
tCarta criaCartaVazia();

// Preenche uma carta já existente
void preencheCarta(char valor, char naipe, tCarta *carta);

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

// Retorna uma carta da lista por referência
void recupera(char valor, char naipe, tLista *lista, tCarta *cartaRetirada);

// Imprime uma carta
void imprimeCarta(tCarta *carta);

// Com caracteres dos naipe
void imprimeCartaLinux(tCarta carta);

// Imprime as cartas da lista
void imprimeLista(tLista *lista);

void destroiLista(tLista *lista);

#endif
