#ifndef __PARTIDACIRCULAR_H
#define __PARTIDACIRCULAR_H

#define HUMANO 0
#define IA 1

#include "BaralhoEncadeado.h"
#include "IA4Jogadores.h"

// Estrutura de dados que abstrai um jogador, que possui "mão" e pontuação
typedef struct tJogador tJogador;
struct tJogador
{
    int PC;
    int indice;
    tMao mao;
    tMonte pontos;
    tJogador *prox;
};

// Estrutura de dados que abstrai uma partida, que possui monte, número de jogadores, corte e jogador inicial da rodada
typedef struct
{
    int nJogadores;
    int modoDev;
    tCarta corte;
    tMonte *monte;
    tMonte *mesa;
    tJogador *inicial;
} tPartida;

// Manda as cartas mesa para o jogador que ganhou a rodada (contando como pontuação deste)
void MandaPontosJogador(tJogador *vencedor, tMonte *mesa);

tJogador *InsereJogador (tJogador *jogador);

void PreparaPartida (tPartida *partida, int nJogadores, int posHumano);

void DestroiPartida (tPartida *partida);

void MoveCabeca (tPartida *partida, int pos);

// Imprime as pontuações de todos os jogadores da partida
void ImprimePontuacao(tPartida *partida);

// Pede para o jogador qual carta quer jogar na mesa e realiza o procedimento
tCarta JogaCartaHumano(tPartida *partida, tJogador *humano);

int IndiceJogador(tJogador *jogador);

int Vencedor (tPartida *partida);

/* Funções para acessar estrutura opaca */
// Retorna a quantidade de jogadores de uma partida
int QuantidadeJogadores (tPartida *partida);
// Retorna o jogador inicial atual de uma partida
tJogador *JogadorInicial(tPartida *partida);
// Retorna o baralho de uma partida
tMonte *Baralho(tPartida *partida);
// Retorna o corte de uma partida
tCarta Corte(tPartida *partida);
// Retorna a pontuação de um jogador
tMonte *Pontuacao(tJogador *jogador);
// Retorna a mão de um jogador
tMao *Mao(tJogador *jogador);
// Retorna a mesa de uma partida
tMonte *Mesa(tPartida *partida);
// Retorna se a partida está em modo de desenvolvedor
int *ModoDev(tPartida *partida);
// Retorna se o jogador é um humano ou computador
int PC(tJogador *jogador);

#endif
