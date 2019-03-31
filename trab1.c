/*
                  ＴＲＡＢＡＬＨＯ　ＥＤ　Ｉ
        Atílio Antônio Dadalto e Leandro Furlam Turi
                       Data: 05/2019                        */

#include <stdio.h>
#include <stdlib.h>
#include "include/Baralho.h"
// #include "include/Jogo.h"

int main()
{
    carta *baralho;

    baralho = escreveBaralho();
    imprimeBaralho(baralho, 40);

    embaralhaBaralho(baralho);
    imprimeBaralho(baralho, 40);

    free(baralho);

    return 0;
}
