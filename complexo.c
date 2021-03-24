#include <stdio.h>
#include <stdlib.h> 
#include <math.h> 
#include "complexo.h"

typedef struct TIPADO_(Complexo_st) {
	DESTE_TIPO_ *real;
    DESTE_TIPO_ *imag;
} TIPADO_(Complexo_t);

TIPADO_(Complexo_pt) TIPADO_(criaComplexo) (DESTE_TIPO_ *real, DESTE_TIPO_ *imag){
    TIPADO_(Complexo_pt) numComplexo = (TIPADO_(Complexo_t*)) malloc(sizeof(TIPADO_(Complexo_t)));

    numComplexo->real = real;
    numComplexo->imag = imag;

    return numComplexo;
}

void TIPADO_(destroiComplexo) (TIPADO_(Complexo_pt) numComplexo){
    free(numComplexo->real);
    numComplexo->real = NULL;
    free(numComplexo->imag);
    numComplexo->imag = NULL;
    free(numComplexo);
    numComplexo = NULL;   
}

