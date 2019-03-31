/* Módulo com funções para manipulação do jogo (menu, etc) */

// Guard para evitar dupla inclusão
#ifndef __JOGO_H
#define __JOGO_H

// Estrutura de dados que abstrai uma carta, que possui valor e naipe
typedef struct
{
    char valor;
    char naipe;
} tCarta;

// Estrutura de dados que abstrai um jogador, que possui "mão" e pontuação
typedef struct
{
    tCarta mao[3];
    int pontuacao;
} tJogador;

void exibeMenu(/* carta *baralho */);
void exibeInfo(tJogador *jogadores, int nJogadores);
void exibeMenuDev();
void exibeAjuda();

#endif
