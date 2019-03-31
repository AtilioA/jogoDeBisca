/*
                  ＴＲＡＢＡＬＨＯ　ＥＤ　Ｉ
        Atílio Antônio Dadalto e Leandro Furlam Turi
                       Data: 05/2019                        */

#include <stdio.h>
#include <stdlib.h>
#include "include/Baralho.h"
#include "include/Jogo.h"

int main()
{
    // Teste de mão de um jogador
    tJogador euzinho;
    euzinho.mao[0].valor = '2';
    euzinho.mao[0].naipe = 'C';
    euzinho.mao[1].valor = '9';
    euzinho.mao[1].naipe = 'O';
    euzinho.mao[2].valor = '3';
    euzinho.mao[2].naipe = 'P';

    // tCarta *baralho;

    // baralho = escreveBaralho();
    // imprimeBaralho(baralho, 40);

    // embaralhaBaralho(baralho);
    // imprimeBaralho(baralho, 40);

    imprimeMao(euzinho);
    exibeMenu();

    // free(baralho);

    return 0;
}
