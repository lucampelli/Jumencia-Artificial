/* 
 * File:   Pontuacao.cpp
 * Author: Abrams
 * 
 * Created on 26 de Agosto de 2016, 11:24
 */
#ifndef PONTUACAO_CPP
#define PONTUACAO_CPP
#include "stdio.h"
#include "string.h"
#include "Pontuacao.h"
#include "Jogador.h"


int p1;

int p2;

Pontuacao::Pontuacao() {
}

int Pontuacao::somarH(int tabuleiro[15][15]) {

    
    p1 = 0;
    p2 = 0;

    int seq1[] = {0, 0, 0, 0, 0}; //{umas, duplas,triplas,quadras,quintas}
    int seq2[] = {0, 0, 0, 0, 0};
    int consec = 0;

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
                if (lastSymbol != 0) {
                    if (lastSymbol == 1) {
                        if (consec > 0) {
                            seq1[consec - 1]++;
                        }
                    }
                    if (lastSymbol == 2) {
                        if (consec > 0) {
                            seq2[consec - 1]++;
                        }
                    }
                    consec = 0;
                }
                lastSymbol = 0;
            }
            if (tabuleiro[i][j] == 1) {
                pontos1++;
                if (pontos2 > 0) {
                    soma2 += heuristica(espacosA, pontos2, espacosD, consec, seq1, seq2, 2);
                    pontos2 = 0;
                    espacosA = espacosD;
                    espacosD = 0;
                }
                if (lastSymbol == 0) {
                    espacosA += espacosD;
                    espacosD = 0;
                }
                if (lastSymbol != 1) {
                    if (lastSymbol == 2) {
                        if (consec > 0) {
                            seq2[consec - 1]++;
                        }
                    }
                    consec = 0;
                }
                consec++;
                lastSymbol = 1;
            }
            if (tabuleiro[i][j] == 2) {
                pontos2++;
                if (pontos1 > 0) {
                    soma1 += heuristica(espacosA, pontos1, espacosD, consec, seq1, seq2, 1);
                    pontos1 = 0;
                    espacosA = espacosD;
                    espacosD = 0;
                }
                if (lastSymbol == 0) {
                    espacosA += espacosD;
                    espacosD = 0;
                }
                if (lastSymbol != 2) {
                    if (lastSymbol == 1) {
                        if (consec > 0) {
                            seq1[consec - 1]++;
                        }
                    }
                    consec = 0;
                }
                consec++;
                lastSymbol = 2;
            }
        }
        if (pontos1 > 0) {
            soma1 += heuristica(espacosA, pontos1, espacosD, consec, seq1, seq2, 1);
        }
        if (pontos2 > 0) {
            soma2 += heuristica(espacosA, pontos2, espacosD, consec, seq1, seq2, 2);
        }
        espacosD = 0;
        espacosA = 0;
        pontos1 = 0;
        pontos2 = 0;
        soma1 = 0;
        soma2 = 0;
        lastSymbol = 0;
        consec = 0;
    }

    return p1 - p2;
}

int Pontuacao::somarV(int tabuleiro[15][15]) {

    
    p1 = 0;
    p2 = 0;
    
    int seq1[] = {0, 0, 0, 0, 0}; //{duplas,triplas,quadras,quintas}
    int seq2[] = {0, 0, 0, 0, 0};
    int consec = 0;

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
                if (lastSymbol != 0) {
                    if (lastSymbol == 1) {
                        if (consec > 0) {
                            seq1[consec - 1]++;
                        }
                    }
                    if (lastSymbol == 2) {
                        if (consec > 0) {
                            seq2[consec - 1]++;
                        }
                    }
                    consec = 0;
                }
                lastSymbol = 0;
            }
            if (tabuleiro[i][j] == 1) {
                pontos1++;
                if (pontos2 > 0) {
                    soma2 += heuristica(espacosA, pontos2, espacosD, consec, seq1, seq2, 2);
                    pontos2 = 0;
                    espacosA = espacosD;
                    espacosD = 0;
                }
                if (lastSymbol == 0) {
                    espacosA += espacosD;
                    espacosD = 0;
                }
                if (lastSymbol != 1) {
                    if (lastSymbol == 2) {
                        if (consec > 0) {
                            seq2[consec - 1]++;
                        }
                    }
                    consec = 0;
                }
                consec++;
                lastSymbol = 1;
            }
            if (tabuleiro[i][j] == 2) {
                pontos2++;
                if (pontos1 > 0) {
                    soma1 += heuristica(espacosA, pontos1, espacosD, consec, seq1, seq2, 1);
                    pontos1 = 0;
                    espacosA = espacosD;
                    espacosD = 0;
                }
                if (lastSymbol == 0) {
                    espacosA += espacosD;
                    espacosD = 0;
                }
                if (lastSymbol != 2) {
                    if (lastSymbol == 1) {
                        if (consec > 0) {
                            seq1[consec - 1]++;
                        }
                    }
                    consec = 0;
                }
                consec++;
                lastSymbol = 2;
            }
        }
        if (pontos1 > 0) {
            soma1 += heuristica(espacosA, pontos1, espacosD, consec, seq1, seq2, 1);
        }
        if (pontos2 > 0) {
            soma2 += heuristica(espacosA, pontos2, espacosD, consec, seq1, seq2, 2);
        }
        espacosD = 0;
        espacosA = 0;
        pontos1 = 0;
        pontos2 = 0;
        soma1 = 0;
        soma2 = 0;
        lastSymbol = 0;
        consec = 0;
    }

    return p1 - p2;
}

