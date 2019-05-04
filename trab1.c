#include "include/IA2Jogadores.h"
#include "include/IA4Jogadores.h"
#include "include/Maos.h"
#include "include/Cartas.h"
#include "include/BaralhoEncadeado.h"
#include "include/PartidaCircular.h"
#include "include/Jogo.h"
#include <time.h>

int main()
{
    tJogador *atual;
    tMonte baralho;
    tPartida *partida;
    CriaBaralho (&baralho);
    partida = CriaPartida(4, &baralho);
    atual = partida->inicial;
    while (1) {
        printf("%d\n", IndiceJogador(atual));
        atual = atual->prox;
        sleep (1);
    }
    //Partida (partida);
    DestroiPartida (partida);

    /* Teste MandaPontosJogador (apagar no próximo commit)
    tMonte mesa;
    tJogador vencedor;
    FMVazio(&vencedor.pontos);
    FMVazio(&mesa);
    ImprimeMonte(&vencedor.pontos);
    ImprimeMonte(&mesa);
    // InsereJogador(&vencedor);
    tCarta carta = PreencheCarta('7', 'C');
    tCarta carta2 = PreencheCarta('7', 'O');
    tCarta carta3 = PreencheCarta('A', 'O');
    tCarta carta4 = PreencheCarta('K', 'E');
    tCarta carta5 = PreencheCarta('J', 'P');
    Insere(carta, &mesa);
    Insere(carta2, &mesa);
    Insere(carta3, &mesa);
    Insere(carta4, &mesa);
    Insere(carta5, &mesa);
    printf("Cartas na mesa:\n");
    ImprimeMonte(&mesa);
    printf("Mandando pontos para jogador vencedor...\n");
    MandaPontosJogador(&vencedor, &mesa);
    printf("Mesa:\n");
    ImprimeMonte(&mesa);
    printf("Monte de pontos do jogador:\n");
    ImprimeMonte(&vencedor.pontos);
    int pontos = ContaPontos(&vencedor.pontos);
    printf("Pontos do jogador: %i\n", pontos);
    DestroiMonte(&mesa);
    DestroiMonte(&vencedor.pontos);
    */

    /* Se precisar do que estava aqui é só pegar no GitHub */

    return 0;
}
