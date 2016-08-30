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
    static int heuristicaPontos(int espacosA, int pontos, int espacosD);
    Pontuacao(const Pontuacao& orig);
    virtual ~Pontuacao();
private:

};

#endif	/* PONTUACAO_H */

