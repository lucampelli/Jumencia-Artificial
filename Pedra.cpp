/* 
 * File:   Pedra.cpp
 * Author: Abrams
 * 
 * Created on 30 de Agosto de 2016, 18:43
 */

#include "Pedra.h"

Pedra::Pedra(int posicao[], bool jogador) {
    this->posicao[0] = posicao[0];
    this->posicao[1] = posicao[1];
    this->jogador = jogador;
}

Pedra::Pedra(const Pedra& orig) {
}

Pedra::~Pedra() {
}

