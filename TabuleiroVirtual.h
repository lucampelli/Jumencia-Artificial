#ifndef TABULEIROVIRTUAL_H
#define TABULEIROVIRTUAL_H

#include "Pontuacao.h"
#include "Jogador.h"

class TabuleiroVirtual{

private:
	int tabuleiro[15][15];

public:
	static TabuleiroVirtual* getInstance(){
		static TabuleiroVirtual* _Tabul;
		if(_Tabul == NULL){
			_Tabul = new TabuleiroVirtual();
		}
		return _Tabul;
	}

	int* getTabul(){
		return &tabuleiro[0][0];
	}

	bool check(int jogada[2]){
		if(tabuleiro[jogada[0]][jogada[1]] == 0){
			return true;
		}
		return false;
	}

	bool check(int i, int j){
		if(tabuleiro[i][j] == 0){
			return true;
		}
		return false;
	}

	void insert(int jogada[2], int player){
		tabuleiro[jogada[0]][jogada[1]] = player;
	}

	void remove(int jogada[2]){
		tabuleiro[jogada[0]][jogada[1]] = 0;
	}

	int heuristica(){
		return Pontuacao::somarPontuacao(tabuleiro);
	}

	void update(){
		Jogador* jogador = Jogador::getInstance();
		for(int i = 0; i < 15; i++){
			for(int j = 0; j < 15; j++){
				tabuleiro[i][j] = jogador->getPlaceInCampo(i,j);
			}
		}
	}
	
	void update(int tabuleiroNovo[15][15]){
		for(int i = 0; i < 15; i++){
			for(int j = 0; j < 15; j++){
				tabuleiro[i][j] = tabuleiroNovo[i][j];
			}
		}
	}
};
#endif
