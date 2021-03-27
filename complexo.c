/*#ifdef TIPADO_ 
#ifdef DESTE_TIPO_ double
#ifdef DESTE_FORMATO_ */
#include <stdio.h>
#include <stdlib.h> 
#include <math.h> 
#include "complexo.h"

typedef struct Complexo_st{
	double *real;
    double *imag;
}Complexo_t;

Complexo_pt criaComplexo (double numReal, double numImag){
    Complexo_pt numComplexo = (Complexo_t*) malloc(sizeof(Complexo_t));
    if(numComplexo == NULL){
        printf("Memória insuficiente!\n");
		exit(1);
    }
    numComplexo->real = (double*) malloc(sizeof(double));
    numComplexo->imag = (double*) malloc(sizeof(double));
    if(numComplexo->real == NULL || numComplexo->imag == NULL){
        printf("Memória insuficiente!\n");
		exit(1);
    }
    *numComplexo->real = numReal;
    *numComplexo->imag = numImag;
    
    return numComplexo;
}

void destroiComplexo (Complexo_pt numComplexo){
    free(numComplexo->real);
    numComplexo->real = NULL;
    free(numComplexo->imag);
    numComplexo->imag = NULL;
    free(numComplexo);
    numComplexo = NULL;   
}

double *retornaReal (Complexo_pt numComplexo){
    return numComplexo->real;
}

double *retornaImaginario (Complexo_pt numComplexo){
    return numComplexo->imag;
}

Complexo_pt atribuiComplexo(Complexo_pt numComplexo1, Complexo_pt numComplexo2){
    numComplexo1->real
}

//#endif
//#endif
//#endif