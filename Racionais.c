#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Racionais.h"

typedef struct Racional_st{
    long int num;
    long int den;
} Racional_t;

typedef struct Racional_st Racional_t;

Racional_pt criaNumRacional(long int numerador, long int denominador){
    Racional_pt numRacional = (Racional_t*) malloc(sizeof(Racional_t));
    if(numRacional == NULL){
        printf("Memória insuficiente!\n");
		exit(1);
    }
    numRacional->num = numerador;
    numRacional->den = denominador;

    return numRacional;
}

long int retornaDen(Racional_pt numero){
    return numero->den;
}

long int retornaNum(Racional_pt numero){
    return numero->num;
}

void destroiNum(Racional_pt numRacional){
    free(numRacional);
    numRacional = NULL;
}

Racional_pt copiaNumRacional(Racional_pt num1, Racional_pt num2){

}

int comparaNumeros(Racional_pt valor1, Racional_pt valor2){
    long double div1, div2;

    div1 = (valor1->num) / (valor1->den);
    div2 = (valor2->num) / (valor2->den);

    if(div1 == div2){
        return 0;
    }
    if(div1 < div2){
        return -1;
    }
    if(div1 > div2){
        return 1;
    }
}

int verificaEquivalente(Racional_pt valor1, Racional_pt valor2){
    long double div1, div2;

    div1 = (valor1->num) / (valor1->den);
    div2 = (valor2->num) / (valor2->den);

    if(div1 == div2)
        return 1;
    else
        return 0;
}

int verificaDenominadorZero(Racional_pt numRacional){
    if(numRacional->den == 0)
        return 1;
    else
        return 0;
}

int verificaNumeradorZero(Racional_pt numRacional){
    if(numRacional->num == 0)
        return 1;
    else
        return 0;
}
    
int verificaAmbosZero(Racional_pt numRacional){
    if(numRacional->num == 0 && numRacional->den == 0)
        return 1;
    else
        return 0;
}

double somaRacionais(Racional_pt valor1, Racional_pt valor2){
    double resultado;    
    resultado = (valor1->num / valor1->den) + (valor2->num / valor2->den);

    return resultado;
}

Racional_pt acumulaRacional(Racional_pt valor1, Racional_pt valor2){

    valor1->num = (valor1->num * valor2->den) + (valor1->den * valor2->num);
    valor1->den = (valor1->den * valor2->den);

    return valor1;
}