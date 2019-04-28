// Define os valores possíveis para número e naipe das cartas do baralho
#define VALORES "23456QJK7A"
#define NAIPES "COPE"
#define nVALORES 10
#define nNAIPES 4
#define nMAO 3 // Número padrão de cartas em uma mão

#include "include/IA2Jogadores.h"
#include <time.h>

int main()
{
    tCarta jogada, corte;
    tMao mao;
    tMonte monte, joao;
    FMVazio(&monte);
    CriaBaralho(&monte);
    ImprimeMonte(&monte);
    Embaralha(&monte);
    ImprimeMonte(&monte);
    printf("\n");
    FMVazio(&joao);
    for (size_t i = 1; i <= 38; i++) {
        CriaMao (&mao);
        srand (time (NULL));
        corte = CartaNoIndice ((rand ( ) % 40)+1, &monte);
        jogada = CartaNoIndice (i, &monte);
        ColocaNaMao (jogada, &mao);
        jogada = CartaNoIndice (i+1, &monte);
        ColocaNaMao (jogada, &mao);
        jogada = CartaNoIndice (i+2, &monte);
        ColocaNaMao (jogada, &mao);
        ImprimeMao(mao);
        printf("\n");

        ImprimeCarta (PC2Jogadores1 (&mao, &joao, corte, 0));

        DestroiMonte(&joao);
    }

    printf("\n");
    DestroiMonte(&monte);

    return 0;
}
