#include "../include/Jogo.h"
#include "../include/MaosSimples.h"
#include "../include/PartidaCircular.h"
#include "../include/BaralhoEncadeado.h"
#include "../include/IA2Jogadores.h"
#include "../include/IA4Jogadores.h"
#include <stdio.h>
#include <sys/time.h>

tPartida *CriaPartida(int nJogadores, tMonte *baralho)
{
    struct timeval t; // Para gerar números aleatórios
    int primeiroJogador = 0, jogadorEsquerda = 0, posCorte = 0, posHumano = 0;
    tCarta trunfo;
    tPartida *partida = (tPartida *)malloc(sizeof(tPartida));

    clrscr();
    printf("Iniciando partida de %i jogadores...\n", nJogadores);
    printf("-----------------------------------\n");
    printf("Humano, escolha qual jogador voce deseja ser [1 a %i]: ", nJogadores);
    scanf("%i", &posHumano);
    PreparaPartida(partida, nJogadores, posHumano);

    printf("OK! Agora, sorteando quem comecara...\n");
    //sleep(1);
    gettimeofday(&t, NULL);
    srand((unsigned int)t.tv_usec);              // Inicializando srand()
    primeiroJogador = (rand() % nJogadores) + 1; // Determinando primeiro jogador aleatoriamente
    printf("Sera o jogador %i!\n\n", primeiroJogador);

    printf("Embaralhando...\n");
    Embaralha(baralho);
    //sleep(1);

    jogadorEsquerda = primeiroJogador - 1;
    if (jogadorEsquerda == 0)
    {
        jogadorEsquerda = nJogadores; // "Dando a volta" nos jogadores
    }
    printf("Jogador %i, passe os comandos ao jogador %i, a sua ESQUERDA, para que ele possa cortar.\n", primeiroJogador, jogadorEsquerda); // Regra da bisca
    //sleep(1);
    if (jogadorEsquerda == posHumano)
    {
        while (posCorte < 1 || posCorte > QuantidadeMonte(baralho))
        {
            printf("Jogador %i, escolha uma posicao de 1 a %i para cortar do baralho: ", jogadorEsquerda, QuantidadeMonte(baralho));
            scanf("%i", &posCorte);
        }
    }
    else
    {
        printf("O computador %i cortara aleatoriamente.\n", jogadorEsquerda);
        posCorte = (rand() % 40) + 1;
    }
    trunfo = Corta(baralho, posCorte);
    partida->corte = trunfo;
    printf("\nCARTA ESCOLHIDA COMO TRUNFO:\n");
    ImprimeCarta(trunfo);
    //sleep(1);

    printf("\nAgora, serao entregues as cartas aos jogadores...\n");
    DistribuiCartas(partida, nMAO, baralho);

    printf("Jogador %i, voce sera o primeiro a jogar!\n", primeiroJogador);
    MoveCabeca(partida, primeiroJogador); // O primeiro jogador será o primeiro da lista de jogadores da partida
    printf("Good luck and don't fuck it up!\n");
    //sleep(2);

    return partida;
}

void DistribuiCartas(tPartida *partida, int n, tMonte *baralho)
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
    printf("Digite um valor e pressione Enter para escolher a opcao\n");
    printf("Voce podera jogar contra um computador ou em duplas (jogador + computador vs. 2 computadores)\n");
    printf("Sobre a bisca: http://tiny.cc/bisca\n\n\n");
}

/* As opções
 * - Mostrar cartas do monte (na ordem que ela estiver)
 * - Embaralhar
 * - Cortar
 * estarão disponíveis apenas quando o jogo começar e em modo desenvolvedor
 */

