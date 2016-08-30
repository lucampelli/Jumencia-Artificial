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

Pontuacao::Pontuacao() {
}

int Pontuacao::somarPontuacao(int tabuleiro[15][15]) {
    int espacosD = 0;
    int espacosA = 0;
    int pontos1 = 0;
    int pontos2 = 0;
    int soma1 = 0;
    int soma2 = 0;
    bool start = true;
    int lastSymbol = 0;

    //horizontal
    printf("Checando Horizontais");
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            if (tabuleiro[i][j] == 0) {
                if (start) {
                    espacosA++;
                } else {
                    espacosD++;
                }
                lastSymbol = 0;
            }
            if (tabuleiro[i][j] == 1) {
                start = false;
                if (pontos2 > 0) {
                    soma2 = (pontos2 + espacosD + espacosA) * 50;
                    espacosA = espacosD;
                    espacosD = 0;
                    pontos2 = 0;
                }
                pontos1++;
                if (lastSymbol == 0) {
                    espacosA += espacosD;
                    espacosD = 0;
                }
                lastSymbol = 1;
            } else if (tabuleiro[i][j] == 2) {
                start = false;
                if (pontos1 > 0) {
                    soma1 = (pontos1 + espacosD + espacosA) * 50;
                    pontos1 = 0;
                    espacosA = espacosD;
                    espacosD = 0;
                }
                pontos2++;
                if (lastSymbol == 0) {
                    espacosA += espacosD;
                    espacosD = 0;
                }
                lastSymbol = 2;
            }
        }
        espacosD = 0;
        espacosA = 0;
        pontos1 = 0;
        pontos2 = 0;
        soma1 = 0;
        soma2 = 0;
        start = true;
    }

    //vertical
    printf("Checando Verticais");
    for (int j = 0; j < 15; j++) {
        for (int i = 0; i < 15; i++) {
            if (tabuleiro[i][j] == 0) {
                if (start) {
                    espacosA++;
                } else {
                    espacosD++;
                }
                lastSymbol = 0;
            }
            if (tabuleiro[i][j] == 1) {
                start = false;
                
                if (pontos2 > 0) {
                    soma2 = heuristicaPontos(espacosA,pontos2,espacosD);
                    espacosA = espacosD;
                    espacosD = 0;
                    pontos2 = 0;
                }
                pontos1++;
                if (lastSymbol == 0) {
                    espacosA += espacosD;
                    espacosD = 0;
                }
                lastSymbol = 1;
                
            } else if (tabuleiro[i][j] == 2) {
                start = false;
                
                if (pontos1 > 0) {
                    soma1 = heuristicaPontos(espacosA,pontos1,espacosD);
                    pontos1 = 0;
                    espacosA = espacosD;
                    espacosD = 0;
                }
                pontos2++;
                if (lastSymbol == 0) {
                    espacosA += espacosD;
                    espacosD = 0;
                }
                lastSymbol = 2;
            }
        }
        
        espacosD = 0;
        espacosA = 0;
        pontos1 = 0;
        pontos2 = 0;
        soma1 = 0;
        soma2 = 0;
        start = true;
    }

    //diagonal secundaria metade superior
    printf("Checando Diagonal Secundaria");
    for (int i = 0; i < 15 ; i++) {
        for (int j = 0; j < 15; j++) {
            
        }
        espacosD = 0;
        espacosA = 0;
        pontos1 = 0;
        pontos2 = 0;
        soma1 = 0;
        soma2 = 0;
        start = true;
    }
    
    //diagonal secundaria metade inferior
    for (int i = 0; i < 15 ; i++) {
        for (int j = 0; j < 15; j++) {
            
        }
        espacosD = 0;
        espacosA = 0;
        pontos1 = 0;
        pontos2 = 0;
        soma1 = 0;
        soma2 = 0;
        start = true;
    }

    int limit = 15;
    //diagonal principal metade superior
    printf("Checando Diagonal Principal");
    for (int i = 0; i <= 10; i++) {
        for (int j = 0, k = i;k < limit; j++,k++) {
            if (tabuleiro[i][j] == 0) {
                if (start) {
                    espacosA++;
                } else {
                    espacosD++;
                }
                lastSymbol = 0;
            }
            if (tabuleiro[i][j] == 1) {
                start = false;
                
                if (pontos2 > 0) {
                    soma2 = heuristicaPontos(espacosA,pontos2,espacosD);
                    espacosA = espacosD;
                    espacosD = 0;
                    pontos2 = 0;
                }
                pontos1++;
                if (lastSymbol == 0) {
                    espacosA += espacosD;
                    espacosD = 0;
                }
                lastSymbol = 1;
                
            } else if (tabuleiro[i][j] == 2) {
                start = false;
                
                if (pontos1 > 0) {
                    soma1 = heuristicaPontos(espacosA,pontos1,espacosD);
                    pontos1 = 0;
                    espacosA = espacosD;
                    espacosD = 0;
                }
                pontos2++;
                if (lastSymbol == 0) {
                    espacosA += espacosD;
                    espacosD = 0;
                }
                lastSymbol = 2;
            }
        }
        limit --;
        espacosD = 0;
        espacosA = 0;
        pontos1 = 0;
        pontos2 = 0;
        soma1 = 0;
        soma2 = 0;
        start = true;
    }
    //diagonal principal metade inferior
    limit = 14;
    for (int i = 1; i <= 10; i++) {
        for (int k = 0, j = i;k < limit; j++,k++) {
            if (tabuleiro[i][j] == 0) {
                if (start) {
                    espacosA++;
                } else {
                    espacosD++;
                }
                lastSymbol = 0;
            }
            if (tabuleiro[i][j] == 1) {
                start = false;
                
                if (pontos2 > 0) {
                    soma2 = heuristicaPontos(espacosA,pontos2,espacosD);
                    espacosA = espacosD;
                    espacosD = 0;
                    pontos2 = 0;
                }
                pontos1++;
                if (lastSymbol == 0) {
                    espacosA += espacosD;
                    espacosD = 0;
                }
                lastSymbol = 1;
                
            } else if (tabuleiro[i][j] == 2) {
                start = false;
                
                if (pontos1 > 0) {
                    soma1 = heuristicaPontos(espacosA,pontos1,espacosD);
                    pontos1 = 0;
                    espacosA = espacosD;
                    espacosD = 0;
                }
                pontos2++;
                if (lastSymbol == 0) {
                    espacosA += espacosD;
                    espacosD = 0;
                }
                lastSymbol = 2;
            }
        }
        limit --;
        espacosD = 0;
        espacosA = 0;
        pontos1 = 0;
        pontos2 = 0;
        soma1 = 0;
        soma2 = 0;
        start = true;
    }
    int result[] ={soma1, soma2};  
    printf("%i   %i \n", soma1, soma2);
}

int Pontuacao::heuristicaPontos(int espacosA, int pontos, int espacosD){
    //Aqui vou avaliar a situacao da ultima carreira de pedras e dar-lhes uma pontuacao
    //switchzao
    printf("Pontos: %i\n", pontos);
    printf("Espacos: %i\n", espacosA + espacosD);
    
    if(pontos == 5){
        printf("%i", WIN);
        return WIN;
    }
    else {
        return 0;
    }
}

Pontuacao::Pontuacao(const Pontuacao& orig) {
}

Pontuacao::~Pontuacao() {
}

#endif