int Pontuacao::somarDP(int tabuleiro[15][15]) {

    p1 = 0;
    p2 = 0;
    
    int seq1[] = {0, 0, 0, 0, 0}; //{umas, duplas,triplas,quadras,quintas}
    int seq2[] = {0, 0, 0, 0, 0};
    int consec = 0;

    int espacosD = 0;
    int espacosA = 0;
    int pontos1 = 0;
    int pontos2 = 0;
    int soma1 = 0;
    int soma2 = 0;
    int lastSymbol = 0;
    //Parte superior da diagonal:
    for (int i = 0, j = 0, r = 0; r < 11; r++, j = r, i = 0) {//r<11 devido a otimização de não precisar ver os cantos que não possam mais formar vitória.
        for (; i < (15 - r); i++, j++) {
            if (tabuleiro[i][j] == 0) {
                if (pontos1 == 0 && pontos2 == 0) {
                    espacosA++;
                } else {
                    espacosD++;
                }
                if (lastSymbol != 0) {
                    if (lastSymbol == 1) {
                        if (consec > 0) {
                            seq1[consec - 1]++;
                        }
                    }
                    if (lastSymbol == 2) {
                        if (consec > 0) {
                            seq2[consec - 1]++;
                        }
                    }
                    consec = 0;
                }
                lastSymbol = 0;
            }
            if (tabuleiro[i][j] == 1) {
                pontos1++;
                if (pontos2 > 0) {
                    soma2 += heuristica(espacosA, pontos2, espacosD, consec, seq1, seq2, 2);
                    pontos2 = 0;
                    espacosA = espacosD;
                    espacosD = 0;
                }
                if (lastSymbol == 0) {
                    espacosA += espacosD;
                    espacosD = 0;
                }
                if (lastSymbol != 1) {
                    if (lastSymbol == 2) {
                        if (consec > 0) {
                            seq2[consec - 1]++;
                        }
                    }
                    consec = 0;
                }
                consec++;
                lastSymbol = 1;
            }
            if (tabuleiro[i][j] == 2) {
                pontos2++;
                if (pontos1 > 0) {
                    soma1 += heuristica(espacosA, pontos1, espacosD, consec, seq1, seq2, 1);
                    pontos1 = 0;
                    espacosA = espacosD;
                    espacosD = 0;
                }
                if (lastSymbol == 0) {
                    espacosA += espacosD;
                    espacosD = 0;
                }
                if (lastSymbol != 2) {
                    if (lastSymbol == 1) {
                        if (consec > 0) {
                            seq1[consec - 1]++;
                        }
                    }
                    consec = 0;
                }
                consec++;
                lastSymbol = 2;
            }
        }
        if (pontos1 > 0) {
            soma1 += heuristica(espacosA, pontos1, espacosD, consec, seq1, seq2, 1);
        }
        if (pontos2 > 0) {
            soma2 += heuristica(espacosA, pontos2, espacosD, consec, seq1, seq2, 2);
        }
        espacosD = 0;
        espacosA = 0;
        pontos1 = 0;
        pontos2 = 0;
        soma1 = 0;
        soma2 = 0;
        lastSymbol = 0;
        consec = 0;
    }
    //Parte inferior da diagonal:
    for (int i = 1, j = 0, r = 1; r < 11; r++, i = r, j = 0) {//r<11 devido a otimização de não precisar ver os cantos que não possam mais formar vitória.
        for (; i <= (15 - r); j++, i++) {
            if (tabuleiro[i][j] == 0) {
                if (pontos1 == 0 && pontos2 == 0) {
                    espacosA++;
                } else {
                    espacosD++;
                }
                if (lastSymbol != 0) {
                    if (lastSymbol == 1) {
                        if (consec > 0) {
                            seq1[consec - 1]++;
                        }
                    }
                    if (lastSymbol == 2) {
                        if (consec > 0) {
                            seq2[consec - 1]++;
                        }
                    }
                    consec = 0;
                }
                lastSymbol = 0;
            }
            if (tabuleiro[i][j] == 1) {
                pontos1++;
                if (pontos2 > 0) {
                    soma2 += heuristica(espacosA, pontos2, espacosD, consec, seq1, seq2, 2);
                    pontos2 = 0;
                    espacosA = espacosD;
                    espacosD = 0;
                }
                if (lastSymbol == 0) {
                    espacosA += espacosD;
                    espacosD = 0;
                }
                if (lastSymbol != 1) {
                    if (lastSymbol == 2) {
                        if (consec > 0) {
                            seq2[consec - 1]++;
                        }
                    }
                    consec = 0;
                }
                consec++;
                lastSymbol = 1;
            }
            if (tabuleiro[i][j] == 2) {
                pontos2++;
                if (pontos1 > 0) {
                    soma1 += heuristica(espacosA, pontos1, espacosD, consec, seq1, seq2, 1);
                    pontos1 = 0;
                    espacosA = espacosD;
                    espacosD = 0;
                }
                if (lastSymbol == 0) {
                    espacosA += espacosD;
                    espacosD = 0;
                }
                if (lastSymbol != 2) {
                    if (lastSymbol == 1) {
                        if (consec > 0) {
                            seq1[consec - 1]++;
                        }
                    }
                    consec = 0;
                }
                consec++;
                lastSymbol = 2;
            }
        }
        if (pontos1 > 0) {
            soma1 += heuristica(espacosA, pontos1, espacosD, consec, seq1, seq2, 1);
        }
        if (pontos2 > 0) {
            soma2 += heuristica(espacosA, pontos2, espacosD, consec, seq1, seq2, 2);
        }
        espacosD = 0;
        espacosA = 0;
        pontos1 = 0;
        pontos2 = 0;
        soma1 = 0;
        soma2 = 0;
        lastSymbol = 0;
        consec = 0;
    }

    return p1 - p2;
}

