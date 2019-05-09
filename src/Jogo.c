#include "../include/Jogo.h"
#include "../include/MaosSimples.h"
#include "../include/PartidaCircular.h"
#include "../include/BaralhoEncadeado.h"
#include "../include/IA2Jogadores.h"
#include "../include/IA4Jogadores.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define FACIL 1
#define DIFICIL 2

tPartida *CriaPartida(int nJogadores, tMonte *baralho)
{
    struct timeval t; // Para gerar números aleatórios
    int primeiroJogador = 0, jogadorEsquerda = 0, posCorte = 0, posHumano = 0;
    tCarta trunfo;
    tPartida *partida = (tPartida *)malloc(sizeof(tPartida));

    clrscr();
    printf("Iniciando partida de %i jogadores...\n", nJogadores);
    printf("-----------------------------------\n");
    while (posHumano < 1 || posHumano > nJogadores)
    {
        printf("Humano, escolha qual jogador voce deseja ser [1 a %i]: ", nJogadores);
        scanf("%i", &posHumano);
        while (getchar() != '\n');
    }

    if(posHumano > nJogadores)
    {
        printf("Voce escolheu um jogador que nao existe! Assista a um belo jogo de computadores da XUXA!\n");
    }

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
            while (getchar() != '\n');
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
    //sleep(1);

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
    if(ModoDev(partida))
    {
        ImprimePontuacao(partida);
        printf("Rodadas restantes: %i\n", QuantidadeMonte(baralho) / 2 + TamanhoMao(*Mao(humano)));
    }
    printf("Cartas restantes no baralho: %i\n", QuantidadeMonte(baralho));
    // printf("\nQuantidade de cartas na mao: %i\n", TamanhoMao(*Mao(humano)));

    /* Tirar o print da JogaCartaHumano e mostrar mão do jogador antes? */

    while(op != 1 && op != 2)
    {
        printf("\n------------------- OPCOES -------------------\n");
        printf("[1] - Jogar carta\n");
        printf("[2] - Ajuda\n");

        if(ModoDev(partida))
        {
            printf("[10] - Mostrar cartas do monte\n");
            printf("[11] - Mostrar cartas de todos os jogadores\n");
            printf("[12] - Pontuacao de todos os jogadores\n");
            printf("[13] - Embaralhar\n");
            printf("[14] - Cortar\n");
        }

        printf("\nDigite sua escolha: ");
        scanf("%d", &op);
        while (getchar() != '\n');
        switch (op)
        {
        case 1:
            return JogaCartaHumano(partida, humano);
            break;

        case 2:
            clrscr();
            exibeAjuda();
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
                for(int i = 1; i < QuantidadeJogadores(partida); i++)
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
            clrscr();
            ImprimeMesa(partida);
            ImprimePontuacao(partida);
            printf("\n");
            break;

        case 13:
            if (ModoDev(partida))
            {
                printf("\nEmbaralhando...\n");
                Embaralha(baralho);
                printf("Embaralhado:\n");
                ImprimeMonte(baralho);
                ImprimeMesa(partida);
            }
            break;

        case 14:
            if (ModoDev(partida))
            {
                printf("Escolha uma posicao de 1 a %i para cortar: ", QuantidadeMonte(baralho));
                while (p < 1 || p > QuantidadeMonte(baralho))
                {
                    scanf("%i", &p);
                    while (getchar() != '\n');
                }

                printf("Corte:\n");
                tCarta trunfo = Corta(baralho, p);
                ImprimeCarta(trunfo);
                partida->corte = trunfo;
                //sleep(1);
                clrscr();
                ImprimeMesa(partida);
            }
            break;

        default:
            printf("\nOpcao invalida. Tente novamente: ");
            break;
        }
    }

    return CartaVazia();
}

void ExibeMenuInicial(tPartida *partida)
{
    tMonte baralho;
    int nJogadores = -1;
    int op = -1;
    int dificuldade = -1;

    while(op != 0)
    {
        printf("-------------------------\n");
        printf("----- JOGO DE BISCA -----\n\n");
        printf("-------- OPCOES: --------\n");
        printf("[1] - Jogar\n");
        printf("[2] - Ajuda\n");
        printf("[3] - Jogar em modo desenvolvedor {h a c k e r m a n}\n");
        printf("[0] - Sair\n\n");
        printf("Digite sua escolha: ");
        if (op == -1)
        {
            scanf("%i", &op);
        }

        switch(op)
        {
        case 1:
            op = -1;
            nJogadores = -1;
            while(nJogadores != 2 && nJogadores != 4)
            {
                printf("Digite 2 para jogar em 2 jogadores\nou 4 para jogar em 4 jogadores: ");
                scanf("%i", &nJogadores);
                while (getchar() != '\n');
            }

            while(dificuldade != 1 && dificuldade != 2)
            {
                printf("Digite o modo da partira:\n");
                printf("[1] - Facil\n");
                printf("[2] - Dificilimo\n");
                scanf("%i", &dificuldade);
                while (getchar() != '\n');
            }

            CriaBaralho(&baralho);
            partida = CriaPartida(nJogadores, &baralho);
            partida->dificuldade = dificuldade;
            partida->modoDev = 0;
            Partida(partida, &baralho);
            FinalizaPartida(partida);
            DestroiPartida(partida);
            break;

        case 2:
            clrscr();
            exibeAjuda();
            break;

        case 3:
            op = -1;
            nJogadores = -1;
            while(nJogadores != 2 && nJogadores != 4)
            {
                printf("Digite 2 para jogar em 2 jogadores\nou 4 para jogar em 4 jogadores: ");
                scanf("%i", &nJogadores);
                while (getchar() != '\n');
            }

            CriaBaralho(&baralho);
            partida = CriaPartida(nJogadores, &baralho);
            partida->dificuldade = dificuldade;
            partida->modoDev = 1;
            Partida(partida, &baralho);
            FinalizaPartida(partida);
            DestroiPartida(partida);
            break;

        default:
            while (op < 0 || op > 3)
            {
                printf("Opcao invalida. Tente novamente: ");
                scanf("%d", &op);
                while (getchar() != '\n');
            }
            clrscr();
        }
    }
}

