/* 
 * File:   Pontuacao.cpp
 * Author: Abrams
 * 
 * Created on 26 de Agosto de 2016, 11:24
 */
#ifndef PONTUACAO_CPP
#define PONTUACAO_CPP
#include "stdio.h"
#include "Pontuacao.h"

#define WIN 100000
#define LOSE -100000

///std::list<Pedra*>::iterator it;
//for( it = lista.begin(); it != lista.end(); it++){}

Pontuacao::Pontuacao() {
}

int Pontuacao::somarH(int tabuleiro[15][15]) {
    printf("Somando as horizontais\n");

    int espacosD = 0;
    int espacosA = 0;
    int pontos1 = 0;
    int pontos2 = 0;
    int soma1 = 0;
    int soma2 = 0;
    int lastSymbol = 0;

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            if (tabuleiro[i][j] == 0) {
                if (pontos1 == 0 && pontos2 == 0) {
                    espacosA++;
                } else {
                    espacosD++;
                }
                lastSymbol = 0;
            }
            if (tabuleiro[i][j] == 1) {
                pontos1++;
                if (pontos2 > 0) {
                    soma2 += heuristica(espacosA, pontos2, espacosD);
                    pontos2 = 0;
                    espacosA = espacosD;
                    espacosD = 0;
                }
                if (lastSymbol == 0) {
                    espacosA += espacosD;
                    espacosD = 0;
                }
                lastSymbol = 1;
            }
            if (tabuleiro[i][j] == 2) {
                pontos2++;
                if (pontos1 > 0) {
                    soma1 += heuristica(espacosA, pontos1, espacosD);
                    pontos1 = 0;
                    espacosA = espacosD;
                    espacosD = 0;
                }
                if (lastSymbol == 0) {
                    espacosA += espacosD;
                    espacosD = 0;
                }
                lastSymbol = 2;
            }
        }
        if (pontos1 > 0) {
            soma1 += heuristica(espacosA, pontos1, espacosD);
        }
        if (pontos2 > 0) {
            soma1 += heuristica(espacosA, pontos2, espacosD);
        }
        espacosD = 0;
        espacosA = 0;
        pontos1 = 0;
        pontos2 = 0;
        soma1 = 0;
        soma2 = 0;
        lastSymbol = 0;
    }
}

int Pontuacao::somarV(int tabuleiro[15][15]) {
    printf("Somando as verticais\n");

    int espacosD = 0;
    int espacosA = 0;
    int pontos1 = 0;
    int pontos2 = 0;
    int soma1 = 0;
    int soma2 = 0;
    int lastSymbol = 0;

    for (int j = 0; j < 15; j++) {
        for (int i = 0; i < 15; i++) {
            if (tabuleiro[i][j] == 0) {
                if (pontos1 == 0 && pontos2 == 0) {
                    espacosA++;
                } else {
                    espacosD++;
                }
                lastSymbol = 0;
            }
            if (tabuleiro[i][j] == 1) {
                pontos1++;
                if (pontos2 > 0) {
                    soma2 += heuristica(espacosA, pontos2, espacosD);
                    pontos2 = 0;
                    espacosA = espacosD;
                    espacosD = 0;
                }
                if (lastSymbol == 0) {
                    espacosA += espacosD;
                    espacosD = 0;
                }
                lastSymbol = 1;
            }
            if (tabuleiro[i][j] == 2) {
                pontos2++;
                if (pontos1 > 0) {
                    soma1 += heuristica(espacosA, pontos1, espacosD);
                    pontos1 = 0;
                    espacosA = espacosD;
                    espacosD = 0;
                }
                if (lastSymbol == 0) {
                    espacosA += espacosD;
                    espacosD = 0;
                }
                lastSymbol = 2;
            }
        }
        if (pontos1 > 0) {
            soma1 += heuristica(espacosA, pontos1, espacosD);
        }
        if (pontos2 > 0) {
            soma1 += heuristica(espacosA, pontos2, espacosD);
        }
        espacosD = 0;
        espacosA = 0;
        pontos1 = 0;
        pontos2 = 0;
        soma1 = 0;
        soma2 = 0;
        lastSymbol = 0;
    }
}

int Pontuacao::somarDP(int tabuleiro[15][15]) {
    printf("Somando a diagonal principal\n");

    int espacosD = 0;
    int espacosA = 0;
    int pontos1 = 0;
    int pontos2 = 0;
    int soma1 = 0;
    int soma2 = 0;
    int lastSymbol = 0;
    
    for (int i = 0, j = 0, r = 0; r < 11; r++, j = r, i = 0) {//r<11 devido a otimização de não precisar ver os cantos que não possam mais formar vitória.
        for (; j <= (15 - r);i++, j++) {
            if (tabuleiro[i][j] == 0) {
                if (pontos1 == 0 && pontos2 == 0) {
                    espacosA++;
                } else {
                    espacosD++;
                }
                lastSymbol = 0;
            }
            if (tabuleiro[i][j] == 1) {
                pontos1++;
                if (pontos2 > 0) {
                    soma2 += heuristica(espacosA, pontos2, espacosD);
                    pontos2 = 0;
                    espacosA = espacosD;
                    espacosD = 0;
                }
                if (lastSymbol == 0) {
                    espacosA += espacosD;
                    espacosD = 0;
                }
                lastSymbol = 1;
            }
            if (tabuleiro[i][j] == 2) {
                pontos2++;
                if (pontos1 > 0) {
                    soma1 += heuristica(espacosA, pontos1, espacosD);
                    pontos1 = 0;
                    espacosA = espacosD;
                    espacosD = 0;
                }
                if (lastSymbol == 0) {
                    espacosA += espacosD;
                    espacosD = 0;
                }
                lastSymbol = 2;
            }
        }
        if (pontos1 > 0) {
            soma1 += heuristica(espacosA, pontos1, espacosD);
        }
        if (pontos2 > 0) {
            soma1 += heuristica(espacosA, pontos2, espacosD);
        }
        espacosD = 0;
        espacosA = 0;
        pontos1 = 0;
        pontos2 = 0;
        soma1 = 0;
        soma2 = 0;
        lastSymbol = 0;
    }
}

int Pontuacao::somarDS(int tabuleiro[15][15]) {
    printf("Somando a diagonal secundaria\n");
    
}

int Pontuacao::somarPontuacao(int tabuleiro[15][15]) {

    return somarH(tabuleiro) + somarV(tabuleiro) + somarDP(tabuleiro);
}

int Pontuacao::heuristica(int espacosA, int pontos, int espacosD) {
    //Aqui vou avaliar a situacao da ultima carreira de pedras e dar-lhes uma pontuacao
    //switchzao
    printf("Pontos: %i\n", pontos);
    printf("Espacos: %i\n", espacosA + espacosD);

    if (pontos == 5) {
        return WIN;
    } else {
        return 0;
    }
}

Pontuacao::Pontuacao(const Pontuacao& orig) {
}

Pontuacao::~Pontuacao() {
}

#endif

