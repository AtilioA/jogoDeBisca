#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../include/Jogo.h"
#include "../include/Maos.h"
#include "../include/PartidaCircular.h"
#include "../include/BaralhoEncadeado.h"
#include "../include/IA2Jogadores.h"
#include "../include/IA4Jogadores.h"

tPartida *CriaPartida(int nJogadores, tMonte *baralho)
{
    int p, q, h;
    tCarta trunfo;
    //tMonte mesa;
    tPartida *partida;
    partida = (tPartida *) malloc (sizeof (tPartida));
    clrscr ();
    printf("Iniciando a partida de %d jogadores...\n", nJogadores);
    //FMVazio(&mesa);
    //partida->mesa = &mesa;
    printf("Humano, escolha seu indice [1 a 4]: ");
    scanf("%d", &h);
    PreparaPartida(partida, nJogadores, h);
    printf("Pronto! Agora sorteando quem comecara embaralhando...\n");
    // sleep (1);
    struct timeval t;
    gettimeofday(&t, NULL);
    srand((unsigned int)t.tv_usec);
    p = (rand() % nJogadores) + 1;
    printf("Sera o jogador %d!\n\n", p);
    printf("Embaralhando...\n");
    Embaralha(baralho);
    // sleep (1);
    q = p - 1;
    if (q == 0) q = nJogadores;
    printf ("Jogador %d, passe os comandos ao jogador %d, a sua ESQUERDA, para que ele possa cortar.\n", p, q);
    // sleep (1);
    if (q == h) {
        printf("Jogador %d, escolha uma posicao de 1 a 40 para cortar o baralho.\n", q);
        scanf("%d", &q);
    }
    else {
        printf("O computador %d cortara aleatoriamente.\n", q);
        gettimeofday(&t, NULL);
        srand((unsigned int)t.tv_usec);
        q = (rand() % 40) + 1;
    }
    trunfo = Corta(baralho, q);
    partida->corte = trunfo;
    printf("O trunfo escolhido foi ");
    ImprimeCarta(trunfo);
    printf("Agora serao entregues as cartas...\n");
    DistribuiCartas(partida, nMAO, baralho);
    p = p + 1;
    if (p > nJogadores) p = 1;
    printf("Jogador %d, voce inicia jogando!\n", p);
    MoveCabeca (partida, p);
    printf("Good luck and dont fuck it up\n\n");

    return (partida);
}


void DistribuiCartas (tPartida *partida, int n, tMonte *baralho)
{
    tJogador *jogadorAtual = partida->inicial;
    tCarta cartaAtual;
    tMao *maoJogador;

    for (int i = 1; i <= QuantidadeJogadores(partida); i++)
    {
        for (int j = 0; j < n; j++)
        {
            cartaAtual = (CartaNoIndice(1, baralho));
            maoJogador = Mao(jogadorAtual);
            MonteParaMao(&cartaAtual, baralho, maoJogador);
        }
        jogadorAtual = jogadorAtual->prox;
    }
}

void exibeAjuda()
{
    printf("\n\n--------- AJUDA ---------\n");
    printf("Digite um valor e pressione Enter para escolher uma opcao\n");
    printf("Voce podera jogar contra um computador ou em duplas (jogador + computador vs. 2 computadores)\n");
    printf("Sobre a bisca: http://tiny.cc/bisca\n\n\n");
}

/* Adicionar:
 * Informacoes do jogo
 * Corte
 * Última carta jogada
 * Quem inicia
 *
 * As opções
 * - Mostrar cartas do monte (na ordem que ela estiver)
 * - Embaralhar
 * - Cortar
 * estarão disponíveis apenas quando o jogo começar e em modo desenvolvedor
 */
void MenuPartida(tPartida *partida, tMonte *baralho)
{
    int op = 0, p = 0;

    ImprimePontuacao(partida);
    printf("Cartas restantes no baralho/monte: %i\n", QuantidadeMonte(baralho));
    printf("\nQuantidade de cartas na mao: %i\n", TamanhoMao(*Mao(JogadorInicial(partida)))); // não sei qual é o jogador inicial

    printf("[1] - Jogar carta\n");
    printf("[2] - Sair\n");
    printf("[3] - Ajuda\n");
    printf("[4] - Pontuação dos jogadores\n");

    if (ModoDev(partida))
    {
        printf("[10] - Mostrar cartas do monte\n");
        printf("[11] - Embaralhar\n");
        printf("[12] - Cortar\n");
    }

    scanf("%d", &op);

    switch (op)
    {
    case 1:
        JogaCartaHumano(partida, partida->inicial);
        break;

    case 2:
        return;

    case 3:
        exibeAjuda();
        break;

    case 10:
        if (ModoDev(partida))
        {
            ImprimeMonte(Mesa(partida));
        }
        break;

    case 11:
        if (ModoDev(partida))
        {
            printf("Embaralhando...\n");
            Embaralha(Mesa(partida));
            ImprimeMonte(Mesa(partida));
        }
        break;

    case 12:
        if (ModoDev(partida))
        {
            printf("Escolha a posicao de 1 a 40 para cortar\n");
            scanf("%d", &p);
            printf("Corte:\n");
            ImprimeCarta(Corta(Mesa(partida), p));
        }
        break;

    default:
        printf("thank u, next.\n");
        break;
    }
}

