/* 
 * File:   Jogador.h
 * Author: Abrams
 *
 * Created on 26 de Agosto de 2016, 10:44
 */

#ifndef JOGADOR_H
#define	JOGADOR_H

#include <iostream>
#include <list>
#include "stdio.h"
#include "Tela.h"
#include "Pedra.h"
#include "Pontuacao.h"

typedef enum {JOGANDO, TERMINADO} estado;

class Jogador {
public:
    Jogador();
    Jogador(const Jogador& orig);
    virtual ~Jogador();
    void leitura();
    bool escrita(int choice[]);
	static Jogador* getInstance(){
		static Jogador* _jogador;
		if(_jogador == NULL){
			_jogador = new Jogador();
		}
		return _jogador;
	}
	int* getCampo(){ return &campo[0][0];}
	
    
private:
    //Matriz que guarda estado atual do campo: 
    int campo[15][15];
    //lista de jogadas 1:
    std::list<Pedra*> jogadas;
    //Variável que define quem é a vez:    
    bool jogador1;
    //Entidade da interface gráfica
    Tela* tela;
    estado estadoDeJogo;
};

#endif	/* JOGADOR_H */

