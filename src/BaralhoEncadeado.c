#include "../include/BaralhoEncadeado.h"
#include "../include/Cartas.h"
#include "../include/MaosSimples.h"
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>

tMonte *CMVazio()
{
    tMonte *monte;
    monte = (tMonte *)malloc(sizeof(tMonte));

    monte->cabeca = (tCelula *)malloc(sizeof(tCelula)); // monte->cabeca será a cabeça do monte
    monte->ultimo = monte->cabeca;
    monte->ultimo->prox = NULL;
    monte->tamanho = 0;

    return monte;
}

void FMVazio(tMonte *monte)
{
    monte->cabeca = (tCelula *)malloc(sizeof(tCelula)); // monte->cabeca será a cabeça do monte
    monte->ultimo = monte->cabeca;
    monte->ultimo->prox = NULL;
    monte->tamanho = 0;
}

void CriaBaralho(tMonte *monte)
{
    FMVazio(monte);
    tCarta atual;

    for (int i = 0; i < nVALORES * nNAIPES; i++)
    {
        atual = PreencheCarta(VALORES[i % 10], NAIPES[i / 10]);
        Insere(atual, monte);
    }
}

int EstaVazio(tMonte *monte)
{
    return (QuantidadeMonte(monte) == 0);
}

tCelula CriaCelulaVazia()
{
    tCelula celulaVazia;

    celulaVazia.carta = CartaVazia();
    celulaVazia.prox = NULL;

    return celulaVazia;
}

tCarta Carta(tCelula *celula)
{
    return celula->carta;
}

int QuantidadeMonte(tMonte *monte)
{
    return (monte->tamanho);
}

int ExisteCarta(tCarta x, tMonte *monte)
{
    if (EstaVazio(monte))
    {
        return 0;
    }
    tCelula *atual = monte->cabeca->prox;

    while (atual != NULL)
    {
        if ((Valor(Carta(atual)) == Valor(x)) && (Naipe(Carta(atual)) == Naipe(x)))
            return 1;
        atual = atual->prox;
    }
    return 0;
}

void Insere(tCarta x, tMonte *monte)
{
    if (!ExisteCarta(x, monte))
    {
        monte->ultimo->prox = (tCelula *)malloc(sizeof(tCelula));
        monte->ultimo = monte->ultimo->prox;
        monte->ultimo->carta = x;
        monte->ultimo->prox = NULL;

        monte->tamanho++;
    }
    else
    {
        printf("A carta ja existe no monte.\n");
    }
}

void Retira(tCarta x, tMonte *monte, tCarta *cartaRetirada)
{
    tCelula *atual, *anterior;

    anterior = monte->cabeca;
    for (atual = monte->cabeca->prox; atual != NULL; atual = atual->prox)
    {
        if ((Valor(Carta(atual)) == Valor(x)) && (Naipe(Carta(atual)) == Naipe(x)))
        {
            *cartaRetirada = Carta(atual);
            anterior->prox = atual->prox;
            free(atual);
            monte->tamanho--;
            return;
        }
        anterior = atual;
    }
    *cartaRetirada = CartaVazia();
}

tCarta Corta(tMonte *monte, int pos)
{
    tCarta corte;

    if ((pos >= 1) && (pos <= QuantidadeMonte(monte)))
    {
        int i = 1;
        tCelula *atual;
        atual = monte->cabeca->prox;

        while (atual != NULL && i < pos)
        {
            i++;
            atual = atual->prox;
        }

        if (atual != NULL)
        {
            monte->ultimo->prox = monte->cabeca->prox;
            monte->cabeca->prox = atual->prox;
            monte->ultimo = atual;
            atual->prox = NULL;
            corte = Carta(monte->ultimo);
        }
        if ((Valor(corte) == 'A') || (Valor(corte) == '7'))
        {
            pos = ((pos + 1) % QuantidadeMonte(monte)) + 1;
            corte = Corta(monte, pos);
        }
        return (corte);
    }
    printf("ERRO! Nao foi possivel cortar.\n");
    return (CartaVazia());
}

void TrocaCarta(tMonte *monte, tCelula *celula, int pos)
{
    int i = 1;

    if (pos <= QuantidadeMonte(monte))
    {
        tCarta primeiraCarta = Carta(celula);
        tCarta segundaCarta;

        // Agora basta substituir a carta da célula no índice pela carta da célula de entrada
        tCelula *atual = monte->cabeca->prox;
        while (atual != NULL && i < pos)
        {
            i++;
            atual = atual->prox;
        }
        if (atual == NULL)
        {
            printf("Nao foi possivel chegar na posicao!\n");
        }
        else
        {
            segundaCarta = Carta(atual);
            celula->carta = segundaCarta;
            atual->carta = primeiraCarta;
        }
    }
    else
    {
        printf("A posicao fica fora do monte.\n");
    }
}

// Para cada célula do monte, gerar uma posição aleatória dentro do monte e mover a célula pra esta posição
void Embaralha(tMonte *monte)
{
    int posAleatoria = 0, tamMonte = QuantidadeMonte(monte);

    if (tamMonte != 0)
    {
        struct timeval t;
        tCelula *atual = monte->cabeca->prox;

        gettimeofday(&t, NULL);
        srand((unsigned int)t.tv_usec); // Inicializa o gerador de números aleatórios
        while (atual != NULL)
        {
            posAleatoria = rand() % (tamMonte + 1);
            if (posAleatoria < 1) // Índice começa em 1
            {
                posAleatoria = 1;
            }
            printf("posAleatoria: %i\n", posAleatoria);

            TrocaCarta(monte, atual, posAleatoria);

            atual = atual->prox;
        }
    }
}

// Usando imprimeCarta
void ImprimeMonte(tMonte *monte)
{
    if (QuantidadeMonte(monte) != 0)
    {
        tCelula *atual = NULL;

        // printf("Quantidade de itens: %i\n", QuantidadeMonte(monte));
        for (atual = monte->cabeca->prox; atual != NULL; atual = atual->prox)
        {
            ImprimeCarta(Carta(atual));
        }
    }
}

void DestroiMonte(tMonte *monte)
{
    tCelula *anterior, *atual;

    atual = monte->cabeca;
    while (atual != NULL)
    {
        anterior = atual;
        atual = atual->prox;
        free(anterior);
    }

    monte->tamanho = 0;
}

tCarta CartaNoIndice(int pos, tMonte *monte)
{
    if (pos >= 1) // 1 como sendo o primeiro elemento (não é índice de vetor)
    {
        int i = 1;
        tCelula *atual = monte->cabeca->prox; // primeiro elemento da lista

        while (atual != NULL && i < pos)
        {
            i++;
            atual = atual->prox;
        }

        if (atual != NULL)
        {
            return Carta(atual);
        }
    }

    return CartaVazia();
}

void MaoParaMonte(tCarta *carta, tMonte *monte, tMao *mao)
{
    RetiraDaMao(*carta, mao);
    Insere(*carta, monte);
}

void MonteParaMao(tCarta *carta, tMonte *monte, tMao *mao)
{
    tCarta retirada;

    Retira(*carta, monte, &retirada);
    ColocaNaMao(retirada, mao);
}

int ContaPontos(tMonte *monte)
{
    tCelula *atual = monte->cabeca->prox;
    int pontos = 0;

    while (atual != NULL)
    {
        pontos += PontuacaoCarta(Carta(atual));
        atual = atual->prox;
    }

    return pontos;
}
