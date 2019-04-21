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
    // criaListaBaralho(&lista);
    carta = criaCarta('2', 'C');
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

    // printf("Movendo a primeira carta para a terceira posicao...\n");
    // moveCelula(&lista, lista.primeiro->prox, 3);

    // printf("Imprimindo a lista:\n");
    // imprimeLista(&lista);

    // printf("Movendo a terceira carta para a primeira posicao...\n");
    // moveCelula(&lista, lista.primeiro->prox->prox->prox, 1);

    // printf("Imprimindo a lista:\n");
    // imprimeLista(&lista);

    // printf("Movendo a ultima carta para a primeira posicao...\n");
    // moveCelula(&lista, lista.ultimo, 1);

    // printf("\nRetirando carta de valor 7, naipe copas...\n");
    // retira('7', 'C', &lista, &carta);
    // printf("Imprimindo a lista:\n");
    // imprimeLista(&lista);
    // printf("Carta retirada:\n");
    // imprimeCarta(&carta);

    // printf("\nRetirando carta de valor 7, naipe espadas...\n");
    // tCarta carta2;
    // retira('7', 'E', &lista, &carta2);
    // printf("Imprimindo a lista:\n");
    // imprimeLista(&lista);
    // printf("Carta retirada:\n");
    // imprimeCarta(&carta2);

    // printf("\nRecuperando carta de valor J, naipe paus...\n");
    // tCarta carta3;
    // recupera('J', 'P', &lista, &carta3);
    // printf("Imprimindo a lista:\n");
    // imprimeLista(&lista);
    // printf("Carta recuperada:\n");
    // imprimeCarta(&carta3);

    printf("\nEmbaralhando lista...\n");
    embaralhaLista(&lista);
    printf("Imprimindo a lista:\n");
    imprimeLista(&lista);

    printf("\nEmbaralhando lista...\n");
    embaralhaLista(&lista);
    printf("Imprimindo a lista:\n");
    imprimeLista(&lista);

    destroiLista(&lista);
    printf("\nLista destruida com sucesso!\n");
    imprimeLista(&lista); // Não printa pois a lista está vazia

    return 0;
}
