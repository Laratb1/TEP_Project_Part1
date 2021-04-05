/*#ifdef TIPADO_ 
#ifdef DESTE_TIPO_ 
#ifdef DESTE_FORMATO_*/
#include <stdio.h>
#include <stdlib.h> 
#include <math.h> 
#include <string.h>
#include "complexo.h"

typedef struct Complexo_st{
	TIPO_ *real;
    TIPO_ *imag;
} Complexo_t;

Complexo_pt TIPADO_(criaComplexo) (TIPO_ numReal, TIPO_ numImag){
    Complexo_pt numComplexo = (Complexo_t*) malloc(sizeof(Complexo_t));
    if(numComplexo == NULL){
        printf("Memória insuficiente!\n");
		exit(1);
    }
    numComplexo->real = (TIPO_*) malloc(sizeof(TIPO_));
    numComplexo->imag = (TIPO_*) malloc(sizeof(TIPO_));
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

TIPO_ *retornaReal (Complexo_pt numComplexo){
    return numComplexo->real;
}

TIPO_ *retornaImaginario (Complexo_pt numComplexo){
    return numComplexo->imag;
}

/*void imprimeComplexo(Complexo_pt numComplexo){
    char formato[10] = " ";
	strcat(formato, FORMATO_);
	strcat(formato, " ");
    printf("formato + formatoI\n", *retornaReal(numComplexo), *retornaImaginario(numComplexo));
}*/

void atribuiComplexo(Complexo_pt numComplexo1, Complexo_pt numComplexo2){
    numComplexo1->real = numComplexo2->real;
    numComplexo1->imag = numComplexo2->imag;
}

Complexo_pt copiaComplexo(Complexo_pt numero){
    Complexo_pt numComplexo;
    numComplexo = criaComplexo(0, 0);
    if(numComplexo == NULL){
        printf("Memória insuficiente!\n");
		exit(1);
    }
    numComplexo->real = numero->real;
    numComplexo->imag = numero->imag;

    return numComplexo;
}

//VERIFICAR SE PODE ISSO 
Complexo_pt converteDoubleParaLongInt(Complexo_pt numComplexo){
    *numComplexo->real = round(*numComplexo->real);
    *numComplexo->imag = round(*numComplexo->imag);

    return numComplexo;
}

//CERTEZA QUE ISSO NAO VAI DAR CERTO 
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

long double retornaMagnitude(Complexo_pt numComplexo){
    double modulo, real, imaginario;

    real = *numComplexo->real;
    imaginario = *numComplexo->imag;

    modulo = sqrt(pow(real, 2) + pow(imaginario, 2));

    return fabs(modulo);
}

long double retornaFase(Complexo_pt numComplexo){
    long double angulo;
    
    if ((*numComplexo->imag < 0 && *numComplexo->real < 0) || (*numComplexo->imag > 0 && *numComplexo->real < 0)){
      angulo = angulo + 3.14159265359;
    }  

    return angulo;
}

int verificaModuloZero(Complexo_pt numComplexo){    
  
    //isso aqui que e para fazer com o eps?
    if(retornaMagnitude(numComplexo) <= eps)
        return 1;
    else 
        return 0;
}

int verificaApenasReal(Complexo_pt numComplexo){
    if(*numComplexo->imag <= eps)
        return 1;
    else 
        return 0;
}

int verificaApenasImaginario(Complexo_pt numComplexo){
    if(*numComplexo->real <= eps)
        return 1;
    else 
        return 0;
}

int comparaModuloNumeros(Complexo_pt numComplexo1, Complexo_pt numComplexo2){
    long double modulo1, modulo2;
    modulo1 = retornaMagnitude(numComplexo1);
    modulo2 = retornaMagnitude(numComplexo2);

//verificar se essa logica esta correta
    if(fabs(modulo1-modulo2) > eps){
        if(modulo1 < modulo2)
            return -1;
        if(modulo1 > modulo2)
            return 1;
    }
    else
        return 0;
}

int comparaAngulosNumeros(Complexo_pt numComplexo1, Complexo_pt numComplexo2){
    long double angulo1, angulo2;

    angulo1 = retornaFase(numComplexo1);
    angulo2 = retornaFase(numComplexo2); 

    if(fabs(angulo1-angulo2) > eps){
        if(angulo1 < angulo2)
            return -1;
        if(angulo1 > angulo2)
            return 1;
    }
    else
        return 0;
}


void atribuiNovoValorReal(Complexo_pt numComplexo, TIPO_ novoValor){
    *numComplexo->real = novoValor;
}

void atribuiNovoValorImaginario(Complexo_pt numComplexo, TIPO_ novoValor){
    *numComplexo->imag = novoValor;
}

void atribuiNovoValorModulo(TIPO_ numComplexo, TIPO_ novoModulo){
    *numComplexo->real = novoModulocos(retornaFase(numComplexo));
    *numComplexo->imag = novoModulosin(retornaFase(numComplexo));
}

void atribuiNovoValorAngulo(TIPO_ numComplexo, TIPO_ novoAngulo){
    *numComplexo->real = retornaMagnitude(numComplexo) * cos(novoAngulo);
    *numComplexo->imag = retornaMagnitude(numComplexo) * sin(novoAngulo);
}

// qual o tipo de retorno 
TIPO_ retornaConjugado(Complexo_pt numComplexo){
    return *numComplexo->imag *= -1;
}

Complexo_pt somaComplexo(Complexo_pt numComplexo1, Complexo_pt numComplexo2){
    Complexo_pt resultado;
    resultado = criaComplexo(0, 0);

    if(resultado == NULL){
        printf("Memória insuficiente!\n");
		exit(1);
    }
    resultado->real = (TIPO_*) malloc(sizeof(TIPO_));
    resultado->imag = (TIPO_*) malloc(sizeof(TIPO_));
    if(resultado->real == NULL || resultado->imag == NULL){
        printf("Memória insuficiente!\n");
		exit(1);
    }
    *resultado->real = *numComplexo1->real + *numComplexo2->real;
    *resultado->imag = *numComplexo1->imag + *numComplexo2->imag;;

    return resultado;
}

Complexo_pt subtraiComplexo(Complexo_pt numComplexo1, Complexo_pt numComplexo2){
    Complexo_pt resultado;
    resultado = criaComplexo(0, 0);

    if(resultado == NULL){
        printf("Memória insuficiente!\n");
		exit(1);
    }
    resultado->real = (TIPO_*) malloc(sizeof(TIPO_));
    resultado->imag = (TIPO_*) malloc(sizeof(TIPO_));
    if(resultado->real == NULL || resultado->imag == NULL){
        printf("Memória insuficiente!\n");
		exit(1);
    }
    *resultado->real = *numComplexo1->real - *numComplexo2->real;
    *resultado->imag = *numComplexo1->imag - *numComplexo2->imag;;

    return resultado;
}

Complexo_pt divideComplexo(Complexo_pt numComplexo1, Complexo_pt numComplexo2){
    Complexo_pt resultado;
    resultado = criaComplexo(0, 0);
    TIPO_ denominador;
    
    if(resultado == NULL){
        printf("Memória insuficiente!\n");
		exit(1);
    }
    resultado->real = (TIPO_*) malloc(sizeof(TIPO_));
    resultado->imag = (TIPO_*) malloc(sizeof(TIPO_));
    if(resultado->real == NULL || resultado->imag == NULL){
        printf("Memória insuficiente!\n");
		exit(1);
    }
    
    *resultado->real = (*numComplexo1->real * *numComplexo2->real) + (*numComplexo1->imag * *numComplexo2->imag * (-1));
    *resultado->imag = (*numComplexo1->real * *numComplexo2->imag) + (*numComplexo1->imag * *numComplexo2->real);

    denominador = (*numComplexo2->real * *numComplexo2->real) + (*numComplexo2->imag * *numComplexo2->imag);
    if(denominador == 0){
        printf("Nao e possivel realizar a divisao\n");
        exit(1);
    }
    *resultado->real = *resultado->real / denominador;
    *resultado->imag = *resultado->imag / denominador;

    return resultado;
}

Complexo_pt multiplicaComplexo(Complexo_pt numComplexo1, Complexo_pt numComplexo2){
    Complexo_pt resultado;
    resultado = criaComplexo(0, 0);

    if(resultado == NULL){
        printf("Memória insuficiente!\n");
		exit(1);
    }
    resultado->real = (TIPO_*) malloc(sizeof(TIPO_));
    resultado->imag = (TIPO_*) malloc(sizeof(TIPO_));
    if(resultado->real == NULL || resultado->imag == NULL){
        printf("Memória insuficiente!\n");
		exit(1);
    }
    *resultado->real = (*numComplexo1->real * *numComplexo2->real) + (*numComplexo1->imag * *numComplexo2->imag * (-1));
    *resultado->imag = (*numComplexo1->real * *numComplexo2->imag) + (*numComplexo1->imag * *numComplexo2->real);

    return resultado;
}

void acumulaSomando(Complexo_pt numComplexo1, Complexo_pt numComplexo2){
    *numComplexo1->real += *numComplexo1->real + *numComplexo2->real;
    *numComplexo1->imag += *numComplexo1->imag + *numComplexo2->imag;
}

void acumulaMultiplicando(Complexo_pt numComplexo1, Complexo_pt numComplexo2){
    *numComplexo1->real *= (*numComplexo1->real * *numComplexo2->real) + (*numComplexo1->imag * *numComplexo2->imag * (-1));
    *numComplexo1->imag *= (*numComplexo1->real * *numComplexo2->imag) + (*numComplexo1->imag * *numComplexo2->real);
}

/*Complexo_pt operacaoComplexo(Complexo_pt numComplexo1, Complexo_pt numComplexo2, char *operacao){
    operacao = (char*) malloc(3 * sizeof(char));

    switch(*operacao){
        case '+':
            return somaComplexo(numComplexo1, numComplexo2);
            break;
        case '-':
            return subtraiComplexo(numComplexo1, numComplexo2);
            break;
        case '*':
            return multiplicaComplexo(numComplexo1, numComplexo2);
            break;
        case '/':
            return divideComplexo(numComplexo1, numComplexo2);
            break;
        case '+=':
            return acumulaSomando(numComplexo1, numComplexo2);
            break;
        case '*=':
            return acumulaMultiplicando(numComplexo1, numComplexo2);
            break;
    }
}*/
//#endif
//#endif
//#endif