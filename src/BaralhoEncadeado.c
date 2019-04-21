#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/BaralhoEncadeado.h"
#include "../include/Jogo.h"

void FLVazia(tLista *lista)
{
    lista->primeiro = (tCelula *)malloc(sizeof(tCelula)); // lista->primeiro será a cabeça da lista
    lista->ultimo = lista->primeiro;
    lista->ultimo->prox = NULL;
    lista->tamanho = 0;
}

int estaVazia(tLista *lista)
{
    if (lista->primeiro )
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

int cartaValida(tCarta *carta)
{
    if ((carta->naipe == NAIPES[0]) ||
        (carta->naipe == NAIPES[1]) ||
        (carta->naipe == NAIPES[2]) ||
        (carta->naipe == NAIPES[3]))
    {
        for (int i = 0; i < nVALORES; i++)
        {
            if (carta->valor == VALORES[i])
            {
                return 1;
            }
        }
    }

    return 0;
}

tCarta criaCarta(char valor, char naipe)
{
    tCarta cartinhaDeGwent;

    cartinhaDeGwent.valor = valor;
    cartinhaDeGwent.naipe = naipe;

    return cartinhaDeGwent;
}

tCarta criaCartaVazia()
{
    tCarta cartinhaVaziaDeGwent;

    cartinhaVaziaDeGwent.valor = ' ';
    cartinhaVaziaDeGwent.naipe = ' ';

    return cartinhaVaziaDeGwent;
}

void preencheCarta(char valor, char naipe, tCarta *carta)
{
    if (!(cartaValida(carta)))
    {
        carta->valor = carta->naipe = ' ';
    }
    else
    {
        carta->valor = valor;
        carta->naipe = naipe;
    }
}

int quantidadeLista(tLista *lista)
{
    return lista->tamanho;
}

char valorCarta(tCarta *carta)
{
    if (!(cartaValida(carta)))
    {
        return (' ');
    }
    else
    {
        return carta->valor;
    }
}

char naipeCarta(tCarta *carta)
{
    if (!(cartaValida(carta)))
    {
        return (' ');
    }
    else
    {
        return carta->naipe;
    }
}

void insere(tCarta x, tLista *lista)
{
    //? Precisa verificar carta já existente?
    lista->ultimo->prox = (tCelula *)malloc(sizeof(tCelula));
    lista->ultimo = lista->ultimo->prox;
    lista->ultimo->carta = x;
    lista->ultimo->prox = NULL;

    lista->tamanho++;
}

void retira(char valor, char naipe, tLista *lista, tCarta *cartaRetirada)
{
    tCelula *anterior = NULL;
    tCelula *atual = lista->primeiro;

    while (atual != NULL && (atual->carta.valor != valor || atual->carta.naipe != naipe))
    {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL)
    {
        printf("Nao existe a carta especificada!\n");
        *cartaRetirada = criaCartaVazia();
    }
    else
    {
        anterior->prox = atual->prox;
        *cartaRetirada = atual->carta;
        free(atual);
        lista->tamanho--;
    }
}

void recupera(char valor, char naipe, tLista *lista, tCarta *cartaRecuperada)
{
    tCelula *anterior = NULL;
    tCelula *atual = lista->primeiro;

    while (atual != NULL && (atual->carta.valor != valor || atual->carta.naipe != naipe))
    {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL)
    {
        printf("Nao existe a carta especificada!\n");
    }
    else
    {
        *cartaRecuperada = atual->carta;
    }
}

void imprimeCarta(tCarta *carta)
{
    if (cartaValida(carta))
    {
        printf("Carta %c %c\n", carta->valor, carta->naipe);
    }
    else
    {
        printf("A carta nao e valida.\n");
    }
}

void imprimeCartaLinux(tCarta carta)
{
    printf("%c", carta.valor);

    // Não funciona em Windows
    if (carta.naipe == 'C')
    {
        printf("\u2665\n");
    }
    else if (carta.naipe == 'O')
    {
        printf("\u2666\n");
    }
    else if (carta.naipe == 'P')
    {
        printf("\u2663\n");
    }
    else if (carta.naipe == 'E')
    {
        printf("\u2660\n");
    }
}

// Usando imprimeCarta
void imprimeLista(tLista *lista)
{
    if (!(estaVazia(lista)))
    {
        tCelula *atual = NULL;

        printf("Quantidade de itens: %i\n", quantidadeLista(lista));
        // Percorre a lista até chegar em NULL
        for (atual = lista->primeiro; atual != NULL; atual = atual->prox)
        {
            imprimeCarta(&atual->carta);
        }
    }
}

void destroiLista(tLista *lista)
{
    tCelula *anterior = NULL;
    tCelula *atual = lista->primeiro;

    while (atual != NULL)
    {
        anterior = atual;
        atual = atual->prox;
        free(anterior);
    }

    lista->tamanho = 0;
}
