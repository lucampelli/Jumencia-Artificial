#define INF 100000
#define MINF -100000

#ifndef MINIMAX_H
#define MINIMAX_H

#include "stdlib.h"
#include "Nodo.h"

class Minimax{

public:
	Minimax();

public:
	static int minimax(Nodo* raiz, int profundidade, bool max = true, int alpha = MINF, int beta = INF);
	static int min(int i, int j);
	static int max(int i, int j);

};
#endif