void Partida(tPartida *partida, tMonte *baralho)
{ // Alguns //sleep() estão repetindo nos loops e deixando lento demais
    int jogadas, rodadas, vez, seteSaiu;
    tCarta corte, escolhida;
    tJogador *atual, *vencedor;

    corte = Corte(partida);
    seteSaiu = 0;
    rodadas = 0;

    while(rodadas < (40 / QuantidadeJogadores(partida)))
    {
        jogadas = 0;
        atual = JogadorInicial(partida);
        vez = PC(atual);

        partida->mesa = CMVazio();

        while(jogadas < QuantidadeJogadores(partida))
        {
            clrscr();
            ImprimeMesa(partida);
            printf("Jogador %i, sua vez!\n\n", IndiceJogador(atual));
            //sleep(1);

            switch(vez)
            {
            case HUMANO:
                if(ModoDev(partida))
                {
                    escolhida = MenuPartida(partida, baralho, atual);
                }
                else
                {
                    escolhida = JogaCartaHumano(partida, atual);
                }


                if(jogadas == 0)
                {
                    //sleep(1);
                }
                clrscr();

                jogadas++;
                vez = PC(atual->prox);
                break;

            case IA:
                printf("Jogador %i:\n", IndiceJogador(atual));
                // //sleep(1);
                if(Dificuldade (partida) == DIFICIL)
                {
                    if(jogadas == 0)
                    {
                        if(QuantidadeJogadores(partida) == 2)
                            escolhida = PC2Jogadores1(Mao(atual), Mesa(partida), corte, &seteSaiu);
                        else
                            escolhida = PC4Jogadores1(Mao(atual), Mesa(partida), corte, &seteSaiu);
                    }
                    else if(jogadas == 1)
                    {
                        if(QuantidadeJogadores(partida) == 2)
                            escolhida = PC2Jogadores2(Mao(atual), Mesa(partida), corte, &seteSaiu);
                        else
                            escolhida = PC4Jogadores2(Mao(atual), Mesa(partida), corte, &seteSaiu);
                    }
                    else if(jogadas == 2)
                    {
                        escolhida = PC4Jogadores3(Mao(atual), Mesa(partida), corte, &seteSaiu);
                    }
                    else if(jogadas == 3)
                    {
                        escolhida = PC4Jogadores4(Mao(atual), Mesa(partida), corte, &seteSaiu);
                    }
                }
                else if (Dificuldade(partida) == FACIL)
                {
                    escolhida = PCXJogadoresAleatorio(Mao(atual), Mesa(partida), corte, &seteSaiu);
                }
                jogadas++;
                vez = PC(atual->prox);
                ImprimeCarta(escolhida);
                //sleep(1);
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
        if(QuantidadeMonte(baralho) > 0)
        {
            printf("Comprando cartas para os jogadores...\n");
        }
        DistribuiCartas(partida, 1, baralho);

        rodadas++;
        DestroiMonte(Mesa(partida));
        free(Mesa(partida));

        //sleep(1);
    }

    DestroiMonte(baralho);
}

void FinalizaPartida(tPartida *partida)
{
    int PJ1 = 0, PJ2 = 0;
    tJogador *atual = partida->inicial;

    for(int i = 1; i <= QuantidadeJogadores(partida); i ++) {
        if(i % 2)
        {
            PJ1 = ContaPontos(Pontuacao(atual)) + PJ1;
        }
        else
        {
            PJ2 = ContaPontos(Pontuacao(atual)) + PJ2;
        }
        atual = atual->prox;
    }

    if(PJ2 > PJ1)
    {
        MoveCabeca(partida, 1);
        atual = partida->inicial;
    }

    clrscr();
    printf("Pontuacao de cada jogador:\n");
    ImprimePontuacao(partida);

    switch(QuantidadeJogadores(partida))
    {
    case 2:
        printf("\nO campeao foi o jogador %i!\n", IndiceJogador(atual));
        if(PC(atual) == HUMANO)
        {
            printf("PARABENS, HUMAN0! Voce GANHOU do carro autonomo da UFES\n");
        }
        else
        {
            printf("PARABENS, HUMAN0! Voce PERDEU pro laptop da Xuxa\n");
        }

        break;

    case 4:
        printf("A dupla campea foram os jogadores %i e %i!\n", IndiceJogador(atual), IndiceJogador((atual->prox)->prox));
        if((PC(atual) == HUMANO) || (IndiceJogador((atual->prox)->prox) == HUMANO))
        {
            printf("PARABENS, HUMAN0! Voce GANHOU da frota de carros autonomos da UFES\n");
        }
        else
        {
            printf("PARABENS, HUMAN0! Voce perdeu para os laptops da Xuxa\n");
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
    //sleep(1);
}