tCarta MenuPartida(tPartida *partida, tMonte *baralho, tJogador *humano)
{
    int op = 0, p = 0;

    // No jogo de bisca, a pontuação só é revelada ao final do jogo
    if (ModoDev(partida))
    {
        ImprimePontuacao(partida);
        printf("Rodadas restantes: %i\n", QuantidadeMonte(baralho) / 2 + TamanhoMao(*Mao(humano)));
    }
    printf("Cartas restantes no baralho: %i\n", QuantidadeMonte(baralho));
    // printf("\nQuantidade de cartas na mao: %i\n", TamanhoMao(*Mao(humano)));

    /* Tirar o print da JogaCartaHumano e mostrar mão do jogador antes? */

    while (op != 1 && op != 2)
    {
        printf("\n------------------- OPCOES -------------------\n");
        printf("[1] - Jogar carta\n");
        printf("[2] - Sair\n");
        printf("[3] - Ajuda\n");
        printf("[4] - Pontuacao dos jogadores\n");

        if (ModoDev(partida))
        {
            printf("[10] - Mostrar cartas do monte\n");
            printf("[11] - Mostrar cartas de todos os jogadores\n");
            printf("[12] - Embaralhar\n");
            printf("[13] - Cortar\n");
        }

        printf("\nDigite sua escolha: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            return JogaCartaHumano(partida, humano);
            break;

        case 2:
            DestroiPartida(partida);
            DestroiMonte(baralho);
            exit(0);

        case 3:
            clrscr();
            exibeAjuda();
            break;

        case 4:
            clrscr();
            ImprimeMesa(partida);
            ImprimePontuacao(partida);
            printf("\n");
            break;

        case 10:
            if (ModoDev(partida))
            {
                printf("Cartas restantes no jogo (%i):\n", QuantidadeMonte(baralho));
                ImprimeMonte(baralho);
                ImprimeMesa(partida);
            }
            break;

        case 11:
            if (ModoDev(partida))
            {
                printf("Sua mao:\n");
                ImprimeMao(*Mao(humano));

                tJogador *atual = humano->prox;
                printf("Mao dos outros jogadores:\n");
                for (int i = 1; i < QuantidadeJogadores(partida); i++)
                {
                    ImprimeMao(*Mao(atual));
                    printf("\n");
                    atual = atual->prox;
                }
                ImprimeMesa(partida);
                break;
            }
            break;

        case 12:
            if (ModoDev(partida))
            {
                printf("\nEmbaralhando...\n");
                Embaralha(baralho);
                printf("Embaralhado:\n");
                ImprimeMonte(baralho);
                ImprimeMesa(partida);
            }
            break;

        case 13:
            if (ModoDev(partida))
            {
                printf("Escolha uma posicao de 1 a %i para cortar: ", QuantidadeMonte(baralho));
                scanf("%i", &p);
                printf("Corte:\n");
                tCarta trunfo = Corta(baralho, p);
                ImprimeCarta(trunfo);
                partida->corte = trunfo;
                //sleep(2);
                clrscr();
                ImprimeMesa(partida);
            }
            break;

        default:
            printf("\nthank u, next.\n");
            break;
        }
    }
}

void ExibeMenuInicial(tPartida *partida)
{
    tMonte baralho;
    int nJogadores = -1;
    int op = 0;

    printf("-------------------------\n");
    printf("----- JOGO DE BISCA -----\n\n");
    printf("-------- OPCOES: --------\n");
    printf("[1] - Jogar\n");
    printf("[2] - Sair\n");
    printf("[3] - Ajuda\n");
    printf("[4] - Jogar em modo desenvolvedor {h a c k e r m a n}\n");
    printf("Digite sua escolha: ");
    scanf("%d", &op);

    switch (op)
    {
    case 1:
        nJogadores = -1;
        while (nJogadores != 2 && nJogadores != 4)
        {
            printf("Digite 2 para jogar em 2 jogadores\nou 4 para jogar em 4 jogadores: ");
            scanf("%i", &nJogadores);
        }

            CriaBaralho(&baralho);
            partida = CriaPartida(nJogadores, &baralho);
            partida->modoDev = 0;
            Partida(partida, &baralho);
            FinalizaPartida(partida);
            DestroiPartida(partida);
            break;

    case 2:
        return;

    case 3:
        clrscr();
        exibeAjuda();
        break;

    case 4:
        nJogadores = -1;
        while (nJogadores != 2 && nJogadores != 4)
        {
            printf("Digite 2 para jogar em 2 jogadores\nou 4 para jogar em 4 jogadores: ");
            scanf("%i", &nJogadores);
        }

            CriaBaralho(&baralho);
            partida = CriaPartida(nJogadores, &baralho);
            partida->modoDev = 1;
            Partida(partida, &baralho);
            FinalizaPartida(partida);
            DestroiPartida(partida);
            break;

    default:
        while (op < 1 || op > 4)
        {
            printf("Opcao invalida. Tente novamente: ");
            scanf("%d", &op);
        }
    }
}

