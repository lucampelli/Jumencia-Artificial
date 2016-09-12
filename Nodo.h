#ifndef NODO_H
#define NODO_H

#include "stdlib.h"
#include <list>

class Nodo{

private:
    Nodo* parent;
    std::list<Nodo*> filhos;
    int value;
    int jogada[2];

public:

 Nodo(int jogada[2], Nodo* parent): value(0){

    parent = parent;
	jogada[0] = jogada[0];
	jogada[1] = jogada[1];

}

void setValue(int value){
	value = value;
}

void addFilho(int jogada[2]){
	filhos.push_back(new Nodo(jogada, this));
}

int* getJogada(){
	return jogada;
}

int getValue(){
	return value;
}

Nodo* getParent(){
    return parent;
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

};
#endif