void exibeMenuInicial(tPartida *partida)
{
    //int modoDev;
    int nJogadores;
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
            partida->modoDev = 0;
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
            partida->modoDev = 1;
            printf("Digite 2 para jogar em 2 jogadores ou\n4 para jogar em 4 jogadores: ");
            scanf("%d", &nJogadores);
            //chama o jogo de jogadores
            break;

            while (op < 1 || op > 15)
            {
                printf("Opcao invalida. Tente novamente: ");
                scanf(" %d", &op);
            }
        }
    }
}

// Último do pontos aponta pra Mesa
// Esvazia mesa
void Partida(tPartida *partida, tMonte *baralho)
{
    int jogadas, rodadas, vez, seteSaiu;
    tCarta corte, escolhida;
    tMonte mesa;
    tJogador *atual, *vencedor;

    corte = Corte(partida);
    seteSaiu = 0;
    rodadas = 0;

    while (rodadas <= (40 / QuantidadeJogadores(partida)))
    {
        jogadas = 0;
        atual = JogadorInicial(partida);
        vez = PC(atual);

        FMVazio(&mesa);
        partida->mesa = &mesa;

        while (jogadas < QuantidadeJogadores(partida))
        {
            printf("Jogador %d, sua vez.\n", IndiceJogador(atual));
            printf("Mesa:\n");
            ImprimeMonte(Mesa(partida));
            printf("\n");
            switch (vez)
            {
            case HUMANO:
                escolhida = JogaCartaHumano(partida, atual);
                jogadas++;
                vez = PC(atual->prox);
                break;

            case IA:
                if (jogadas == 0)
                {
                    if (QuantidadeJogadores(partida) == 2)
                        escolhida = PC2Jogadores1(Mao(atual), Mesa(partida), corte, &seteSaiu);
                    else
                        escolhida = PC4Jogadores1(Mao(atual), Mesa(partida), corte, &seteSaiu);
                }
                else if (jogadas == 1)
                {
                    if (QuantidadeJogadores(partida) == 2)
                        escolhida = PC2Jogadores2(Mao(atual), Mesa(partida), corte, &seteSaiu);
                    else
                        escolhida = PC4Jogadores2(Mao(atual), Mesa(partida), corte, &seteSaiu);
                }
                else if (jogadas == 2)
                {
                    escolhida = PC4Jogadores3(Mao(atual), Mesa(partida), corte, &seteSaiu);
                }
                else if (jogadas == 3)
                {
                    escolhida = PC4Jogadores4(Mao(atual), Mesa(partida), corte, &seteSaiu);
                }
                jogadas++;
                vez = PC(atual->prox);
                break;
            }
            ImprimeCarta(escolhida);
            atual = atual->prox;
        }
        clrscr ( );
        vencedor = Vencedor(partida);
        MandaPontosJogador (vencedor, Mesa (partida));
        printf("%d venceu essa rodada\n", IndiceJogador(vencedor));
        DistribuiCartas (partida, 1, baralho);
        rodadas++;
        DestroiMonte(Mesa(partida));
    }

    DestroiMonte(baralho);
}

void FinalizaPartida (tPartida *partida)
{
    int ponto1 = 0, ponto2 = 0,
        campeao = 0, h;
    tJogador *atual;

    h = HUMANO;
    atual = partida->inicial;
    for (int i = 1; i <= QuantidadeJogadores (partida); i ++) {
        if (! (i % 2))
            ponto1 = ContaPontos (Pontuacao (atual)) + ponto1;
        else
            ponto2 = ContaPontos (Pontuacao (atual)) + ponto2;

        if (IndiceJogador (atual) == 1)
            partida->inicial = atual;

        if (PC(atual) == HUMANO)
            h = i;

        atual = atual->prox;
    }

    clrscr ( );
    printf ("Pontuacao de cada jogador:\n");
    ImprimePontuacao(partida);

    if (ponto1 > ponto2)
        campeao = 1; //jogador 1 e 3
    else if (ponto2 > ponto1)
        campeao = 2; //jogador 2 e 4

    switch (QuantidadeJogadores (partida)) {
        case 2:
            printf ("O campeao foi o jogador %d!\n", campeao);
            if (campeao != h)
                printf("PARABENS HUMAN0! voce perdeu pro laptop da xuxa\n");
        break;

        case 4:
            printf ("A dupla campea foram os jogadores %d e %d!\n", campeao, campeao + 2);
            if ((campeao != h) && ((campeao + 2) != h))
                printf("PARABENS HUMAN0! voce perdeu pro laptop da xuxa\n");
        break;
    }
}

void clrscr()
{
    system("@cls||clear");
}
