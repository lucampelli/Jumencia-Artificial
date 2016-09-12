#ifndef MINIMAX_CPP
#define MINIMAX_CPP

#include "Minimax.h"

Nodo* Minimax::minimax(Nodo* raiz, int prof, bool minoumax, int a, int b){
	Nodo* scoreNode = NULL;
	

	if(prof == 0 /*&&raiz->isFinal()*/){
		scoreNode = raiz;
	}

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
