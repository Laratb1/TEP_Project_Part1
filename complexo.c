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
    numComplexo1->real = numComplexo2->real;
    numComplexo1->imag = numComplexo2->imag;

    return numComplexo1;
}

Complexo_pt copiaComplexo(Complexo_pt numero){
    Complexo_pt numComplexo = (Complexo_t*) malloc(sizeof(Complexo_t));

    numComplexo->real = numero->real;
    numComplexo->imag = numero->imag;

    return numComplexo;
}

Complexo_pt converteDoubleParaLongInt(Complexo_pt numComplexo){

}

Complexo_pt converteLongIntParaDouble(Complexo_pt numComplexo){

}

Complexo_pt converteDoubleParaRacional(Complexo_pt numComplexo){

}

Complexo_pt converteRacionalParaDouble(Complexo_pt numComplexo){

}

Complexo_pt converteRacionalParaLongInt(Complexo_pt numComplexo){

}

Complexo_pt converteLongIntPataRacional(Complexo_pt numComplexo){

}

double calculaModulo(Complexo_pt numComplexo){
    double modulo, real, imaginario;

    real = *numComplexo->real;
    imaginario = *numComplexo->imag;

    modulo = sqrt(pow(real, 2) + pow(imaginario, 2));

    return modulo;
}

int verificaModuloZero(Complexo_pt numComplexo){    
  
    //isso aqui que e para fazer com o eps?
    if(calculaModulo(numComplexo) <= eps)
        return 1;
    else 
        return 0;
}

int verificaApenasReal(Complexo_pt numComplexo){
    double imaginario;

    imaginario = *numComplexo->imag;

    if(imaginario <= eps)
        return 1;
    else 
        return 0;
}

int verificaApenasImaginario(Complexo_pt numComplexo){
    double real;

    real = *numComplexo->imag;

    if(real <= eps)
        return 1;
    else 
        return 0;
}

int comparaNumeros(Complexo_pt numComplexo1, Complexo_pt numComplexo2){
    double modulo1, modulo2;
    modulo1 = calculaModulo(numComplexo1);
    modulo2 = calculaModulo(numComplexo2);

//verificar se essa logica esta correta
    if(modulo1 == modulo2 && fabs(modulo1-modulo2) <= eps)
        return 0;
    if(modulo1 < modulo2 && fabs(modulo1-modulo2) <= eps)
        return -1;
    if(modulo1 > modulo2 && fabs(modulo1-modulo2) <= eps)
        return 1;
}





//#endif
//#endif
//#endif