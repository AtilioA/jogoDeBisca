/*
 * Esta biblioteca contém o código que permite simular um jogo de bisca.
 * Possui funções que exibem informações sobre o jogo, além de abstrair
 * os conceitos do jogo, como jogador, carta, etc. em estruturas de dados
 * utilizadas pelo algoritmo.
 *
 * Utiliza outras bibliotecas para assim ser possível montar uma partida
 * e também concede estruturas de dados construídas aqui para outras bibliotecas. (?)
 *
 * EM CONSTRUÇÃO
 *
 */

/* Módulo com funções para manipulação do jogo (menu, etc) */

// Guard para evitar dupla inclusão
#ifndef __JOGO_H
#define __JOGO_H

#include "BaralhoEncadeado.h"

// Estrutura de dados que abstrai um jogador, que possui "mão" e pontuação
typedef struct tJogador tJogador;
struct tJogador
{
    tMao mao;
    tMonte pontos;
    tJogador *prox;
};

typedef struct
{
    int nJogadores;
    tCarta corte;
    tMonte monte;
    tJogador *inicial;
} tPartida;

void CriaJogador (tJogador *anterior);

void CriaPartida (tPartida *partida, int nJogadores);

/* Funções para acessar estrutura opaca */
int QuantidadeJogadores (tPartida *partida);
tJogador *JogadorInicial(tPartida *partida);
tMonte Monte(tPartida *partida);
tCarta Corte(tPartida *partida);
tMonte Pontuacao(tJogador *jogador);
tMao Mao(tJogador *jogador);

// Exibe o menu principal do jogo
void exibeMenu(/* carta *baralho */);

// Imprime informações de ajuda para o jogador
void exibeAjuda();

// Imprime opções extras (para quando o modo de desenvolvedor estiver ativo)
void exibeMenuDev();

// Exibe informações sobre o estado do jogo
void exibeInfo(tMonte *monte, tJogador *jogadores, int nJogadores);

void Joga(tMonte *monte, int modoDev, int nJogadores);

#endif
