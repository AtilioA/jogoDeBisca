#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "../include/BaralhoEncadeado.h"
#include "../include/Jogo.h"

void FLVazia(tLista *lista)
{
    lista->primeiro = (tCelula *)malloc(sizeof(tCelula)); // lista->primeiro será a cabeça da lista
    lista->ultimo = lista->primeiro;
    lista->ultimo->prox = NULL;
    lista->tamanho = 0;
}

void criaListaBaralho(tLista *lista)
{
    FLVazia(lista);

    int nCartas = 1, i = 0, j = 0;
    tCelula *atual = lista->primeiro->prox;

    for (i = 0; i < nVALORES; i++)
    {
        for (j = 0; j < nNAIPES; j++)
        {
            tCarta atual = criaCarta(VALORES[i], NAIPES[j]);
            insere(atual, lista);
        }
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

    for (int i = 0; i < 40; i++)
    {
        posValor = i % 10;
        posNaipe = i / 10;

        baralho[i].valor = VALORES[posValor];
        baralho[i].naipe = NAIPES[posNaipe];
    }

    return (baralho);
}

int estaVazia(tLista *lista)
{
    return (lista->primeiro == lista->ultimo);
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

tCelula criaCelulaVazia()
{
    tCelula celulaVazia;

    celulaVazia.prox = NULL;
    celulaVazia.carta = criaCartaVazia();

    return celulaVazia;
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

void corta(char valor, char naipe, tLista *lista, tCarta *cartaCorte)
{
    if (valor != 'A' && valor != '7')
    {
        retira(valor, naipe, lista, cartaCorte);
    }
    else
    {
        printf("Nao e permitido cortar As ou 7\n");
    }

    // ???
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

void moveCelula(tLista *lista, tCelula *celula, int pos)
{
    int i = 1;

    if (pos < quantidadeLista(lista))
    {
        tCelula *atual = lista->primeiro;
        tCelula *anterior = NULL;
        while (atual != NULL && atual != celula)
        {
            anterior = atual;
            atual = atual->prox;
            // printf("Buscando celula original...\n");
        }

        if (atual == NULL)
        {
            printf("Nao foi possivel chegar na celula original!\n");
        }
        else
        {
            anterior->prox = celula->prox;
        }

        if (pos == 1)
        {
            tCelula *aux = malloc(sizeof(tCelula));
            aux = lista->primeiro->prox;
            aux->prox = lista->primeiro->prox->prox;
            celula->prox = aux;
            lista->primeiro->prox = celula;
        }
        else
        {
            atual = lista->primeiro->prox;
            anterior = NULL;
            while (atual != NULL && i < pos)
            {
                i++;
                anterior = atual;
                atual = atual->prox;
                // printf("Buscando posicao destino...\n");
            }

            if (atual == NULL)
            {
                printf("Nao foi possivel chegar na posicao!\n");
            }
            else
            {
                anterior->prox = celula;
                celula->prox = atual;
            }
        }
    }
    else
    {
        printf("A posicao fica fora da lista.\n");
    }
}

// Para cada célula da lista, gerar uma posição aleatória dentro da lista e mover a célula pra esta posição
void embaralhaLista(tLista *lista)
{
    struct timeval t;
    int posAleatoria = 0, tamLista = quantidadeLista(lista);
    tCelula *anterior = NULL;
    tCelula *atual = lista->primeiro->prox;

    gettimeofday(&t,NULL);
    srand((unsigned int)t.tv_usec); // Inicializa o gerador de números aleatórios com o valor da função time(NULL)

    if (tamLista != 0)
    {
        while (atual != NULL)
        {
            anterior = atual;
            atual = atual->prox;

            posAleatoria = rand() % tamLista;
            if (posAleatoria < 1) // ??? Precisa disso mas não sei por quê
            {
                posAleatoria = 1;
            }
            // printf("%i, %i\n\n", tamLista, posAleatoria);
            moveCelula(lista, anterior, posAleatoria);
        }
    }
}

void imprimeCarta(tCarta *carta)
{
    char valor = valorCarta(carta);
    char naipe = naipeCarta(carta);

    if (cartaValida(carta))
    {
        printf("Carta %c %c\n", valor, naipe);
    }
    else
    {
        printf("A carta nao e valida.\n");
    }
}

void imprimeCartaLinux(tCarta carta)
{
    char valor = valorCarta(&carta);
    char naipe = naipeCarta(&carta);

    printf("%c", valor);

    // Não funciona em Windows
    if (naipe == 'C')
    {
        printf("\u2665\n");
    }
    else if (naipe == 'O')
    {
        printf("\u2666\n");
    }
    else if (naipe == 'P')
    {
        printf("\u2663\n");
    }
    else if (naipe == 'E')
    {
        printf("\u2660\n");
    }
}

// Usando imprimeCarta
void imprimeLista(tLista *lista)
{
    if (quantidadeLista(lista) != 0)
    {
        tCelula *atual = NULL;

        printf("Quantidade de itens: %i\n", quantidadeLista(lista));
        for (atual = lista->primeiro->prox; atual != NULL; atual = atual->prox)
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

/* implementar: */
void pop(tLista *lista, tCarta *cartaRetirada);
void deleta(char valor, char naipe, tLista *lista);
void deletaNaipe(char naipe, tLista *lista);
void deletaValor(char valor, tLista *lista);
int indiceCarta(char valor, char naipe, tLista *lista);
tCarta cartaNoIndice(int pos, tLista *lista);
void swapCelulas (int pos1, int pos2, tLista *lista);
