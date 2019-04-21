

#include "IA2Jogadores.h"


/*
typedef struct {
    tCarta carta;
    struct tBaralho *proxima;
} tBaralho;

void embaralhaBaralho (carta *baralho) {
    if (baralho == NULL)
        return;

    int pos;
    carta aux;

    srand (time (NULL));                                                        // inicializar o gerador de números aleatórios com o valor da função time(NULL)
    for (int i = 0; i < nBARALHO; i ++) {
        pos = rand ( ) % nBARALHO;
        aux = baralho[i];
        baralho[i] = baralho[pos];
        baralho[pos] = aux;
    }
}

carta *escreveBaralho ( ) {
    int posNaipe, posValor;
    carta *baralho;

    baralho = (carta *) malloc (nBARALHO * sizeof (carta));
    if (baralho == NULL)
        return (NULL);

    for (int i = 0; i < nBARALHO; i ++) {
        posValor = i % nVALORES;
        posNaipe = i / nVALORES;

        baralho[i].valor = VALORES[posValor];
        baralho[i].naipe = NAIPES[posNaipe];
    }

    return (baralho);
}
*/

int main ( ) {
    tCarta carta, mesa, corte;
    tMao mao;
    CriaMao (&mao);
    printf("\n");
    PreencheCarta ('4', 'C', &corte);
    for (size_t i = 0; i < 40; i++) {
        int posValor = i % nVALORES;
        int posNaipe = i / nVALORES;
        PreencheCarta (VALORES[posValor], NAIPES[posNaipe], &mesa);
        ImprimeCarta (mesa);
        printf("\n");
        PreencheCarta ('2', 'C', &carta);
        ColocaNaMao (carta, &mao);
        PreencheCarta ('7', 'O', &carta);
        ColocaNaMao (carta, &mao);
        PreencheCarta ('K', 'E', &carta);
        ColocaNaMao (carta, &mao);
        ImprimeCarta (PC2Jogadores (&mao, mesa, corte, 1));
        printf("\n");
        printf("\n");
    }

    LiberaMao (&mao);

    return (0);
}
