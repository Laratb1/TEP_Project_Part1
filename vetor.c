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

Vetor_pt criaVetor(int n, int i, double *elementos){
    Vetor_pt vetor = (Vetor_t*) malloc(sizeof(Vetor_t));
    vetor->elementos = (double*) malloc(n * sizeof(double));
    
    vetor->n = n;
    vetor->N = 100;
    vetor->i = i;

    realocaEspaco(vetor);
    
    for(vetor->i = 0; vetor->i < vetor->n-1; vetor->i++){
       *(vetor->elementos+vetor->i) = elementos[i];
    }

    return vetor;
}

void realocaEspaco(Vetor_pt vetor){
    if(vetor->n >= vetor->N){
        vetor->elementos = (double*) realloc(vetor->elementos, 2 * vetor->n * sizeof(double));
    }
    if(vetor->n <= (vetor->N / 4)){
        vetor->elementos = (double*) realloc(vetor->elementos, 0.5 * vetor->n * sizeof(double));
    }
}

Vetor_pt destroiVetor(Vetor_pt vetor){
    for(vetor->i = 0; vetor->i < vetor->n-1; vetor->i++){
        free(vetor->elementos+vetor->i);
        vetor->elementos+vetor->i == NULL;
    }
    free(vetor);
    vetor == NULL;
}

double retornaElementos(Vetor_pt vetor, int indice){
    return vetor->elementos[indice];
}

Vetor_pt atribuiVetor(Vetor_pt vetor1, Vetor_pt vetor2){
    for(vetor1->i = 0; vetor1->i < vetor1->n-1; vetor1->i++){
        *(vetor1->elementos+vetor1->i) = *(vetor2->elementos+vetor2->i);
    }
   return vetor1;
}