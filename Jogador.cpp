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
    jogadorAI = false;
    tela = new Tela();
	ultimaJogada[0] = 7;
    ultimaJogada[1] = 7;
    estadoDeJogo = JOGANDO;
    leitura();
}

void Jogador::leitura() {
    while (estadoDeJogo == JOGANDO) {
        tela->printTabul(campo);
		if(!jogadorAI){
        	int choice[2];
        	scanf("%i%i", &choice[0], &choice[1]);
        	if (this->escrita(choice)) {
            	jogadorAI = true;
        	}
		} else {
			if(this->escrita()){
				jogadorAI = false;
			}
		}
    }

    printf("O vencedor é o jogador %i", jogadorAI);
}

bool Jogador::escrita(int choice[]) {
    //system("clear");
	printf("Campo:");

    if (campo[choice[0]][choice[1]] == 0) {
        	campo[choice[0]][choice[1]] = 2;
			ultimaJogada[0] = choice[0];
			ultimaJogada[1] = choice[1];
        //jogadas.push_back(new Pedra(choice, jogadorAI));		
        //int pontos = Pontuacao::somarPontuacao(campo);
        //printf("Pontos: %i", pontos);
        return true;
    }
    return false;
}

bool Jogador::escrita(){
	TabuleiroVirtual* tab = TabuleiroVirtual::getInstance();
	tab->update(campo);
	Nodo* nodo = new Nodo(ultimaJogada, NULL, !jogadorAI);
	int heuristica = Minimax::minimax(nodo,2);
	printf("Heuristica: %i", heuristica);
	int choice[2];
	choice[0] = nodo->getFilhos().findByValue(heuristica)->getJogada()[0];
	choice[1] = nodo->getFilhos().findByValue(heuristica)->getJogada()[1];
	campo[choice[0]][choice[1]] = 1;
	return true;
}

Jogador::Jogador(const Jogador& orig) {
}

Jogador::~Jogador() {
}

#endif
