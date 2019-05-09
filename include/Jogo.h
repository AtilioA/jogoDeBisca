/*
 * Esta biblioteca contém o código que permite simular um jogo de bisca.
 * Possui funções que coordenam funções de outras bibliotecas para formar
 * um jogo de bisca, além de funções que exibem informações sobre o jogo.
 */

// Guard para evitar dupla inclusão
#ifndef __JOGO_H
#define __JOGO_H

#include "BaralhoEncadeado.h"
#include "PartidaCircular.h"

tPartida *CriaPartida(int nJogadores, tMonte *baralho);

// Exibe o menu inicial do jogo com suas devidas opções
void ExibeMenuInicial(tPartida *partida);

// Exibe o menu que aparece durante o jogo e suas devidas opções
tCarta MenuPartida(tPartida *partida, tMonte *baralho, tJogador *humano);

// Distribui cartas do baralho para todos os jogadores da partida, de forma que todos tenham 3 cartas na mão
void DistribuiCartas(tPartida *partida, int n, tMonte *baralho);

// Exibe informações sobre o estado do jogo
void exibeInfo(tPartida *partida);

// Imprime informações de ajuda para o jogador
void exibeAjuda();

void Partida(tPartida *partida, tMonte *baralho);

void FinalizaPartida(tPartida *partida);

// Limpa a tela do terminal (para Windows E Linux)
void clrscr();

// Imprime o estado da mesa (Corte e cartas na mesa)
void ImprimeMesa(tPartida *partida);

#endif
