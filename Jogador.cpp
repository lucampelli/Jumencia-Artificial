/* 
 * File:   Jogador.cpp
 * Author: Abrams
 * 
 * Created on 26 de Agosto de 2016, 10:44
 */


#ifndef JOGADOR_CPP
#define JOGADOR_CPP

#include "Jogador.h"
#include "stdlib.h"
#include "Nodo.h"
#include "Minimax.h"

Jogador::Jogador() {
    jogador1 = true;
    tela = new Tela();
    estadoDeJogo = JOGANDO;
    leitura();
}

void Jogador::leitura() {
    while (estadoDeJogo == JOGANDO) {
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

    printf("O vencedor é o jogador %i", jogador1);
}

bool Jogador::escrita(int choice[]) {
    //system("clear");
	printf("Campo:");
    if (campo[choice[0]][choice[1]] == 0) {
        if (jogador1) {
            campo[choice[0]][choice[1]] = 1;
        } else {
            campo[choice[0]][choice[1]] = 2;
        }
        //jogadas.push_back(new Pedra(choice, jogador1));
		Nodo* nodo = new Nodo(choice, NULL, jogador1);
		int heuristica = Minimax::minimax(nodo,2);
		printf("Heuristica: %i", heuristica);
        //int pontos = Pontuacao::somarPontuacao(campo);
        //printf("Pontos: %i", pontos);
        return true;
    }
    return false;
}

Jogador::Jogador(const Jogador& orig) {
}

Jogador::~Jogador() {
}

#endif
