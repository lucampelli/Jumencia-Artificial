#define INF 10000000
#define MINF -10000000


#ifndef MINIMAX_CPP
#define MINIMAX_CPP

#include "Minimax.h"
#include "Pontuacao.h"

int Minimax::minimax(Nodo* raiz, int prof, bool isMax = true, int a = -INF, int b = INF){

	
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

/*

function minimax(node, depth, maximizingPlayer)
     if depth = 0 or node is a terminal node
         return the heuristic value of node

     if maximizingPlayer
         bestValue := −∞
         for each child of node
             v := minimax(child, depth − 1, FALSE)
             bestValue := max(bestValue, v)
         return bestValue

     else    (* minimizing player *)
         bestValue := +∞
         for each child of node
             v := minimax(child, depth − 1, TRUE)
             bestValue := min(bestValue, v)
         return bestValue



public int MiniMax(int depth, bool needMax, int alpha, int beta, out Board childWithMax)
{
    childWithMax = null;
    System.Diagnostics.Debug.Assert(m_TurnForPlayerX == needMax);
    if (depth == 0 || IsTerminalNode())
    {
        RecursiveScore = m_Score;
        return m_Score;
    }
    foreach (Board cur in GetChildren())
    {
        Board dummy;
        int score = cur.MiniMax(depth - 1, !needMax, alpha, beta, out dummy);
        if (!needMax)
        {
            if (beta > score)
            {
                beta = score;
                childWithMax = cur;
                if (alpha >= beta)
                {
                    break;
                }
            }
        }
        else
        {
            if (alpha < score)
            {
                alpha = score;
                childWithMax = cur;
                if (alpha >= beta)
                {
                    break;
                }
            }
        }
    }
    RecursiveScore = needMax ? alpha : beta;
    return RecursiveScore;


*/




#endif