void Partida(tPartida *partida, tMonte *baralho)
{ // Alguns //sleep() estão repetindo nos loops e deixando lento demais
    int jogadas, rodadas, vez, seteSaiu;
    tCarta corte, escolhida;
    tMonte mesa;
    tJogador *atual, *vencedor;

    corte = Corte(partida);
    seteSaiu = 0;
    rodadas = 0;

    while (rodadas < (40 / QuantidadeJogadores(partida)))
    {
        jogadas = 0;
        atual = JogadorInicial(partida);
        vez = PC(atual);

        FMVazio(&mesa);
        partida->mesa = &mesa;

        while (jogadas < QuantidadeJogadores(partida))
        {
            clrscr();
            ImprimeMesa(partida);
            printf("Jogador %i, sua vez!\n\n", IndiceJogador(atual));
            //sleep(1);

            switch (vez)
            {
            case HUMANO:
                escolhida = MenuPartida(partida, baralho, atual);

                if (jogadas == 0)
                {
                    //sleep(2);
                }
                clrscr();

                jogadas++;
                vez = PC(atual->prox);
                break;

            case IA:
                printf("Jogador %i:\n", IndiceJogador(atual));
                // //sleep(1);
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
                ImprimeCarta(escolhida);
                //sleep(2);
                clrscr();
                ImprimeMesa(partida);
                break;
            }
            atual = atual->prox;
        }
        clrscr();
        ImprimeMesa(partida);

        printf("Vencedor da rodada...\n");
        //sleep(1);
        vencedor = Vencedor(partida);
        MandaPontosJogador(vencedor, Mesa(partida));
        printf("O jogador %i venceu essa rodada!\n", IndiceJogador(vencedor));

        //sleep(1);
        if (QuantidadeMonte(baralho) > 0)
        {
            printf("Comprando cartas para os jogadores...\n");
        }
        DistribuiCartas(partida, 1, baralho);

        rodadas++;
        DestroiMonte(Mesa(partida));

        //sleep(2);
    }

    DestroiMonte(baralho);
}

void FinalizaPartida(tPartida *partida)
{
    int ponto1 = 0, ponto2 = 0, campeao = 0, PJ1 = 0, PJ2 = 0, h;
    tJogador *atual = partida->inicial;
    h = HUMANO;

    /* Não está anunciando o vencedor corretamente */

    if (QuantidadeJogadores(partida) == 2)
    {
        PJ1 = ContaPontos(Pontuacao(atual));
        atual = atual->prox;
        PJ2 = ContaPontos(Pontuacao(atual));
        if (PJ1 > PJ2)
        {
            h = 1;
            campeao = 1;
        }
        else
        {
            h = 1;
            campeao = 2;
        }
    }
    else
    {
        for (int i = 0; i < QuantidadeJogadores(partida); i++)
        {
            if (i % 2 == 0)
            {
                ponto1 = ContaPontos(Pontuacao(atual)) + ponto1;
            }
            else
            {
                ponto2 = ContaPontos(Pontuacao(atual)) + ponto2;
            }

            if (IndiceJogador(atual) == 1)
            {
                partida->inicial = atual;
            }

            if (PC(atual) == HUMANO)
            {
                h = i;
            }

            atual = atual->prox;
        }

        printf("ponto1: %i\nponto2: %i", ponto1, ponto2);
        if (ponto1 > ponto2)
        {
            campeao = 2; // jogadores 1 e 3
        }
        else if (ponto2 > ponto1)
        {
            campeao = 1; // jogadores 2 e 4
        }
    }

    clrscr();
    printf("Pontuacao de cada jogador:\n");
    ImprimePontuacao(partida);

    switch (QuantidadeJogadores(partida))
    {
    case 2:
        printf("\nO campeao foi o jogador %i!\n", campeao);
        if (campeao != h)
        {
            printf("PARABENS, HUMAN0! Voce PERDEU pro laptop da Xuxa\n");
            printf("Sashay away\n");
        }
        else
        {
            printf("PARABENS, HUMAN0! Voce GANHOU do carro autonomo da UFES\n");
            printf("Shantay you stay\n");
        }

        break;

    case 4:
        printf("A dupla campea foram os jogadores %i e %i!\n", campeao, campeao + 2);
        if ((campeao != h) && ((campeao + 2) != h))
        {
            printf("PARABENS, HUMAN0! Voce perdeu para os laptops da Xuxa\n");
            printf("Sashay away\n");
        }
        else
        {
            printf("PARABENS, HUMAN0! Voce GANHOU da frota de carros autonomos da UFES\n");
            printf("Shantay you stay\n");
        }
        break;
    }
}

void clrscr()
{
#ifdef __unix__
    system("clear");
#elif defined(WIN32) || defined(WIN64)
    system("cls");
#endif
}

void ImprimeMesa(tPartida *partida)
{
    printf("-----------------------------------\n");
    printf("Corte:\n");
    ImprimeCarta(Corte(partida));
    printf("\nMesa:\n");
    if (QuantidadeMonte(Mesa(partida)) > 0)
    {
        ImprimeMonte(Mesa(partida));
    }
    else
    {
        printf("A mesa ainda esta vazia.\n");
    }
    printf("-----------------------------------\n");
    printf("\n");
    //sleep(2);
}
