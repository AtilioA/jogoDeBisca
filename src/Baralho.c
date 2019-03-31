#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// #include "../include/modulo2.h"

// Define os valores possíveis para número e naipe das cartas do baralho
#define VALORES "A234567QJK"
#define NAIPES "COPE"

typedef struct
{
    char valor;
    char naipe;
} carta;

carta *escreveBaralho();
void imprimeBaralho(carta *baralho, int nCartas);
void embaralhaBaralho(carta *baralho);

carta *escreveBaralho()
{
    int posNaipe = 0, posValor = 0;
    carta *baralho;

    baralho = (carta *)malloc(40 * sizeof(carta));
    if (baralho == NULL)
    {
        return (NULL);
    }

    srand(time(NULL));  // Inicializa o gerador de números aleatórios com o valor da função time(NULL)
    for (int i = 0; i < 40; i++)
    {
        posValor = i % 10;
        posNaipe = i / 10;

        baralho[i].valor = VALORES[posValor];
        baralho[i].naipe = NAIPES[posNaipe];
    }

    return (baralho);
}

void imprimeBaralho(carta *baralho, int nCartas)
{
    if (baralho == NULL)
    {
        return;
    }

    for (int i = 0; i < nCartas; i++)
    {
        // printf("%c%c\n", baralho[i].valor, baralho[i].naipe);
        printf("%c", baralho[i].valor);

        // Não funciona em Windows
        if (baralho[i].naipe == 'C')
        {
            printf("\u2665\n");
        }
        else if (baralho[i].naipe == 'O')
        {
            printf("\u2666\n");
        }
        else if (baralho[i].naipe == 'P')
        {
            printf("\u2663\n");
        }
        else if (baralho[i].naipe == 'E')
        {
            printf("\u2660\n");
        }
    }
    printf("\n");
}

void embaralhaBaralho(carta *baralho)
{
    int posAleatoria = 0;
    carta aux;

    if (baralho == NULL)
    {
        return;
    }

    for (int i = 0; i < 40; i++)
    {
        posAleatoria = rand() % 40;
        aux = baralho[i];
        baralho[i] = baralho[posAleatoria];
        baralho[posAleatoria] = aux;
    }
}
