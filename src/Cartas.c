#include "../include/Cartas.h"

int CartaValida(tCarta carta)
{
    if ((carta.naipe == NAIPES[0]) || (carta.naipe == NAIPES[1]) ||
        (carta.naipe == NAIPES[2]) || (carta.naipe == NAIPES[3]))
    {
        for (int i = 0; i < nVALORES; i++)
        {
            if (carta.valor == VALORES[i])
                return (1);
        }
    }
    return (0);
}

tCarta PreencheCarta(char valor, char naipe)
{
    tCarta carta;

    carta.valor = valor;
    carta.naipe = naipe;

    return carta;
}

tCarta CartaVazia()
{
    return (PreencheCarta(' ', ' '));
}

void ImprimeCartaLinux(tCarta carta)
{
    if (!(CartaValida(carta)))
        return;

    printf("%c", carta.valor);

    if (carta.naipe == NAIPES[0])
        printf("\u2665");
    else if (carta.naipe == NAIPES[1])
        printf("\u2666");
    else if (carta.naipe == NAIPES[2])
        printf("\u2663");
    else if (carta.naipe == NAIPES[3])
        printf("\u2660");
}

char Valor(tCarta carta)
{
    if (!(CartaValida(carta)))
        return (' ');
    return (carta.valor);
}

char Naipe(tCarta carta)
{
    if (!(CartaValida(carta)))
        return (' ');
    return (carta.naipe);
}
