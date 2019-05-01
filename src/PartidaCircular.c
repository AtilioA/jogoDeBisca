#include "../include/PartidaCircular.h"


tJogador *InsereJogador (tJogador *jogador) {
    tJogador *novo;
    novo = (tJogador *) malloc (sizeof (tJogador));
    CriaMao (&novo->mao);
    FMVazio (&novo->pontos);

    novo->prox = jogador;
    return (novo);
}

void PreparaPartida (tPartida *partida, int nJogadores) {
    partida->nJogadores = 0;
    partida->inicial = (tJogador *) malloc (sizeof (tJogador));
    CriaMao (&partida->inicial->mao);
    FMVazio (&partida->inicial->pontos);
    partida->nJogadores ++;
    tJogador *inicio = partida->inicial;
    while (QuantidadeJogadores (partida) <= nJogadores) {
        inicio = InsereJogador (inicio);
        partida->nJogadores ++;
    }
    partida->inicial->prox = inicio;
}

void DestroiPartida (tPartida *partida) {
    tJogador *atual, *lixo;
    lixo = partida->inicial;
    while ((QuantidadeJogadores (partida)) > 0) {
        atual = lixo->prox;
        LiberaMao(&lixo->mao);
        DestroiMonte(&lixo->pontos);
        free (lixo);
        lixo = atual;
        partida->nJogadores --;
    }
}

void MoveCabeca (tPartida *partida, int pos) {
    tJogador *atual = partida->inicial;
    for (int i = 1; i < pos; i ++) {
        atual = atual->prox;
    }
    partida->inicial = atual;
}

int QuantidadeJogadores (tPartida *partida) {
    return (partida->nJogadores);
}

tJogador *JogadorInicial(tPartida *partida)
{
    return partida->inicial;
}

tMonte Monte(tPartida *partida)
{
    return partida->monte;
}

tCarta Corte(tPartida *partida)
{
    return partida->corte;
}

tMonte Pontuacao(tJogador *jogador)
{
    return jogador->pontos;
}

tMao Mao(tJogador *jogador)
{
    return jogador->mao;
}
