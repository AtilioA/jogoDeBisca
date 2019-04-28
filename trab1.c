// Define os valores possíveis para número e naipe das cartas do baralho
#define VALORES "23456QJK7A"
#define NAIPES "COPE"
#define nVALORES 10
#define nNAIPES 4
#define nMAO 3 // Número padrão de cartas em uma mão

#include "include/BaralhoEncadeado.h"
#include "include/Cartas.h"

int main()
{
    tMonte monte;
    FMVazio(&monte);
    CriaBaralho(&monte);
    ImprimeMonte(&monte);
    Embaralha(&monte);
    ImprimeMonte(&monte);
    DestroiMonte(&monte);

    return 0;
}
