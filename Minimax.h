#ifndef MINIMAX_H
#define MINIMAX_H

#include "stdlib.h"
#include "Nodo.h"

class Minimax{

public:
	static Nodo* minimax(Nodo* raiz, int profundidade, bool minoumax, int alpha, int beta);

};
#endif

