#include "include/IA2Jogadores.h"
#include "include/IA4Jogadores.h"
#include "include/MaosSimples.h"
#include "include/Cartas.h"
#include "include/BaralhoEncadeado.h"
#include "include/PartidaCircular.h"
#include "include/Jogo.h"
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese_Brasil");
    tPartida *partida;
    printf("teste: ááãçéíóúâêÎôûâÂáÁ\n\n");
    ExibeMenuInicial(partida);

    return 0;
}
