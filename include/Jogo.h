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
#include "PartidaCircular.h"

void CriaPartida (int nJogadores, tPartida *partida, tMonte *baralho);

// Exibe informações sobre o estado do jogo
void exibeInfo (tPartida *partida);

// Imprime informações de ajuda para o jogador
void exibeAjuda();

// Imprime opções extras (para quando o modo de desenvolvedor estiver ativo)
void exibeMenuDev (tPartida *partida);

void exibeMenu ( );

#endif
