#include "include/IA2Jogadores.h"
#include "include/IA4Jogadores.h"
#include "include/Maos.h"
#include "include/Cartas.h"
#include "include/BaralhoEncadeado.h"
#include <time.h>

int main()
{
    tMao mao;
    tMonte monte;

    CriaMao(&mao);
    FMVazio(&monte);
    CriaBaralho(&monte);
    ImprimeMonte(&monte);
    printf("\n");
    Embaralha(&monte);
    ImprimeMonte(&monte);

    LiberaMao(&mao);
    DestroiMonte(&monte);

    return 0;
}
