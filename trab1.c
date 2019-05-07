#include "include/IA2Jogadores.h"
#include "include/IA4Jogadores.h"
#include "include/MaosSimples.h"
#include "include/Cartas.h"
#include "include/BaralhoEncadeado.h"
#include "include/PartidaCircular.h"
#include "include/Jogo.h"

int main()
{
    tPartida *partida;
    ExibeMenuInicial(partida);
    DestroiPartida(partida);

    return 0;
}
