/* Esta biblioteca contém o código que implementa ferramentas relevantes a
 * uma partida de bisca, como as estruturas tPartida e tJogador
 * e as funções que as envolvem.
 */

#ifndef __PARTIDACIRCULAR_H
#define __PARTIDACIRCULAR_H

#define HUMANO 0
#define IA 1

#include "BaralhoEncadeado.h"
#include "IA4Jogadores.h"

// Estrutura de dados que abstrai um jogador, que possui "mão" e pontuação
typedef struct tJogador tJogador;
struct tJogador
{
    int PC;
    int indice;
    tMao mao;
    tMonte pontos;
    tJogador *prox;
};

// Estrutura de dados que abstrai uma partida, que possui monte, número de jogadores, corte e jogador inicial da rodada
typedef struct
{
    int nJogadores;
    int modoDev;
    int dificuldade;
    tCarta corte;
    // tMonte *monte;
    tMonte *mesa;
    tJogador *inicial;
} tPartida;

/* Funções para acessar estrutura opaca */
// Retorna a quantidade de jogadores de uma partida
int QuantidadeJogadores(tPartida *partida);
// Retorna a referência do jogador inicial atual de uma partida
tJogador *JogadorInicial(tPartida *partida);
// Retorna o corte de uma partida
tCarta Corte(tPartida *partida);
// Retorna a referência do monte pontuação de um jogador
tMonte *Pontuacao(tJogador *jogador);
// Retorna a referência da mão de um jogador
tMao *Mao(tJogador *jogador);
// Retorna a referência da mesa de uma partida
tMonte *Mesa(tPartida *partida);
// Retorna se a partida está em modo de desenvolvedor
int ModoDev(tPartida *partida);
// Retorna se o jogador é um humano ou computador
int PC(tJogador *jogador);

int Dificuldade(tPartida *partida);

// Manda as cartas da mesa para o jogador que ganhou a rodada (contando como pontuação deste)
void MandaPontosJogador(tJogador *vencedor, tMonte *mesa);

// Inicializa uma variável tJogador e insere na lista de jogadores
tJogador *InsereJogador(tJogador *jogador);

void PreparaPartida(tPartida *partida, int nJogadores, int posHumano);

// Libera os elementos da partida da memória, como jogadores, mesa, etc.
void DestroiPartida(tPartida *partida);

// Move um jogador por n posições e torna ele o primeiro jogador (???)
void MoveCabeca(tPartida *partida, int n);

// Imprime as pontuações de todos os jogadores da partida
void ImprimePontuacao(tPartida *partida);

// Pede para o jogador qual carta quer jogar na mesa e realiza o procedimento
tCarta JogaCartaHumano(tPartida *partida, tJogador *humano);

// Retorna o índice de um jogador
int IndiceJogador(tJogador *jogador);

// Determina o vencedor de uma rodada e retorna-o
tJogador *Vencedor(tPartida *partida);

#endif
