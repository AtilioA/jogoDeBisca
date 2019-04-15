/*
 * Esta biblioteca contém o código que permite simular um jogo de bisca.
 * Possui funções que exibem informações sobre o jogo, além de abstrair
 * os conceitos do jogo, como jogador, carta, etc. em estruturas de dados
 * utilizadas pelo algoritmo.
 *
 * Utiliza outras bibliotecas para assim ser possível montar uma partida
 * e também concede estruturas de dados construídas aqui para outras bibliotecas.
 *
 * EM CONSTRUÇÃO
 *
 */

/* Módulo com funções para manipulação do jogo (menu, etc) */

// Guard para evitar dupla inclusão
#ifndef __JOGO_H
#define __JOGO_H

#include "Baralho.h"

typedef int Posicao;

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

// Estrutura de dados que abstrai um jogador, que possui "mão" e pontuação
typedef struct
{
    tBaralho mao;
    int pontuacao;
} tJogador;


// Exibe o menu principal do jogo
void exibeMenu(/* carta *baralho */);

// Imprime informações de ajuda para o jogador
void exibeAjuda();

// Imprime opções extras (para quando o modo de desenvolvedor estiver ativo)
void exibeMenuDev();

// Exibe informações sobre o estado do jogo
void exibeInfo(tJogador *jogadores, int nJogadores);


#endif
