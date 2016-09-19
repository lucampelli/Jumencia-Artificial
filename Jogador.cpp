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
	AI = false;
    tela = new Tela();
	ultimaJogada[0] = 7;
    ultimaJogada[1] = 7;
    estadoDeJogo = JOGANDO;
    leitura();
}

void Jogador::leitura() {

	printf("Escolha o modo de JOGO: 1 para pvp, 2 para pvAI\n");	
	int escolha;
	scanf("%i",&escolha);
	if(escolha == 2){
		AI = true;
		printf("Escolha quem começa, 1 para o jogador, e 2 para a AI\n");
		scanf("%i",&escolha);
		if(escolha == 2){
			jogadorAI = true;
		}
	}

    while (estadoDeJogo == JOGANDO) {
        tela->printTabul(campo);
		if(!jogadorAI){
        	int choice[2];
        	scanf("%i%i", &choice[0], &choice[1]);
        	if (this->escrita(choice)) {
            	jogadorAI = true;
        	}
		} else {
			if(AI){
				if(this->escrita()){
					jogadorAI = false;
				}
			} else {
				int choice[2];
        		scanf("%i%i", &choice[0], &choice[1]);
        		if (this->escrita(choice)) {
            		jogadorAI = false;
        		}
			}
		}
		
		int result = Pontuacao::somarPontuacao(campo);

		printf("%i", result);
		printf("%i", estadoDeJogo);
		if(result >= 1000000 || result <= -1000000){
			estadoDeJogo = TERMINADO;
		}

    }

    printf("\nO vencedor é o jogador %i\n", (int)jogadorAI +1);
}

bool Jogador::escrita(int choice[]) {
    //system("clear");
	printf("Campo:");

    if (campo[choice[0]][choice[1]] == 0) {
			if(jogadorAI){
        		campo[choice[0]][choice[1]] = 1;
			} else {
				campo[choice[0]][choice[1]] = 2;
			}
			ultimaJogada[0] = choice[0];
			ultimaJogada[1] = choice[1];

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
