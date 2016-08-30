/* 
 * File:   Jogador.cpp
 * Author: Abrams
 * 
 * Created on 26 de Agosto de 2016, 10:44
 */


#ifndef JOGADOR_CPP
#define JOGADOR_CPP

#include "Jogador.h"


Jogador::Jogador() {
    jogador1 = true;
    tela = new Tela();
    leitura();
}

void Jogador::leitura() {
    while (1) {
        tela->printTabul(campo);
        int choice[2];
        scanf("%i%i", &choice[0], &choice[1]);
        if (this->escrita(choice)) {
            if (jogador1) {
                jogador1 = false;
            } else {
                jogador1 = true;
            }
        }
    }
}

bool Jogador::escrita(int choice[]) {
    if (campo[choice[0]][choice[1]] == 0) {
        if (jogador1) {
            jogadas1.push_back(new Pedra(choice, jogador1));
            campo[choice[0]][choice[1]] = 1;
        } else {
            jogadas2.push_back(new Pedra(choice, jogador1));
            campo[choice[0]][choice[1]] = 2;
        }
        Pontuacao::somarPontuacao(campo);
        return true;
    }
    return false;
}

Jogador::Jogador(const Jogador& orig) {
}

Jogador::~Jogador() {
}

#endif
