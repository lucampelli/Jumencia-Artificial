
#ifndef MINIMAX_CPP
#define MINIMAX_CPP

#include "Minimax.h"
#include "Pontuacao.h"
#include "stdlib.h"
#include "MyLista.h"

int Minimax::minimax(Nodo* raiz, int prof, bool isMax, int a, int b){

	TabuleiroVirtual* tabuleiro = TabuleiroVirtual::getInstance();
	tabuleiro->insert(raiz->getJogada(),raiz->getPlayer());

	if(prof == 0 /*&&raiz->isFinal()*/){
		int pontuacao = raiz->calcularHeuristica();
		tabuleiro->remove(raiz->getJogada());
		return pontuacao;
	}

	raiz->gerarFilhos();

	if(isMax){
		int v = MINF;
		for(unsigned int i = 0; i < raiz->getFilhos().getSize(); i++){
			Nodo* it = raiz->getFilhos().getNodeByPos(i);
			v = max(v,minimax(it, prof -1, false, a, b));
			a = max(a,v);
			if(b <= a){
				break;
			}
		}
		raiz->setValue(v);
		tabuleiro->remove(raiz->getJogada());
		return v;
	} else {
		int v = INF;
		for(int i = 0; i < raiz->getFilhos().getSize(); i++){
			Nodo* it = raiz->getFilhos().getNodeByPos(i);
			v = min(v,minimax(it, prof -1, true, a, b));
			b = min(b,v);
			if(b <= a){
				break;
			}
		}
		raiz->setValue(v);
		tabuleiro->remove(raiz->getJogada());
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
