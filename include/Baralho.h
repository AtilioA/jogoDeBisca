/* Módulo com funções para manipulação do baralho */

// Guard para evitar dupla inclusão
#ifndef __BARALHO_H
#define __BARALHO_H

typedef struct
{
    char valor;
    char naipe;
} carta;

// Cria o vetor com todas as cartas do baralho
carta *escreveBaralho();

// Exibe todas as cartas de um baralho
void imprimeBaralho(carta *baralho, int nCartas);

// Rearranja as cartas de um baralho em ordem aleatória
void embaralhaBaralho(carta *baralho);

#endif
