/*#ifdef TIPADO_*/ 
#ifdef DESTE_TIPO_ double
#ifdef DESTE_FORMATO_ 
#include <stdio.h>
#include <stdlib.h> 
#include <math.h> 
#include "complexo.h"

typedef struct Complexo_st{
	DESTE_TIPO_ *real;
    DESTE_TIPO_ *imag;
}Complexo_t;

Complexo_pt *criaComplexo (DESTE_TIPO_ *real, DESTE_TIPO_ *imag){
    Complexo_pt numComplexo = (Complexo_t*) malloc(sizeof(Complexo_t));
    if(numComplexo == NULL){
        printf("Memória insuficiente!\n");
		exit(1);
    }
    real = (DESTE_TIPO_*) malloc(sizeof(DESTE_TIPO_));
    imag = (DESTE_TIPO_*) malloc(sizeof(DESTE_TIPO_));
    if(real == NULL || imag == NULL){
        printf("Memória insuficiente!\n");
		exit(1);
    }
    numComplexo->real = real;
    numComplexo->imag = imag;

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

DESTE_TIPO_ *retornaReal (Complexo_pt numComplexo){
    return numComplexo->real;
}

DESTE_TIPO_ *retornaImaginario (Complexo_pt numComplexo){
    return numComplexo->imag;
}

#endif
#endif
//#endif