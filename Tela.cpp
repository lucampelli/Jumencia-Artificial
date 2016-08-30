/* 
 * File:   Tela.cpp
 * Author: Abrams
 * 
 * Created on 26 de Agosto de 2016, 10:24
 */

#ifndef TELA_CPP
#define TELA_CPP

#include "stdio.h"
//#include "stdlib.h"
#include "Tela.h"

Tela::Tela() {
}

Tela::~Tela(){}

void Tela::printTabul(int tabul[15][15]) {
    //system("clrscr");
    for (int i = 0; i < 15; i++) {
        printf("-");
    }

    for (int i = 0; i < 16; i++) {
        if (i < 11 && i > 0) {
            printf("\n %i |", i - 1);
        } else {
            printf("\n %i|", i - 1);
        }
        for (int j = 0; j < 15; j++) {
            if (i == 0) {
                if (j < 10 && j > -1) {
                    printf(" %i |", j);
                } else {
                    printf(" %i|", j);
                }
            } else {
                printf(" %i |", tabul[i - 1][j]);
            }
        }
        printf("\n");
    }
}

#endif


