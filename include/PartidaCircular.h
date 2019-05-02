#ifndef __PARTIDACIRCULAR_H
#define __PARTIDACIRCULAR_H

#include "BaralhoEncadeado.h"

// Estrutura de dados que abstrai um jogador, que possui "mão" e pontuação
typedef struct tJogador tJogador;
struct tJogador
{
    tMao mao;
    tMonte pontos;
    tJogador *prox;
};

// Estrutura de dados que abstrai uma partida, que possui monte, número de jogadores, corte e jogador inicial da rodada
typedef struct
{
    int nJogadores;
    tCarta corte;
    tMonte *monte;
    tJogador *inicial;
} tPartida;

tJogador *InsereJogador (tJogador *jogador);

void PreparaPartida (tPartida *partida, int nJogadores);

void DestroiPartida (tPartida *partida);

void MoveCabeca (tPartida *partida, int pos);

/* Funções para acessar estrutura opaca */
// Retorna a quantidade de jogadores de uma partida
int QuantidadeJogadores (tPartida *partida);
// Retorna o jogador inicial atual de uma partida
tJogador *JogadorInicial(tPartida *partida);
// Retorna o monte de uma  partida
tMonte *Monte(tPartida *partida);
// Retorna o corte de uma partida
tCarta Corte(tPartida *partida);
// Retorna a pontuação de um jogador
tMonte Pontuacao(tJogador *jogador);
// Retorna a mão de um jogador
tMao Mao(tJogador *jogador);

#endif
