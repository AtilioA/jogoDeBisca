#include "../include/PartidaCircular.h"
#include <stdio.h>
#include <stdlib.h>

void MandaPontosJogador(tJogador *vencedor, tMonte *mesa)
{
    int i = 0;
    tCarta retirada;

    for (i = QuantidadeMonte(mesa); i > 0; i--)
    {
        Retira(CartaNoIndice(1, mesa), mesa, &retirada);
        Insere(retirada, &vencedor->pontos);
    }
}

tJogador *InsereJogador(tJogador *jogador)
{
    tJogador *novo;
    novo = (tJogador *)malloc(sizeof(tJogador));
    CriaMao(&novo->mao);
    FMVazio(&novo->pontos);

    novo->prox = jogador;
    return novo;
}

void PreparaPartida(tPartida *partida, int nJogadores, int posHumano)
{
    partida->nJogadores = 0;
    partida->inicial = (tJogador *)malloc(sizeof(tJogador));
    CriaMao(&partida->inicial->mao);
    FMVazio(&partida->inicial->pontos);
    partida->nJogadores++;
    partida->inicial->indice = (nJogadores - QuantidadeJogadores(partida)) + 1;

    if (IndiceJogador(partida->inicial) == posHumano)
    {
        partida->inicial->PC = HUMANO;
    }
    else
    {
        partida->inicial->PC = IA;
    }

    tJogador *inicio = partida->inicial;
    while (QuantidadeJogadores(partida) < nJogadores)
    {
        inicio = InsereJogador(inicio);
        partida->nJogadores++;
        inicio->indice = (nJogadores - QuantidadeJogadores(partida)) + 1;
        if (IndiceJogador(inicio) == posHumano)
        {
            inicio->PC = HUMANO;
        }
        else
        {
            inicio->PC = IA;
        }
    }
    partida->inicial->prox = inicio;
}

void DestroiPartida(tPartida *partida)
{
    tJogador *atual, *lixo;
    lixo = partida->inicial;
    while ((QuantidadeJogadores(partida)) > 0)
    {
        atual = lixo->prox;
        LiberaMao(&lixo->mao);
        DestroiMonte(&lixo->pontos);
        free(lixo);
        lixo = atual;
        partida->nJogadores--;
    }
free(partida);
}

void MoveCabeca(tPartida *partida, int n)
{
    tJogador *atual = partida->inicial;
    for (int i = 1; i <= n; i++)
    {
        atual = atual->prox;
    }
    partida->inicial = atual;
}

tCarta JogaCartaHumano(tPartida *partida, tJogador *humano)
{
    int p = 0;
    tCarta selecionada;

    printf("\nCartas da sua mao:\n");
    ImprimeMao(*Mao(humano));
    while (p < 1 || p > TamanhoMao(*Mao(humano)))
    {
        printf("Informe a posicao da carta que quer jogar: ");
        scanf("%i", &p);
        while (getchar() != '\n');
    }

    selecionada = PegaCarta(p, *Mao(humano));
    ImprimeCarta(selecionada);
    MaoParaMonte(&selecionada, Mesa(partida), Mao(humano));

    return selecionada;
}

void ImprimePontuacao(tPartida *partida)
{
    if (partida != NULL)
    {
        int i = 0;
        tJogador *atual = partida->inicial;

        printf("----------------------------\n");
        printf("    PONTUACAO DA PARTIDA\n");
        for (i = 1, atual = partida->inicial; i <= QuantidadeJogadores(partida); i++, atual = atual->prox)
        {
            if (atual != NULL)
            {
                if (PC(atual) == HUMANO)
                {
                    printf("Jogador %i (VOCE): %i pontos\n", IndiceJogador(atual), ContaPontos(Pontuacao(atual)));
                }
                else
                {
                    printf("Jogador %i: %i pontos\n", IndiceJogador(atual), ContaPontos(Pontuacao(atual)));
                }
            }
        }
        printf("----------------------------\n");
    }
}

tJogador *Vencedor(tPartida *partida)
{
    for (int i = 0; i < QuantidadeJogadores(partida); i++)
    {
        if (CartasIguais(MaiorMesa(Mesa(partida), Corte(partida)), CartaNoIndice((i + 1), Mesa(partida))))
        {
            MoveCabeca(partida, i);
        }
    }

    return JogadorInicial(partida);
}

int QuantidadeJogadores(tPartida *partida)
{
    return (partida->nJogadores);
}

tJogador *JogadorInicial(tPartida *partida)
{
    return partida->inicial;
}

//tMonte *Baralho(tPartida *partida)
//{
//    return partida->monte;
//}

tCarta Corte(tPartida *partida)
{
    return partida->corte;
}

tMonte *Pontuacao(tJogador *jogador)
{
    return &jogador->pontos;
}

tMao *Mao(tJogador *jogador)
{
    return &jogador->mao;
}

tMonte *Mesa(tPartida *partida)
{
    return partida->mesa;
}

int PC(tJogador *jogador)
{
    return jogador->PC;
}

int Dificuldade(tPartida *partida)
{
    return partida->dificuldade;
}

int ModoDev(tPartida *partida)
{
    return partida->modoDev;
}

int IndiceJogador(tJogador *jogador)
{
    return jogador->indice;
}
