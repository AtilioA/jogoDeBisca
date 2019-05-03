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
    tMonte baralho;
    //tPartida partida;
    CriaBaralho (&baralho);
    //Embaralha (&baralho);
    TrocaCarta(&baralho, baralho.primeiro->prox, 40);
    ImprimeMonte(&baralho);
    ImprimeCarta(Corta (&baralho, 7));
    DestroiMonte(&baralho);

    //CriaPartida (4, &partida, &baralho);
    //exibeMenuDev (&partida);
    // DestroiPartida (&partida); // Segmentation fault
    // TESTE DE IA
    //int posAleatoria;
    //tCarta carta;
    //tMao mao;
    //tMonte monte, mesa;

    //FMVazio(&monte);

    //DestroiMonte(&monte);
    //CriaBaralho(&monte);
    //Embaralha(&monte);
    //ImprimeMonte(&monte);
    //ImprimeCarta(Corta(&monte, 10));
    //ImprimeMonte(&monte);
/*
    for (size_t i = 0; i < 100; i++) {
        CriaMao(&mao);
        posAleatoria = (rand () % 40) + 1;
        carta = CartaNoIndice (posAleatoria, &monte);
        ColocaNaMao(carta, &mao);
        posAleatoria = (rand () % 40) + 1;
        carta = CartaNoIndice (posAleatoria, &monte);
        ColocaNaMao(carta, &mao);
        posAleatoria = (rand () % 40) + 1;
        carta = CartaNoIndice (posAleatoria, &monte);
        ColocaNaMao(carta, &mao);

        posAleatoria = (rand () % 40) + 1;
        carta = CartaNoIndice (posAleatoria, &monte);
        //printf("Mao:\n");
        //ImprimeMao(mao);
        FMVazio(&mesa);
        //printf("Jogada1:\n");
        ImprimeCarta (PC4Jogadores1 (&mao, &mesa, carta, 1));
        posAleatoria = (rand () % 40) + 1;
        carta = CartaNoIndice (posAleatoria, &monte);
        ColocaNaMao(carta, &mao);
        //printf("Nova mao:\n");
        //ImprimeMao(mao);
        //printf("Jogada2:\n");
        ImprimeCarta (PC4Jogadores2 (&mao, &mesa, carta, 1));
        posAleatoria = (rand () % 40) + 1;
        carta = CartaNoIndice (posAleatoria, &monte);
        ColocaNaMao(carta, &mao);
        //printf("Nova mao:\n");
        //ImprimeMao(mao);
        //printf("Jogada2:\n");
        ImprimeCarta (PC4Jogadores3 (&mao, &mesa, carta, 1));
        posAleatoria = (rand () % 40) + 1;
        carta = CartaNoIndice (posAleatoria, &monte);
        ColocaNaMao(carta, &mao);
        //printf("Nova mao:\n");
        //ImprimeMao(mao);
        //printf("Jogada2:\n");
        ImprimeCarta (PC4Jogadores4 (&mao, &mesa, carta, 1));
        posAleatoria = (rand () % 40) + 1;
        carta = CartaNoIndice (posAleatoria, &monte);
        printf("Trunfo: ");
        ImprimeCarta (carta);
        printf("Maior mesa: ");
        ImprimeCarta(MaiorMesa (&mesa, carta));
        printf("\n");
        printf("\n");
        LiberaMao(&mao);
        DestroiMonte(&mesa);
    }
*/

    return 0;
}
