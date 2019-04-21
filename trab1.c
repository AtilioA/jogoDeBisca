/*
                  ＴＲＡＢＡＬＨＯ　ＥＤ　Ｉ
        Atílio Antônio Dadalto e Leandro Furlam Turi
                       Data: 05/2019                        */

#include <stdio.h>
#include <stdlib.h>
#include "include/BaralhoEncadeado.h"
#include "include/Jogo.h"

int main()
{

    tLista lista;
    tCarta carta;

    FLVazia(&lista);
    printf("Lista vazia criada com sucesso!\n");

    printf("Inserindo cartas...\n");
    carta = criaCarta('1', 'C');
    insere(carta, &lista);
    carta = criaCarta('4', 'O');
    insere(carta, &lista);
    carta = criaCarta('7', 'C');
    insere(carta, &lista);
    carta = criaCarta('A', 'C');
    insere(carta, &lista);
    carta = criaCarta('K', 'E');
    insere(carta, &lista);
    carta = criaCarta('J', 'P');
    insere(carta, &lista);

    printf("Imprimindo a lista:\n");
    imprimeLista(&lista);

    printf("\nRetirando carta de valor 7, naipe copas...\n");
    retira('7', 'C', &lista, &carta);
    printf("Imprimindo a lista:\n");
    imprimeLista(&lista);
    printf("Carta retirada:\n");
    imprimeCarta(&carta);

    printf("\nRetirando carta de valor 7, naipe espadas...\n");
    tCarta carta2;
    retira('7', 'E', &lista, &carta2);
    printf("Imprimindo a lista:\n");
    imprimeLista(&lista);
    printf("Carta retirada:\n");
    imprimeCarta(&carta2); // ???

    printf("\nRecuperando carta de valor J, naipe paus...\n");
    tCarta carta3;
    recupera('J', 'P', &lista, &carta3);
    printf("Imprimindo a lista:\n");
    imprimeLista(&lista);
    printf("Carta retirada:\n");
    imprimeCarta(&carta3);

    destroiLista(&lista);
    printf("Lista destruida com sucesso!\n");
    imprimeLista(&lista); // Não printa pois a lista está vazia


    // tJogador euzinho;
    // euzinho.mao[0].valor = '2';
    // euzinho.mao[0].naipe = 'C';
    // euzinho.mao[1].valor = '9';
    // euzinho.mao[1].naipe = 'O';
    // euzinho.mao[2].valor = '3';
    // euzinho.mao[2].naipe = 'P';

    // tCarta *baralho;

    // baralho = escreveBaralho();
    // imprimeBaralho(baralho, 40);

    // embaralhaBaralho(baralho);
    // imprimeBaralho(baralho, 40);

    // imprimeMao(euzinho);
    // exibeMenu();

    // free(baralho);

    return 0;
}
