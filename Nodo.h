#ifndef NODO_H
#define NODO_H

#include "stdlib.h"
#include <list>
#include "TabuleiroVirtual.h"
#include "MyLista.h"

class Nodo{

private:
    Nodo* parent;
    MyLista<Nodo*> filhos;
    int value;
    int jogada[2];
	bool player1;

public:

 Nodo(int jogadas[2], Nodo* parente, bool player): value(0){
	filhos = MyLista<Nodo*>();
    parent = parente;
	jogada[0] = jogadas[0];
	jogada[1] = jogadas[1];
	player1 = player;

}


void setValue(int newValue){
	value = newValue;
}

void gerarFilhos(){
	TabuleiroVirtual* tabuleiro = TabuleiroVirtual::getInstance();
	for(int i = 0; i < 15; i++){
		for(int j = 0; j < 15; j++){
			if(tabuleiro->check(i,j)){
				addFilho(i,j);
			}
		}
	}
}

void addFilho(int jogadas[2]){
	Nodo* nodo = new Nodo(jogadas, this,!player1);
	filhos.add(nodo);
}

void addFilho(int i, int j){
	
	int jogadas[2] = {i,j};

	Nodo* nodo = new Nodo(jogadas, this,!player1);
	filhos.add(nodo);
}

int* getJogada(){
	return jogada;
}

int getPlayer(){
	if(player1){
		return 1;
	} else {
		return 2;
	}
}

int getValue(){
	return value;
}

int calcularHeuristica(){
	TabuleiroVirtual* tabuleiro = TabuleiroVirtual::getInstance();
	value = tabuleiro->heuristica();	
	return value;
}

Nodo* getParent(){
    return parent;
}

void setParent(Nodo* parent){
	parent = parent;
}

MyLista<Nodo*> getFilhos(){
	return filhos;
}

bool operator >= (Nodo* nodo){
	return(value >= nodo->getValue());
}

bool operator == (Nodo* nodo){
	return(jogada[0] == nodo->getJogada()[0] && jogada[1] == nodo->getJogada()[1]);
}
};
#endif
