#ifndef MINIMAX_H
#define MINIMAX_H

#include "stdlib.h"
#include "Nodo.h"

class Minimax{

public:
	Minimax();

public:
	static int minimax(Nodo* raiz, int profundidade, bool max, int alpha, int beta);
	static int min(int i, int j);
	static int max(int i, int j);

};
#endif

