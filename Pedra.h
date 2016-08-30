/* 
 * File:   Pedra.h
 * Author: Abrams
 *
 * Created on 30 de Agosto de 2016, 18:43
 */

#ifndef PEDRA_H
#define	PEDRA_H

class Pedra {
public:
    Pedra(int posicao[2], bool jogador);
    Pedra(const Pedra& orig);
    virtual ~Pedra();
private:
    int posicao1;
    int posicao2;
    bool jogador;
};

#endif	/* PEDRA_H */

