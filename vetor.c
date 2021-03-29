/*#ifdef TIPADO_ 
#ifdef DESTE_TIPO_ double
#ifdef DESTE_FORMATO_ */
#include <stdio.h>
#include <stdlib.h> 
#include <math.h> 
#include "vetor.h"

typedef struct Vetor_st{
	int n;
    int N;
    int i;
    double *elementos;
}Vetor_t;

Vetor_pt criaVetor(int n, double *elementos){
    Vetor_pt vetor = (Vetor_t*) malloc(sizeof(Vetor_t));
    double *elementos = (double*) malloc(n * sizeof(double));
    vetor->n = n;
    vetor->N = 100;
    vetor->i = 0;
    for(int i = 0; i < n; i++){
       vetor->elementos[i] = elementos[i];
    }
    return vetor;
}
