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

void CriaPartida (int nJogadores, tPartida *partida, tMonte *baralho) {
    int p;
    tCarta trunfo;

    printf("Iniciando a partida de %d jogadores...\n", nJogadores);
    PreparaPartida (partida, nJogadores);
    partida->monte = baralho;
    // FMVazio(partida->mesa); // ??? Parou de funcionar
    printf ("Embaralhando o baralho...\n");
    Embaralha(Baralho(partida));
    // sleep (1);

    printf ("Pronto! Agora sorteando quem sera o primeiro a jogar...\n");
    struct timeval t;
    gettimeofday(&t, NULL);
    srand((unsigned int)t.tv_usec);
    p = (rand ( ) % nJogadores) + 1;
    MoveCabeca (partida, p);
    // sleep (1);
    printf ("Sera o jogador %d!\n\n", p);

    printf ("Jogador %d, passe os comandos ao jogador a sua ESQUERDA para que ele possa cortar.\n", p);
    p = p - 1;
    if (p == 0) p = nJogadores;
    // sleep (1);
    printf ("Jogador %d, escolha uma posicao de 1 a 40 para cortar o baralho.\n", p);
    scanf ("%d", &p);
    // p = (p % 40) + 1;
    trunfo = Corta (Baralho (partida), p);
    partida->corte = trunfo;
    printf ("O trunfo escolhido foi ");
    ImprimeCarta (trunfo);

    printf ("Agora serao entregues as cartas...\n");
    ImprimeMonte(Baralho(partida));
    DistribuiCartas(partida);
    printf("Mao do jogador:\n");
    ImprimeMao(*Mao(partida->inicial));
    // JogaCartaHumano(partida, partida->inicial);
    // printf("Mesa:\n");
    // ImprimeMonte(Mesa(partida));
    // printf("Mao do jogador:\n");
    // ImprimeMao(partida->inicial->mao);
}

void DistribuiCartas (tPartida *partida)
{
    int i = 0, j = 0;
    tJogador *jogadorAtual = partida->inicial;
    tCarta cartaAtual;
    tMao *maoJogador;

    for (i = 1; i < QuantidadeJogadores(partida); i++)
    {
        for (j = 0; j < nMAO; j++)
        {
            cartaAtual = (CartaNoIndice(1, partida->monte));
            maoJogador = Mao(jogadorAtual);
            MonteParaMao(&cartaAtual, Baralho(partida), maoJogador);
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
void MenuPartida(tPartida *partida)
{
    int op = 0, p = 0;

    PrintaPontuacao(partida);
    printf("Cartas restantes no baralho/monte: %i\n", QuantidadeMonte(Baralho(partida)));
    printf("\nQuantidade de cartas na mao: %i\n", TamanhoMao(*Mao(JogadorInicial(partida)))); // não sei qual é o jogador inicial

    printf("[1] - Jogar carta\n");
    printf("[2] - Sair\n");
    printf("[3] - Ajuda\n");
    printf("[4] - Pontuação dos jogadores\n");

    if (ModoDev(partida))
    {
        printf ("[10] - Mostrar cartas do monte\n");
        printf ("[11] - Embaralhar\n");
        printf ("[12] - Cortar\n");
    }

    scanf ("%d", &op);

    switch (op) {
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
                ImprimeMonte (Mesa (partida));
            }
        break;

        case 11:
            if (ModoDev(partida))
            {
                printf("Embaralhando...\n");
                Embaralha (Mesa (partida));
                ImprimeMonte (Mesa (partida));
            }
        break;

        case 12:
            if (ModoDev(partida))
            {
                printf ("Escolha a posicao de 1 a 40 para cortar\n");
                scanf ("%d", &p);
                printf("Corte:\n");
                ImprimeCarta (Corta (Mesa (partida), p));
            }
        break;

        default:
            printf ("thank u, next.\n");
        break;
    }
}

void exibeMenuInicial (tPartida *partida)
{
    int modoDev;
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
void Partida (tPartida *partida)
{
     int jogadas, rodadas, vez, seteSaiu, vencedor;
     tCarta corte, escolhida;
     tJogador *atual;

     corte = Corte (partida);
     seteSaiu = 0;
     vez = PC (JogadorInicial(partida));
     rodadas = 0;

     while (rodadas <= (40 / QuantidadeJogadores (partida))) {
         jogadas = 0;
         atual = partida->inicial;

         while (jogadas < QuantidadeJogadores (partida)) {
             switch (vez) {
                 case HUMANO:
                    MenuPartida(partida);
                    jogadas ++;
                    vez = PC (atual->prox);
                 break;

                 case IA: // Falta determinar a dificuldade pela entrada do usuário
                    if (jogadas == 0) {
                        if (QuantidadeJogadores (partida) == 2)
                            escolhida = PC2Jogadores1 (Mao (atual), Mesa (partida), corte, &seteSaiu);
                        else
                            escolhida = PC4Jogadores1 (Mao (atual), Mesa (partida), corte, &seteSaiu);
                    }
                    else if (jogadas == 1) {
                        if (QuantidadeJogadores (partida) == 2)
                            escolhida = PC2Jogadores2 (Mao (atual), Mesa (partida), corte, &seteSaiu);
                        else
                            escolhida = PC4Jogadores2 (Mao (atual), Mesa (partida), corte, &seteSaiu);
                    }
                    else if (jogadas == 2) {
                        escolhida = PC4Jogadores3 (Mao (atual), Mesa (partida), corte, &seteSaiu);
                    }
                    else if (jogadas == 3) {
                        escolhida = PC4Jogadores4 (Mao (atual), Mesa (partida), corte, &seteSaiu);
                    }
                    jogadas ++;
                    vez = PC (atual->prox);
                 break;
             }
             ImprimeCarta (escolhida);
             atual = atual->prox;
         }
         vencedor = Vencedor (partida);
         printf ("%d venceu essa rodada\n", vencedor);
         rodadas ++;
    }
}
