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

    CriaBaralho(&monte);
    ImprimeMonte(&monte);

    printf("Embaralhando...\n");
    Embaralha(&monte);
    ImprimeMonte(&monte);

<<<<<<< HEAD
int main () {
    tMonte monte;
    FMVazio (&monte);
    CriaBaralho (&monte);
    ImprimeMonte (&monte);
    DestroiMonte (&monte);

=======
>>>>>>> 6814b84a38007cc8fedb2f65d1d302fc569b21d6
    return 0;
}
