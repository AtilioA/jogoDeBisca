// Define os valores possíveis para número e naipe das cartas do baralho
#define VALORES "23456QJK7A"
#define NAIPES "COPE"
#define nVALORES 10
#define nNAIPES 4
// Número padrão de cartas em uma mão
#define nMAO 3

#include "include/BaralhoEncadeado.h"

int main () {
    tMonte monte;
    FMVazio (&monte);
    CriaBaralho (&monte);
    ImprimeMonte (&monte);
    DestroiMonte (&monte);

    return 0;
}
