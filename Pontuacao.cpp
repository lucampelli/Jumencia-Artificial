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

#define WIN 100000
#define LOSE -100000

///std::list<Pedra*>::iterator it;
//for( it = lista.begin(); it != lista.end(); it++){}

Pontuacao::Pontuacao() {
}

int Pontuacao::somarH(int tabuleiro[15][15]) {
    printf("Somando as horizontais\n");

    int seq1[] = {0,0,0,0}; //{duplas,triplas,quadras,quintas}
    int seq2[] = {0,0,0,0};
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
		if(lastSymbol != 0){
		    if(lastSymbol == 1){
			if(consec > 1){
			    seq1[consec -2]++;
			}
		    }
		    if(lastSymbol == 2){
			if(consec > 1){
			    seq2[consec -2]++;
			}
		    }
		    consec = 0;
		}
                lastSymbol = 0;
            }
            if (tabuleiro[i][j] == 1) {
                pontos1++;
                if (pontos2 > 0) {
                    soma2 += heuristica(espacosA, pontos2, espacosD, consec, seq1, seq2, lastSymbol);
                    pontos2 = 0;
                    espacosA = espacosD;
                    espacosD = 0;
                }
                if (lastSymbol == 0) {
                    espacosA += espacosD;
                    espacosD = 0;
                }
		if(lastSymbol != 1){
		    if(lastSymbol == 2){
			if(consec > 1){
			    seq2[consec -2]++;
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
                    soma1 += heuristica(espacosA, pontos1, espacosD, consec, seq1, seq2, lastSymbol);
                    pontos1 = 0;
                    espacosA = espacosD;
                    espacosD = 0;
                }
                if (lastSymbol == 0) {
                    espacosA += espacosD;
                    espacosD = 0;
                }
		if(lastSymbol != 2){
		    if(lastSymbol == 1){
			if(consec > 1){
			    seq1[consec -2]++;
			}
		    }
		    consec = 0;
		}
		consec++;
                lastSymbol = 2;
            }
        }
        if (pontos1 > 0) {
            soma1 += heuristica(espacosA, pontos1, espacosD, consec, seq1, seq2, lastSymbol);
        }
        if (pontos2 > 0) {
            soma1 += heuristica(espacosA, pontos2, espacosD, consec, seq1, seq2, lastSymbol);
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
    printSeqs(seq1,seq2);
}

int Pontuacao::somarV(int tabuleiro[15][15]) {
    printf("Somando as verticais\n");

    int seq1[] = {0,0,0,0}; //{duplas,triplas,quadras,quintas}
    int seq2[] = {0,0,0,0};
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
		if(lastSymbol != 0){
		    if(lastSymbol == 1){
			if(consec > 1){
			    seq1[consec -2]++;
			}
		    }
		    if(lastSymbol == 2){
			if(consec > 1){
			    seq2[consec -2]++;
			}
		    }
		    consec = 0;
		}
                lastSymbol = 0;
            }
            if (tabuleiro[i][j] == 1) {
                pontos1++;
                if (pontos2 > 0) {
                    soma2 += heuristica(espacosA, pontos2, espacosD, consec, seq1, seq2, lastSymbol);
                    pontos2 = 0;
                    espacosA = espacosD;
                    espacosD = 0;
                }
                if (lastSymbol == 0) {
                    espacosA += espacosD;
                    espacosD = 0;
                }
		if(lastSymbol != 1){
		    if(lastSymbol == 2){
			if(consec > 1){
			    seq2[consec -2]++;
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
                    soma1 += heuristica(espacosA, pontos1, espacosD, consec, seq1, seq2, lastSymbol);
                    pontos1 = 0;
                    espacosA = espacosD;
                    espacosD = 0;
                }
                if (lastSymbol == 0) {
                    espacosA += espacosD;
                    espacosD = 0;
                }
		if(lastSymbol != 2){
		    if(lastSymbol == 1){
			if(consec > 1){
			    seq1[consec -2]++;
			}
		    }
		    consec = 0;
		}
		consec++;
                lastSymbol = 2;
            }
        }
        if (pontos1 > 0) {
            soma1 += heuristica(espacosA, pontos1, espacosD, consec, seq1, seq2, lastSymbol);
        }
        if (pontos2 > 0) {
            soma1 += heuristica(espacosA, pontos2, espacosD, consec, seq1, seq2, lastSymbol);
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
    printSeqs(seq1,seq2);
}

int Pontuacao::somarDP(int tabuleiro[15][15]) {
    printf("Somando a diagonal principal\n");

    int seq1[] = {0,0,0,0}; //{duplas,triplas,quadras,quintas}
    int seq2[] = {0,0,0,0};
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
		if(lastSymbol != 0){
		    if(lastSymbol == 1){
			if(consec > 1){
			    seq1[consec -2]++;
			}
		    }
		    if(lastSymbol == 2){
			if(consec > 1){
			    seq2[consec -2]++;
			}
		    }
		    consec = 0;
		}
                lastSymbol = 0;
            }
            if (tabuleiro[i][j] == 1) {
                pontos1++;
                if (pontos2 > 0) {
                    soma2 += heuristica(espacosA, pontos2, espacosD, consec, seq1, seq2, lastSymbol);
                    pontos2 = 0;
                    espacosA = espacosD;
                    espacosD = 0;
                }
                if (lastSymbol == 0) {
                    espacosA += espacosD;
                    espacosD = 0;
                }
		if(lastSymbol != 1){
		    if(lastSymbol == 2){
			if(consec > 1){
			    seq2[consec -2]++;
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
                    soma1 += heuristica(espacosA, pontos1, espacosD, consec, seq1, seq2, lastSymbol);
                    pontos1 = 0;
                    espacosA = espacosD;
                    espacosD = 0;
                }
                if (lastSymbol == 0) {
                    espacosA += espacosD;
                    espacosD = 0;
                }
		if(lastSymbol != 2){
		    if(lastSymbol == 1){
			if(consec > 1){
			    seq1[consec -2]++;
			}
		    }
		    consec = 0;
		}
		consec++;
                lastSymbol = 2;
            }
        }
        if (pontos1 > 0) {
            soma1 += heuristica(espacosA, pontos1, espacosD, consec, seq1, seq2, lastSymbol);
        }
        if (pontos2 > 0) {
            soma1 += heuristica(espacosA, pontos2, espacosD, consec, seq1, seq2, lastSymbol);
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
		if(lastSymbol != 0){
		    if(lastSymbol == 1){
			if(consec > 1){
			    seq1[consec -2]++;
			}
		    }
		    if(lastSymbol == 2){
			if(consec > 1){
			    seq2[consec -2]++;
			}
		    }
		    consec = 0;
		}
                lastSymbol = 0;
            }
            if (tabuleiro[i][j] == 1) {
                pontos1++;
                if (pontos2 > 0) {
                    soma2 += heuristica(espacosA, pontos2, espacosD, consec, seq1, seq2, lastSymbol);
                    pontos2 = 0;
                    espacosA = espacosD;
                    espacosD = 0;
                }
                if (lastSymbol == 0) {
                    espacosA += espacosD;
                    espacosD = 0;
                }
		if(lastSymbol != 1){
		    if(lastSymbol == 2){
			if(consec > 1){
			    seq2[consec -2]++;
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
                    soma1 += heuristica(espacosA, pontos1, espacosD, consec, seq1, seq2, lastSymbol);
                    pontos1 = 0;
                    espacosA = espacosD;
                    espacosD = 0;
                }
                if (lastSymbol == 0) {
                    espacosA += espacosD;
                    espacosD = 0;
                }
		if(lastSymbol != 2){
		    if(lastSymbol == 1){
			if(consec > 1){
			    seq1[consec -2]++;
			}
		    }
		    consec = 0;
		}
		consec++;
                lastSymbol = 2;
            }
        }
        if (pontos1 > 0) {
            soma1 += heuristica(espacosA, pontos1, espacosD, consec, seq1, seq2, lastSymbol);
        }
        if (pontos2 > 0) {
            soma1 += heuristica(espacosA, pontos2, espacosD, consec, seq1, seq2, lastSymbol);
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
    printSeqs(seq1,seq2);
}

int Pontuacao::somarDS(int tabuleiro[15][15]) {
    printf("Somando a diagonal secundaria\n");

    int seq1[] = {0,0,0,0}; //{duplas,triplas,quadras,quintas}
    int seq2[] = {0,0,0,0};
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
		if(lastSymbol != 0){
		    if(lastSymbol == 1){
			if(consec > 1){
			    seq1[consec -2]++;
			}
		    }
		    if(lastSymbol == 2){
			if(consec > 1){
			    seq2[consec -2]++;
			}
		    }
		    consec = 0;
		}
                lastSymbol = 0;
            }
            if (tabuleiro[i][j] == 1) {
                pontos1++;
                if (pontos2 > 0) {
                    soma2 += heuristica(espacosA, pontos2, espacosD, consec, seq1, seq2, lastSymbol);
                    pontos2 = 0;
                    espacosA = espacosD;
                    espacosD = 0;
                }
                if (lastSymbol == 0) {
                    espacosA += espacosD;
                    espacosD = 0;
                }
		if(lastSymbol != 1){
		    if(lastSymbol == 2){
			if(consec > 1){
			    seq2[consec -2]++;
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
                    soma1 += heuristica(espacosA, pontos1, espacosD, consec, seq1, seq2, lastSymbol);
                    pontos1 = 0;
                    espacosA = espacosD;
                    espacosD = 0;
                }
                if (lastSymbol == 0) {
                    espacosA += espacosD;
                    espacosD = 0;
                }
		if(lastSymbol != 2){
		    if(lastSymbol == 1){
			if(consec > 1){
			    seq1[consec -2]++;
			}
		    }
		    consec = 0;
		}
		consec++;
                lastSymbol = 2;
            }
        }
        if (pontos1 > 0) {
            soma1 += heuristica(espacosA, pontos1, espacosD, consec, seq1, seq2, lastSymbol);
        }
        if (pontos2 > 0) {
            soma1 += heuristica(espacosA, pontos2, espacosD, consec, seq1, seq2, lastSymbol);
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
		if(lastSymbol != 0){
		    if(lastSymbol == 1){
			if(consec > 1){
			    seq1[consec -2]++;
			}
		    }
		    if(lastSymbol == 2){
			if(consec > 1){
			    seq2[consec -2]++;
			}
		    }
		    consec = 0;
		}
                lastSymbol = 0;
            }
            if (tabuleiro[i][j] == 1) {
                pontos1++;
                if (pontos2 > 0) {
                    soma2 += heuristica(espacosA, pontos2, espacosD, consec, seq1, seq2, lastSymbol);
                    pontos2 = 0;
                    espacosA = espacosD;
                    espacosD = 0;
                }
                if (lastSymbol == 0) {
                    espacosA += espacosD;
                    espacosD = 0;
                }
		if(lastSymbol != 1){
		    if(lastSymbol == 2){
			if(consec > 1){
			    seq2[consec -2]++;
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
                    soma1 += heuristica(espacosA, pontos1, espacosD, consec, seq1, seq2, lastSymbol);
                    pontos1 = 0;
                    espacosA = espacosD;
                    espacosD = 0;
                }
                if (lastSymbol == 0) {
                    espacosA += espacosD;
                    espacosD = 0;
                }
		if(lastSymbol != 2){
		    if(lastSymbol == 1){
			if(consec > 1){
			    seq1[consec -2]++;
			}
		    }
		    consec = 0;
		}
		consec++;
                lastSymbol = 2;
            }
        }
        if (pontos1 > 0) {
            soma1 += heuristica(espacosA, pontos1, espacosD, consec, seq1, seq2, lastSymbol);
        }
        if (pontos2 > 0) {
            soma1 += heuristica(espacosA, pontos2, espacosD, consec, seq1, seq2, lastSymbol);
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
    printSeqs(seq1,seq2);
}

int Pontuacao::algoritmo(int tabuleiro[15][15]){

}

int Pontuacao::somarPontuacao(int tabuleiro[15][15]) {

    return somarH(tabuleiro) + somarV(tabuleiro) + somarDP(tabuleiro) + somarDS(tabuleiro);
}


int Pontuacao::heuristica(int espacosA, int pontos, int espacosD, int consec, int seq1[4], int seq2[4], int lastSymbol) {
    //Aqui vou avaliar a situacao da ultima carreira de pedras e dar-lhes uma pontuacao
    //switchzao
    //printf("Pontos: %i\n", pontos);
    //printf("Espacos: %i\n", espacosA + espacosD);
    //printf("Consecutivos: %i\n", consec);

    if(pontos + espacosD + espacosA >= 5){
	if(consec == 5){
	    printf("Win");
	}
    } else {
	if(lastSymbol == 1){
	    if(consec > 1){
		seq1[consec -2]--;
	    }
	}
	if(lastSymbol == 2){
	    if(consec > 1){
		seq2[consec -2]--;
	    }
	}
    }
    return 0;
}

void Pontuacao::printSeqs( int seq1[4], int seq2[4]){
    printf("Duplas: %i, Triplas: %i, Quadras: %i, Quintas: %i Player1\n",seq1[0],seq1[1],seq1[2],seq1[3]);
    printf("Duplas: %i, Triplas: %i, Quadras: %i, Quintas: %i Player2\n",seq2[0],seq2[1],seq2[2],seq2[3]);
}


Pontuacao::Pontuacao(const Pontuacao& orig) {
}

Pontuacao::~Pontuacao() {
}

#endif

