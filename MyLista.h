#ifndef LISTA_H
#define LISTA_H

#define SIZE 255

#include "stdio.h"
#include <iostream>


using namespace std;

template <typename T>
class MyLista{

private:
	T lista[SIZE];
	unsigned int size;

public:
	MyLista():size(0){
		for(int i = 0;i < SIZE; i++){
			lista[i] = NULL;
		}
	}

	void add(T nodo){
		unsigned int i = 0;
		while(lista[i] != NULL && i < SIZE){
			i++;
		}
		lista[i] = nodo;
		size++;
	}

	T getNodeByPos(int i = 0){
		if(empty()){
			return NULL;
		}
		if(i == -1){
			return lista[size-1];
		}
		if(lista[i] != NULL){
			return lista[i];
		} else {
			return NULL;
		}
	}

	T removeByPos(int i = 0){
		if(empty()){
			return NULL;
		}
		if(i == -1){
			return lista[size-1];
		}
		
		if(lista[i] != NULL){
			T* retorno = lista[i];
			lista[i] = NULL;
			size--;
			order();
			return lista[i];
		} else {
			return NULL;
		}
	}
		
	void order(){
		for(int i = 0; i < SIZE -1; i++){
			if(lista[i] = NULL){
				lista[i] = lista[i+1];
				lista[i+1] = NULL;
			}
		}
	}

	unsigned int getSize(){
		return size;
	}
	
	bool empty(){
		return size == 0;
	}

	int maxSize(){
		return SIZE;
	}











};
#endif
