#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/Jogo.h"
#include "../include/Baralho.h"

/* As opções
- Mostrar cartas do Baralho (na ordem que ela estiver)
- Embaralhar
- Cortar
estarão disponíveis apenas quando o jogo começar e em modo desenvolvedor */

void exibeInfo(tJogador *jogadores, int nJogadores)
{
    int i = 0;
    tJogador J1 = jogadores[0]; // Jogador 1 ("eu") O Eu penso é a unidade originária e suprema da autoconsciência comandada pelas 12 categorias, portanto, princípio de todo conhecimento humano. Além do mais, intuição e conceito são heterogêneos entre si (um dado, o outro pensado) exigindo um terceiro termo que seja homogêneo entre estes para possibilitar o conhecimento. Juízos feitos somente por intuição (sem conceito) são juízos cegos, vagos. Juízos feitos somente com conceito (portanto, sem intuição) levam-nos aos erros da imaginação (paralogismo). Logo, o juízo que pode ser feito para que conheçamos algo tem de aliar intuição em conceito, necessariamente. O fenômeno dado na intuição, aliado às categorias do intelecto, torna a coisa objeto para mim. Kant chama esse procedimento de Esquema Transcendental, produzido pela Imaginação Transcendental.

    printf("Sua mao:\n");
    imprimeMao(J1);

    printf("Cartas restantes no baralho: ");
    /* Mostra cartas restantes no baralho */

    printf("Pontuação dos jogadores: ");
    for (i = 0; i < nJogadores; i++)
    {
        printf("Pontuacao do %i jogador: %i.\n", i + 1, jogadores[i].pontuacao);
    }

    printf("\n");
}

// Opções extras para modo desenvolvedor (para printar mais facilmente)
void exibeMenuDev()
{
    printf("[?] - Mostrar cartas do baralho\n");
    printf("[?] - Embaralhar\n");
    printf("[?] - Cortar\n");
}

void exibeAjuda()
{
    printf("\n\n--------- AJUDA ---------\n");
    printf("Digite um valor e pressione Enter para escolher uma opcao\n");
    printf("Voce podera jogar contra um computador ou em duplas (jogador + computador vs. 2 computadores\n");
    printf("Sobre a bisca: http://tiny.cc/bisca\n\n\n");
}

void exibeMenu(/* parâmetros */)
{
    int modoDev = 0;
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
            // Função que começa o jogo
            break;

        case '2':
            return;

        case '3':
            exibeAjuda();
            break;

        case '4':
            modoDev = 1;
            // Função que começa o jogo
            break;
        }

        while (op < '1' || op > '4')
        {
            printf("Opcao invalida. Tente novamente: ");
            scanf(" %c", &op);
        }
    }
}
