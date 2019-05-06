#include "../include/Cartas.h"

int CartaValida(tCarta carta)
{
    if ((carta.naipe == NAIPES[0]) || (carta.naipe == NAIPES[1]) ||
        (carta.naipe == NAIPES[2]) || (carta.naipe == NAIPES[3]))
    {
        for (int i = 0; i < nVALORES; i++)
        {
            if (carta.valor == VALORES[i])
            {
                return 1;
            }
        }
    }
    return 0;
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

int CartasIguais(tCarta carta1, tCarta carta2)
{
    return ((Valor(carta1) == Valor(carta2)) && (Naipe(carta1) == Naipe(carta2)));
}

int PontoAlto(tCarta carta)
{
    return ((Valor(carta) == '7') || (Valor(carta) == 'A'));
}

int PontoBaixo(tCarta carta)
{
    return ((Valor(carta) == 'Q') || (Valor(carta) == 'J') || (Valor(carta) == 'K'));
}

int ETrunfo(tCarta carta, tCarta corte)
{
    return (Naipe(carta) == Naipe(corte));
}

void ImprimeCarta(tCarta carta)
{
    if (!(CartaValida(carta)))
    {
        return;
    }

    printf("%c ", carta.valor);

#ifdef __unix__
    if (carta.naipe == NAIPES[0])
        printf("\u2665\n");
    else if (carta.naipe == NAIPES[1])
        printf("\u2666\n");
    else if (carta.naipe == NAIPES[2])
        printf("\u2663\n");
    else if (carta.naipe == NAIPES[3])
        printf("\u2660\n");

#elif defined(WIN32) || defined(WIN64)
    printf("%c\n", carta.naipe);
#endif
}

char Valor(tCarta carta)
{
    if (!(CartaValida(carta)))
    {
        return (' ');
    }
    return (carta.valor);
}

char Naipe(tCarta carta)
{
    if (!(CartaValida(carta)))
    {
        return (' ');
    }
    return (carta.naipe);
}
