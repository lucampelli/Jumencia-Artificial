#ifndef NODO_H
#define NODO_H

#include "stdlib.h"
#include <list>
#include "Pontuacao.h"

class Nodo{

public:
	static int tabuleiroVirtual[15][15];

private:
    Nodo* parent;
    std::list<Nodo*> filhos;
    int value;
    int jogada[2];
	int player;

public:

 Nodo(int jogada[2], Nodo* parent, int player): value(0){

    parent = parent;
	jogada[0] = jogada[0];
	jogada[1] = jogada[1];
	player = player;
	play(jogada, player);

}

void setValue(int value){
	value = value;
}

void addFilho(int jogada[2]){
	if(player == 1){
		filhos.push_back(new Nodo(jogada, this,2));
	}
	if(player == 2){
		filhos.push_back(new Nodo(jogada, this,1));
	}
}

int* getJogada(){
	return jogada;
}

int getValue(){
	return value;
}

int calcularHeuristica(){
	return Pontuacao::somarPontuacao(tabuleiroVirtual);
}

Nodo* getParent(){
    return parent;
}

void setParent(Nodo* parent){
	parent = parent;
}

std::list<Nodo*> getFilhos(){
	return filhos;
}

Nodo* operator >= (Nodo* nodo){
	if(value >= nodo->getValue()){
		return this;
	} else {
		return nodo;
	}
}

void play(int jogada[2], int jogador){
	if(jogada[0] < 0 || jogada[1] < 0){
		return;
	}
	if(tabuleiroVirtual[jogada[0]][jogada[1]] == 0){
		tabuleiroVirtual[jogada[0]][jogada[1]] = jogador;
	}
	
}

};
#endif