int Pontuacao::somarDS(int tabuleiro[15][15]) {

    p1 = 0;
    p2 = 0;
    
    int seq1[] = {0, 0, 0, 0, 0}; //{duplas,triplas,quadras,quintas}
    int seq2[] = {0, 0, 0, 0, 0};
    int consec = 0;

    int espacosD = 0;
    int espacosA = 0;
    int pontos1 = 0;
    int pontos2 = 0;
    int soma1 = 0;
    int soma2 = 0;
    int lastSymbol = 0;
    //Parte superior da diagonal:
    for (int i = 0, j = 14, r = 0; r < 11; r++, j = 14 - r, i = 0) {//r<11 devido a otimização de não precisar ver os cantos que não possam mais formar vitória.
        for (; j >= 0; i++, j--) {
            if (tabuleiro[i][j] == 0) {
                if (pontos1 == 0 && pontos2 == 0) {
                    espacosA++;
                } else {
                    espacosD++;
                }
                if (lastSymbol != 0) {
                    if (lastSymbol == 1) {
                        if (consec > 0) {
                            seq1[consec - 1]++;
                        }
                    }
                    if (lastSymbol == 2) {
                        if (consec > 0) {
                            seq2[consec - 1]++;
                        }
                    }
                    consec = 0;
                }
                lastSymbol = 0;
            }
            if (tabuleiro[i][j] == 1) {
                pontos1++;
                if (pontos2 > 0) {
                    soma2 += heuristica(espacosA, pontos2, espacosD, consec, seq1, seq2, 2);
                    pontos2 = 0;
                    espacosA = espacosD;
                    espacosD = 0;
                }
                if (lastSymbol == 0) {
                    espacosA += espacosD;
                    espacosD = 0;
                }
                if (lastSymbol != 1) {
                    if (lastSymbol == 2) {
                        if (consec > 0) {
                            seq2[consec - 1]++;
                        }
                    }
                    consec = 0;
                }
                consec++;
                lastSymbol = 1;
            }
            if (tabuleiro[i][j] == 2) {
                pontos2++;
                if (pontos1 > 0) {
                    soma1 += heuristica(espacosA, pontos1, espacosD, consec, seq1, seq2, 1);
                    pontos1 = 0;
                    espacosA = espacosD;
                    espacosD = 0;
                }
                if (lastSymbol == 0) {
                    espacosA += espacosD;
                    espacosD = 0;
                }
                if (lastSymbol != 2) {
                    if (lastSymbol == 1) {
                        if (consec > 0) {
                            seq1[consec - 1]++;
                        }
                    }
                    consec = 0;
                }
                consec++;
                lastSymbol = 2;
            }
        }
        if (pontos1 > 0) {
            soma1 += heuristica(espacosA, pontos1, espacosD, consec, seq1, seq2, 1);
        }
        if (pontos2 > 0) {
            soma2 += heuristica(espacosA, pontos2, espacosD, consec, seq1, seq2, 2);
        }
        espacosD = 0;
        espacosA = 0;
        pontos1 = 0;
        pontos2 = 0;
        soma1 = 0;
        soma2 = 0;
        lastSymbol = 0;
        consec = 0;
    }
    //Parte inferior da diagonal:
    for (int i = 1, j = 14, r = 1; r < 11; r++, i = r, j = 14) {//r<11 devido a otimização de não precisar ver os cantos que não possam mais formar vitória.
        for (; i < 15; i++, j--) {
            if (tabuleiro[i][j] == 0) {
                if (pontos1 == 0 && pontos2 == 0) {
                    espacosA++;
                } else {
                    espacosD++;
                }
                if (lastSymbol != 0) {
                    if (lastSymbol == 1) {
                        if (consec > 0) {
                            seq1[consec - 1]++;
                        }
                    }
                    if (lastSymbol == 2) {
                        if (consec > 0) {
                            seq2[consec - 1]++;
                        }
                    }
                    consec = 0;
                }
                lastSymbol = 0;
            }
            if (tabuleiro[i][j] == 1) {
                pontos1++;
                if (pontos2 > 0) {
                    soma2 += heuristica(espacosA, pontos2, espacosD, consec, seq1, seq2, 2);
                    pontos2 = 0;
                    espacosA = espacosD;
                    espacosD = 0;
                }
                if (lastSymbol == 0) {
                    espacosA += espacosD;
                    espacosD = 0;
                }
                if (lastSymbol != 1) {
                    if (lastSymbol == 2) {
                        if (consec > 0) {
                            seq2[consec - 1]++;
                        }
                    }
                    consec = 0;
                }
                consec++;
                lastSymbol = 1;
            }
            if (tabuleiro[i][j] == 2) {
                pontos2++;
                if (pontos1 > 0) {
                    soma1 += heuristica(espacosA, pontos1, espacosD, consec, seq1, seq2, 1);
                    pontos1 = 0;
                    espacosA = espacosD;
                    espacosD = 0;
                }
                if (lastSymbol == 0) {
                    espacosA += espacosD;
                    espacosD = 0;
                }
                if (lastSymbol != 2) {
                    if (lastSymbol == 1) {
                        if (consec > 0) {
                            seq1[consec - 1]++;
                        }
                    }
                    consec = 0;
                }
                consec++;
                lastSymbol = 2;
            }
        }
        if (pontos1 > 0) {
            soma1 += heuristica(espacosA, pontos1, espacosD, consec, seq1, seq2, 1);
        }
        if (pontos2 > 0) {
            soma2 += heuristica(espacosA, pontos2, espacosD, consec, seq1, seq2, 2);
        }
        espacosD = 0;
        espacosA = 0;
        pontos1 = 0;
        pontos2 = 0;
        soma1 = 0;
        soma2 = 0;
        lastSymbol = 0;
        consec = 0;
    }

    return p1 - p2;
}

