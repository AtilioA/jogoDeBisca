#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/Jogo.h"
#include "../include/BaralhoEncadeado.h"
/*
 As opções
- Mostrar cartas do monte (na ordem que ela estiver)
- Embaralhar
- Cortar
estarão disponíveis apenas quando o jogo começar e em modo desenvolvedor

// void exibeInfo(tJogador *jogadores, int nJogadores)
// {
//     int i = 0;
//     tJogador J1 = jogadores[0]; // Jogador 1 ("eu")

//     printf("Sua mao:\n");
//     // imprimeMao(J1);

//     printf("Cartas restantes no monte: ");
//     Mostra cartas restantes no monte

//     printf("Pontuação dos jogadores: ");
//     for (i = 0; i < nJogadores; i++)
//     {
//         printf("Pontuacao do %i jogador: %i.\n", i + 1, jogadores[i].pontuacao);
//     }

//     printf("\n");
// }

// Opções extras para modo desenvolvedor (para printar mais facilmente)
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
    //int modoDev = 0;
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
            //modoDev = 0;
            // Função que começa o jogo
            break;

        case '2':
            return;

        case '3':
            exibeAjuda();
            break;

        case '4':
            //modoDev = 1;
            // Função que começa o jogo
            break;

        // Quando o jogo estiver ativo
        case '7':
            //modoDev = 1;
            // imprimeLista(monte);

            break;

        case '8':
            //modoDev = 1;
            // embaralhaLista(monte);
            break;

        case '9':
            //modoDev = 1;
            char valorCortado, naipeCortado;
            tCarta cartaCortada;
            printf("Informe a carta a ser cortada [Valor/Naipe]:\n");
            scanf(" %c %c", &valorCortado, &naipeCortado);
            Corta(valorCortado, naipeCortado, monte, &cartaCortada);
            break;

            while (op < '1' || op > '9')
            {
                printf("Opcao invalida. Tente novamente: ");
                scanf(" %c", &op);
            }
        }
    }
}
*/
