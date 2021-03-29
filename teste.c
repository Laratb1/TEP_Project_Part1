#include <stdio.h>
#include <stdlib.h>
#include "Racionais.h"

int main(){
    Racional_pt numero1, numero2, resultado2;
    int resultado1;
    resultado2 = (Racional_t*) malloc(sizeof(Racional_pt));

    numero1 = criaNumRacional(9, 1000000);
    numero2 = criaNumRacional(1, 2);

    resultado1 = verificaRacionalConverteEmInteiro(numero1);

    //printf("%ld\n", retornaNum(resultado2));
    //printf("%ld\n", retornaDen(resultado2));

    printf("%d\n", resultado1);

    destroiNum(numero1);
    destroiNum(numero2);
    //destroiNum(resultado2);

    return 0;
}



/*int MDC(int a, int b);

int main(){
    int num;
    
    num = MDC(34020, 903820);

    printf("%d", num);

    return 0;
}

int MDC(int a, int b){
    if(b == 0)
        return a;
    else
        return MDC(b, a%b);   
}*/