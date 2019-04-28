#include "../include/Cartas.h"
#include "../include/BaralhoEncadeado.h"

void FMVazio (tMonte *monte)
{
    monte->primeiro = (tCelula *) malloc (sizeof (tCelula)); // monte->primeiro será a cabeça do monte
    monte->ultimo = monte->primeiro;
    monte->ultimo->prox = NULL;
    monte->tamanho = 0;
}

void CriaBaralho (tMonte *monte)
{
    FMVazio (monte);

    tCarta atual;

    for (int i = 0; i < nVALORES * nNAIPES; i ++)
    {
        atual = PreencheCarta (VALORES[i % 10], NAIPES[i / 10]);
        Insere (atual, monte);
    }
}

int EstaVazio (tMonte *monte)
{
    return (QuantidadeMonte (monte) == 0);
}

tCelula CriaCelulaVazia ( )
{
    tCelula celulaVazia;

    celulaVazia.carta = CartaVazia ( );
    celulaVazia.prox = NULL;

    return celulaVazia;
}

int QuantidadeMonte (tMonte *monte)
{
    return (monte->tamanho);
}

void Insere (tCarta x, tMonte *monte)
{
    //? Precisa verificar carta já existente? SIM
    monte->ultimo->prox = (tCelula *) malloc (sizeof (tCelula));
    monte->ultimo = monte->ultimo->prox;
    monte->ultimo->carta = x;
    monte->ultimo->prox = NULL;

    monte->tamanho ++;
}

void Retira (char valor, char naipe, tMonte *monte, tCarta *cartaRetirada)
{
    tCelula *atual = monte->primeiro;
    tCelula *anterior = NULL;

    while (atual != NULL && (atual->carta.valor != valor || atual->carta.naipe != naipe))
    {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL)
    {
        printf ("Nao existe a carta especificada!\n");
        *cartaRetirada = CartaVazia ( );
    }
    else
    {
        anterior->prox = atual->prox;
        *cartaRetirada = atual->carta;
        free (atual);
        monte->tamanho --;
    }
}

void Corta (char valor, char naipe, tMonte *monte, tCarta *cartaCorte)
{
    if (valor != 'A' && valor != '7')
    {
        Retira (valor, naipe, monte, cartaCorte);
    }
    else
    {
        printf ("Nao e permitido cortar As ou 7\n");
    }

    // ???
}

int Recupera (char valor, char naipe, tMonte *monte)
{
    tCelula *atual;

    for (atual = monte->primeiro ; atual != NULL; atual = atual->prox) {
        if ((Valor (atual->carta) == valor) && (Naipe (atual->carta) == naipe))
            return (1);
    }
    return (0);
}

void MoveCelula (tMonte *monte, tCelula *celula, int pos)
{
    int i = 1;

    if (pos < QuantidadeMonte(monte))
    {
        tCelula *atual = monte->primeiro;
        tCelula *anterior = NULL;
        while (atual != NULL && atual != celula)
        {
            anterior = atual;
            atual = atual->prox;
            // printf("Buscando celula original...\n");
        }

        if (atual == NULL)
        {
            printf ("Nao foi possivel chegar na celula original!\n");
        }
        else
        {
            anterior->prox = celula->prox;
        }

        if (pos == 1)
        {
            tCelula *aux = (tCelula *) malloc (sizeof (tCelula));
            aux = monte->primeiro->prox;
            aux->prox = monte->primeiro->prox->prox;
            celula->prox = aux;
            monte->primeiro->prox = celula;
        }
        else
        {
            atual = monte->primeiro->prox;
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
                printf ("Nao foi possivel chegar na posicao!\n");
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
        printf ("A posicao fica fora da monte.\n");
    }
}

// Para cada célula da monte, gerar uma posição aleatória dentro da monte e mover a célula pra esta posição
void Embaralha (tMonte *monte)
{
    struct timeval t;
    int posAleatoria = 0, tammonte = QuantidadeMonte (monte);
    tCelula *anterior = NULL;
    tCelula *atual = monte->primeiro->prox;

    gettimeofday (&t, NULL);
    srand ((unsigned int) t.tv_usec); // Inicializa o gerador de números aleatórios com o valor da função time(NULL)

    if (tammonte != 0)
    {
        while (atual != NULL)
        {
            anterior = atual;
            atual = atual->prox;

            posAleatoria = (rand ( ) % tammonte) + 1;

            // printf("%i, %i\n\n", tammonte, posAleatoria);
            MoveCelula (monte, anterior, posAleatoria);
        }
    }
}

// Usando imprimeCarta
void ImprimeMonte (tMonte *monte)
{
    if (QuantidadeMonte (monte) != 0)
    {
        tCelula *atual = NULL;

        printf ("Quantidade de itens: %i\n", QuantidadeMonte (monte));
        for (atual = monte->primeiro->prox; atual != NULL; atual = atual->prox)
            ImprimeCartaLinux  (atual->carta);
    }
}

void DestroiMonte (tMonte *monte)
{
    tCelula *anterior = NULL;
    tCelula *atual = monte->primeiro;

    while (atual != NULL)
    {
        anterior = atual;
        atual = atual->prox;
        free (anterior);
    }

    monte->tamanho = 0;
}

/* implementando: */

void Pop (tMonte *monte, tCarta *cartaRetirada);

void Deleta (char valor, char naipe, tMonte *monte)
{
    tCelula *atual = monte->primeiro;
    tCelula *anterior = NULL;

    while (atual != NULL && (atual->carta.valor != valor || atual->carta.naipe != naipe))
    {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual != NULL)
    {
        anterior->prox = atual->prox;
        free (atual);
    }
}

void DeletaNaipe (char naipe, tMonte *monte)
{
    int i = 0;

    for(i = 0; i < nVALORES; i++)
    {
        char valor = VALORES[i];
        Deleta (valor, naipe, monte);
    }
}

void DeletaValor (char valor, tMonte *monte)
{
    int i = 0;

    for(i = 0; i < nVALORES; i++)
    {
        char valor = VALORES[i];
        Deleta (valor, valor, monte);
    }
}

int IndiceCarta (char valor, char naipe, tMonte *monte)
{
    tCelula *atual = monte->primeiro->prox;
    int indice = 0;

    while (atual != NULL || (atual->carta.valor != valor && atual->carta.naipe != naipe))
    {
        indice++;
        atual = atual->prox;
    }

    if (atual == NULL)
    {
        return -1;
    }
    else
    {
        return indice;
    }
}


tCarta CartaNoIndice (int pos, tMonte *monte)
{
    if (pos <= 0)
        return (CartaVazia ( ));

    int cont = 0;
    for (tCelula *p = monte->primeiro; p != NULL; p = p->prox, cont ++) {
        if (cont == (pos - 1))
            return (p->carta);
    }
    return (CartaVazia ( ));
}


void SwapCelulas (int pos1, int pos2, tMonte *monte);
