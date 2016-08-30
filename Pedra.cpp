/* 
 * File:   Pedra.cpp
 * Author: Abrams
 * 
 * Created on 30 de Agosto de 2016, 18:43
 */

#include "Pedra.h"

Pedra::Pedra(int posicao[], bool jogador) {
    this->posicao1 = posicao1;
    this->posicao2 = posicao2;
    this->jogador = jogador;
}

Pedra::Pedra(const Pedra& orig) {
}

Pedra::~Pedra() {
}

