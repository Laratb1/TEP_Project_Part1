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
    
    for(int c = 0; c < vetor->n; c++){
       *(vetor->elementos+c) = elementos[c];
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
    free(vetor->elementos);
    vetor->elementos == NULL;
    free(vetor);
    vetor == NULL;
}

double retornaElementos(Vetor_pt vetor, int indice){
    return vetor->elementos[indice];
}

Vetor_pt atribuiVetor(Vetor_pt vetor1, Vetor_pt vetor2){
    for(int c = 0; c < vetor1->n; c++){
        *(vetor1->elementos+c) = *(vetor2->elementos+c);
    }
   return vetor1;
}

Vetor_pt criaCopiaVetor( Vetor_pt vetor){

}

int retornaNumeroAtualElementos(Vetor_pt vetor){
    return vetor->n;
}

int retornaNumeroMaxElementos(Vetor_pt vetor){

} //milla

int retornaIndice(Vetor_pt vetor){
    return vetor->i;
}

double retornaPrimeiroElemento(Vetor_pt vetor){

} //milla

double retornaProximoElemento(Vetor_pt vetor, int indice){
    vetor->i = indice + 1;
    return vetor->elementos[indice+1];
}

double retornaElementoAnterior(Vetor_pt vetor, int indice){

} //milla

double retornaUltimoElemento(Vetor_pt vetor){
    vetor->i = vetor->n-1;
    return vetor->elementos[vetor->n-1];
}

double retornaElementoDePosicaoI(Vetor_pt vetor, int indice){

} //mila

Vetor_pt atribuirValorNaIesimaPosicao(Vetor_pt vetor, int indice, double valor){
    vetor->elementos[indice] = valor;
    vetor->i = indice;

    return vetor;
}

Vetor_pt incrementaValor(Vetor_pt vetor, double valor){

} //milla

Vetor_pt eliminaElementoDePosicaoI(Vetor_pt vetor, int indice){
    for(int c = indice; c < vetor->n; c++){
        vetor->elementos[c] = vetor->elementos[c+1];
    }
    vetor->n = vetor->n-1;
    //estou na duvida se faco esse realloc 
    vetor->elementos = (double*) realloc(vetor->elementos, vetor->n * sizeof(double));
    return vetor;
}

Vetor_pt eliminaTodosElementos(Vetor_pt vetor){

} //milla

double valorDeMaiorModulo(Vetor_pt vetor){
    double maior;
    maior = fabs(vetor->elementos[0]);
    vetor->i = 0;
    for(int c = 0; c < vetor->n; c++){
        if(fabs(vetor->elementos[c]) > maior){
            maior = vetor->elementos[c];
            vetor->i = c;
        }
    }
    return maior;
}