int Pontuacao::somarPontuacao(int tabuleiro[15][15]) {

    return somarH(tabuleiro) + somarV(tabuleiro) + somarDP(tabuleiro) + somarDS(tabuleiro);
}

int Pontuacao::heuristica(int espacosA, int pontos, int espacosD, int consec, int seq1[5], int seq2[5], int jogador) {


    if (pontos + espacosD + espacosA < 5){
        if (jogador == 1) {
            if (consec > 0) {
                seq1[consec - 1]--;
            }
        }
        if (jogador == 2) {
            if (consec > 0) {
                seq2[consec - 1]--;
            }
        }
    }
    if (jogador == 1) {
        p1 = 0;
        p1 += seq1 [0] * 20;
        p1 += seq1 [1] * 40;
        p1 += seq1 [2] * 100;
        p1 += seq1 [3] * 500;
		p1 += seq1 [4] * 1500000;
        p1 += (espacosD + espacosA) * 2;
    } else {
        p2 = 0;
        p2 += seq2 [0] * 20;
        p2 += seq2 [1] * 40;
        p2 += seq2 [2] * 100;
        p2 += seq2 [3] * 500;
		p2 += seq2 [4] * 1500000;
        p2 += (espacosD + espacosA) * 2;
    }
    return p1 - p2;

}

Pontuacao::Pontuacao(const Pontuacao& orig) {
}

Pontuacao::~Pontuacao() {
}

#endif

