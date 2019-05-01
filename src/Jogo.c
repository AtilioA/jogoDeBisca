#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/Jogo.h"
#include "../include/Maos.h"
#include "../include/BaralhoEncadeado.h"

void CriaJogador(tJogador *jogador)
{
    CriaMao(&jogador->mao);
    FMVazio(&jogador->pontos);
    jogador->prox = NULL;
}

void CriaPartida(tPartida *partida, int nJogadores)
{
    tJogador *atual = partida->inicial;
    partida->nJogadores = 0;

    while ((QuantidadeJogadores(partida)) < nJogadores)
    {
        CriaJogador(atual);
        atual = atual->prox;
        partida->nJogadores++;
    }
    atual->prox = partida->inicial;
}

int QuantidadeJogadores(tPartida *partida)
{
    return partida->nJogadores;
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

void exibeInfo(tMonte *monte, tJogador *jogadores, int nJogadores)
{
    int i = 0;
    tJogador J1 = jogadores[0]; // Jogador 1 ("eu")

    printf("Sua mao:\n");
    ImprimeMao(Mao(&J1));

    printf("Cartas restantes no monte: ");
    ImprimeMonte(monte);

    printf("Pontuação dos jogadores: ");
    for (i = 0; i < nJogadores; i++)
    {
        // printf("Pontuacao do %i jogador: %i.\n", i + 1, Pontuacao(&jogadores[i]));
    }

    printf("\n");
}


/* As opções
 * - Mostrar cartas do monte (na ordem que ela estiver)
 * - Embaralhar
 * - Cortar
 * estarão disponíveis apenas quando o jogo começar e em modo desenvolvedor
 */
void exibeMenuDev()
{
    printf("[10] - Mostrar cartas do monte\n");
    printf("[11] - Embaralhar\n");
    printf("[12] - Cortar\n");
}

void exibeAjuda()
{
    printf("\n\n--------- AJUDA ---------\n");
    printf("Digite um valor e pressione Enter para escolher uma opcao\n");
    printf("Voce podera jogar contra um computador ou em duplas (jogador + computador vs. 2 computadores)\n");
    printf("Sobre a bisca: http://tiny.cc/bisca\n\n\n");
}

void exibeMenu(tMonte *monte)
{
    int modoDev = 0, nJogadores = 0;
    char op = '1';

    while (op != '2')
    {
        printf("-------------------------\n");
        printf("----- JOGO DE BISCA -----\n\n");
        printf("-------- OPCOES: --------\n");
        printf("[1] - Jogar\n");
        printf("[2] - Sair\n");
        printf("[3] - Ajuda\n");
        printf("[4] - Jogar em modo desenvolvedor {h a c k e r m a n}\n");
        printf("Digite sua escolha: ");
        scanf(" %c", &op);

        switch (op)
        {
        case '1':
            modoDev = 0;
            printf("Digite 2 para jogar em 2 jogadores ou\n4 para jogar em 4 jogadores: ");
            scanf("%i", &nJogadores);
            Joga(monte, modoDev, nJogadores);
            break;

        case '2':
            return;

        case '3':
            exibeAjuda();
            break;

        case '4':
            modoDev = 1;
            printf("Digite 2 para jogar em 2 jogadores ou\n4 para jogar em 4 jogadores: ");
            scanf("%i", &nJogadores);
            Joga(monte, modoDev, nJogadores);
            break;

        // Quando o jogo estiver ativo
        case '7':
            if (modoDev == 1) // algo assim
            {
                ImprimeMonte(monte);
            }
            break;

        case '8':
            if (modoDev == 1)
            {
                Embaralha(monte);
            }
            break;

        case '9':
            // Vergonha alheia de cortar no meio do jogo
            break;

            while (op < '1' || op > '9')
            {
                printf("Opcao invalida. Tente novamente: ");
                scanf(" %c", &op);
            }
        }
    }
}

void Joga2(tMonte *monte, int modoDev)
{
    tPartida partida;
    Embaralha(monte);
    CriaPartida(&partida, 2);

    /* Primeiro jogador corta, etc
    */
}
void Joga4(tMonte *monte, int modoDev)
{
    tPartida partida;
    Embaralha(monte);
    CriaPartida(&partida, 4);

    /* Primeiro jogador corta, etc
    */
}

void Joga(tMonte *monte, int modoDev, int nJogadores)
{
    while (nJogadores != 2 && nJogadores != 4)
    {
        printf("Opcao invalida.\nDigite 2 para jogar com 2 jogadores ou\n 4 para jogar com 4 jogadores: ");
        scanf("%i", &nJogadores);
    }
    if (nJogadores == 2)
    {
        Joga2(monte, modoDev);
    }
    else if (nJogadores == 4)
    {
        Joga4(monte, modoDev);
    }
}
