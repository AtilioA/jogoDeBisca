#ifndef LISTAENC_H_
#define LISTAENC_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int Chave;
    /* outros componentes */
} TipoItem;

typedef struct TipoCelula *TipoApontador;

typedef struct TipoCelula
{
    TipoItem Item;
    TipoCelula *Prox;
} TipoCelula;

typedef struct
{
    TipoCelula *Primeiro, *Ultimo;
} TipoLista;

/* Faz a lista ficar vazia */
void FLVazia(TipoLista *Lista);

/*Verifica se a lista est� vazia*/
int Vazia(TipoLista Lista);

/* Insere x ap�s o �ltimo elemento da lista */
void Insere(TipoItem x, TipoLista *Lista);

/*Op��o que n�o modifica o lista.h */
void Retira(TipoApontador p, TipoLista *Lista, TipoItem *Item);
/*Imprime a lista */
void Imprime(TipoLista Lista);

#endif /* LISTAENC_H_ */
