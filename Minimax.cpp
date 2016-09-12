#define INF 10000000
#define MINF -10000000


#ifndef MINIMAX_CPP
#define MINIMAX_CPP

#include "Minimax.h"
#include "Pontuacao.h"

int Minimax::minimax(Nodo* raiz, int prof, bool isMax = true, int a = -INF, int b = INF){

	//gerar filhos dos nodos	

	if(prof == 0 /*&&raiz->isFinal()*/){
		
		return raiz->calcularHeuristica();
	}

	if(isMax){
		int v = MINF;
		for(std::list<Nodo*>::iterator it = raiz->getFilhos().begin(); it!=raiz->getFilhos().end(); it++){
			v = max(v,minimax(*it, prof -1, false, a, b));
			a = max(a,v);
			if(b <= a){
				break;
			}
		}
		return v;
	} else {
		int v = INF;
		for(std::list<Nodo*>::iterator it = raiz->getFilhos().begin(); it!=raiz->getFilhos().end(); it++){
			v = min(v,minimax(*it, prof -1, true, a, b));
			b = min(b,v);
			if(b <= a){
				break;
			}
		}
		return v;
	}
}




int Minimax::max(int i, int j){
	if(i>=j){
		return i;
	}
	return j;
}

int Minimax::min(int i, int j){
	if(i>=j){
		return j;
	}
	return i;
}

#endif
