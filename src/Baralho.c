#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/Baralho.h"
#include "../include/Jogo.h"

// Define os valores possíveis para número e naipe das cartas do baralho
#define VALORES "A234567QJK"
#define NAIPES "COPE"

void FLVazia(tLista *lista)
{
    lista->primeiro = (tLista *)malloc(sizeof(tCelula));
    lista->ultimo = lista->primeiro;
    lista->primeiro->prox = NULL;
}

int estaVazia(tLista lista)
{
    if (lista.primeiro == lista.ultimo)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

void insere(tCarta x, tLista *lista)
{
    lista->ultimo->prox = (tCelula *)malloc(sizeof(tCelula));
    lista->ultimo = lista->ultimo->prox; // ?
    lista->ultimo->carta = x;
    lista->ultimo->prox == NULL;
}

void retira(tCelula *p, tLista *lista, tCarta *carta)
{
    tCelula *q;

    if (estaVazia(*lista) || p == NULL || p->prox == NULL)
    {
        printf("Erro: lista vazia ou posicao nao existe.\n");
        return;
    }

    q = p->prox;
    *carta = q->carta;
    p->prox = q->prox;

    if (p->prox == NULL)
    {
        lista->ultimo = p;
    }

    free(q); // ?
}

void imprimeLista(tLista lista)
{
    tCelula *aux;
    aux = (lista.primeiro->prox);

    // Percorre a lista até chegar em NULL
    for (aux; aux != NULL; aux = aux->prox)
    {
        printf("%i", aux->carta.chave); // ?
    }
}


tCarta *escreveBaralho()
{
    int posNaipe = 0, posValor = 0;
    tCarta *baralho;

    baralho = (tCarta *)malloc(40 * sizeof(tCarta));
    if (baralho == NULL)
    {
        return (NULL);
    }

    srand(time(NULL)); // Inicializa o gerador de números aleatórios com o valor da função time(NULL)
    for (int i = 0; i < 40; i++)
    {
        posValor = i % 10;
        posNaipe = i / 10;

        baralho[i].valor = VALORES[posValor];
        baralho[i].naipe = NAIPES[posNaipe];
    }

    return (baralho);
}

void imprimeMao(tJogador p)
{
    // int i = 0, nCartasMao = 3;

    // imprimeBaralho(p.mao, nCartasMao);

    // for (i = 0; i < nCartasMao; i++)
    // {
    //     printf("%c", p.mao[i].valor);
    //     printf("%c", p.mao[i].naipe);
    // }
}

void imprimeBaralho(tCarta *baralho, int nCartas)
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

void embaralhaBaralho(tCarta *baralho)
{
    int posAleatoria = 0;
    tCarta aux;

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
