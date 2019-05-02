#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../include/Jogo.h"
#include "../include/Maos.h"
#include "../include/BaralhoEncadeado.h"

void CriaPartida (int nJogadores, tPartida *partida, tMonte *baralho) {
    int p;
    tCarta trunfo;

    printf("Iniciando a partida de %d jogadores...\n", nJogadores);
    PreparaPartida (partida, nJogadores);
    partida->monte = baralho;
    printf ("Embaralhando o baralho...\n");
    Embaralha(Monte(partida));
    sleep (1);
    printf ("Pronto! Agora sorteando quem sera o primeiro a jogar...\n");
    struct timeval t;
    gettimeofday(&t, NULL);
    srand((unsigned int)t.tv_usec);
    p = (rand ( ) % nJogadores) + 1;
    MoveCabeca (partida, p);
    sleep (1);
    printf ("Sera o jogador %d!\n", p);
    printf ("\n");
    printf ("Jogador %d, passe os comandos ao jogador a sua ESQUERDA para que ele possa cortar.\n", p);
    p = p - 1;
    if (p == 0) p = nJogadores;
    sleep (1);
    printf ("Jogador %d, escolha uma posicao de 1 a 40 para cortar o baralho.\n", p);
    scanf ("%d", &p);
    p = (p % 40) + 1;
    trunfo = Corta (Monte (partida), p);
    partida->corte = trunfo;
    printf ("O trunfo escolhido foi ");
    ImprimeCarta (trunfo);
    printf ("Agora serao entregues as cartas...\n");
}

// Não está funcionando
void DistribuiCartas (tPartida *partida)
{
    int i = 0, j = 0;
    tJogador *atual = partida->inicial;

    for (i = 1; i < QuantidadeJogadores(partida); i++)
    {
        for (j = 0; j < nMAO; j++)
        { // Não estou conseguindo usar as funções para acesso da struct
            MonteParaMao(&(Monte(partida)->primeiro)->carta, Monte(partida), &atual->mao); // Segmentation fault aqui
        }
        atual = atual->prox;
    }
}

//Informacoes do jogo
void exibeInfo (tPartida *partida)
{
//Corte
//ultima carta Jogada
//quem inicia
}


/* As opções
 * - Mostrar cartas do monte (na ordem que ela estiver)
 * - Embaralhar
 * - Cortar
 * estarão disponíveis apenas quando o jogo começar e em modo desenvolvedor
 */
void exibeMenuDev (tPartida *partida)
{
    int op, p;

    printf ("[10] - Mostrar cartas do monte\n");
    printf ("[11] - Embaralhar\n");
    printf ("[12] - Cortar\n");

    scanf ("%d", &op);
    switch (op) {
        case 10:
            ImprimeMonte (Monte (partida));
        break;

        case 11:
            Embaralha (Monte (partida));
            ImprimeMonte (Monte (partida));
        break;

        case 12:
            printf ("Escolha a posicao de 1 a 40 para cortar\n");
            scanf ("%d", &p);
            ImprimeCarta (Corta (Monte (partida), p));
        break;

        default:
            printf ("Im sorry my dear.\n");
        break;
    }
}

void exibeAjuda()
{
    printf("\n\n--------- AJUDA ---------\n");
    printf("Digite um valor e pressione Enter para escolher uma opcao\n");
    printf("Voce podera jogar contra um computador ou em duplas (jogador + computador vs. 2 computadores)\n");
    printf("Sobre a bisca: http://tiny.cc/bisca\n\n\n");
}

void exibeMenu ( )
{
    int modoDev, nJogadores;
    int op = 1;

    while (op != 2)
    {
        printf("-------------------------\n");
        printf("----- JOGO DE BISCA -----\n\n");
        printf("-------- OPCOES: --------\n");
        printf("[1] - Jogar\n");
        printf("[2] - Sair\n");
        printf("[3] - Ajuda\n");
        printf("[4] - Jogar em modo desenvolvedor {h a c k e r m a n}\n");
        printf("Digite sua escolha: ");
        scanf(" %d", &op);

        switch (op)
        {
            case 1:
                modoDev = 0;
                printf("Digite 2 para jogar em 2 jogadores ou\n4 para jogar em 4 jogadores: ");
                scanf("%d", &nJogadores);
                //chama o jogo de jogadores
                break;

            case 2:
                return;

            case 3:
                exibeAjuda();
                break;

            case 4:
                modoDev = 1;
                printf("Digite 2 para jogar em 2 jogadores ou\n4 para jogar em 4 jogadores: ");
                scanf("%d", &nJogadores);
                //chama o jogo de jogadores
            break;

            while (op < 1 || op > 4)
            {
                printf("Opcao invalida. Tente novamente: ");
                scanf(" %d", &op);
            }
        }
    }
}

int Partida2Jogadores (tPartida *partida)
{

    return 0;
}
