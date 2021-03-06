/* 
 * File:   Pontuacao.h
 * Author: Abrams
 *
 * Created on 26 de Agosto de 2016, 11:24
 */

#ifndef PONTUACAO_H
#define	PONTUACAO_H

class Pontuacao {
public:
    Pontuacao();
    static int somarPontuacao(int tabuleiro[15][15]);
    Pontuacao(const Pontuacao& orig);
    virtual ~Pontuacao();
private:

    static int somarH(int tabuleiro[15][15]);
    static int somarV(int tabuleiro[15][15]);
    static int somarDP(int tabuleiro[15][15]);
    static int somarDS(int tabuleiro[15][15]);
    static int algoritmo(int tabuleiro[15][15]);
    static int heuristica(int espacosA, int pontos, int espacosD, int consec, int seq1[5], int seq2[5], int lastSymbol);
    static void printSeqs(int seq1[5], int seq2[5]);

    int espacosD;
    int espacosA;
    int pontos1;
    int pontos2;
    int soma1;
    int soma2;
    int lastSymbol;
};

#endif	/* PONTUACAO_H */

