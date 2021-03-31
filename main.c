#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "complexo_double.h"
#include "complexo_long_int.h"
#include "complexo_racional.h"

int main(){
    double imag;
    double real;
    Complexo_pt numero1, numero2;
    Complexo_pt resultado;

    numero1 = criaComplexo(1.5787, 2.7643);
    numero2 = criaComplexo(3, 4);

    resultado = converteDoubleParaLongInt(numero1);

    /*if(resultado == 1)
        printf("V\n");
    if(resultado == 0)
        printf("F\n");
    if(resultado == -1)
        printf("2 maior\n");*/
        
    printf("%f\n", *retornaReal(resultado));
    printf("%f\n", *retornaImaginario(resultado));

    //printf("%f\n", resultado);

    destroiComplexo(numero1);
    destroiComplexo(numero2);
    destroiComplexo(resultado);



    return 0;
}

//valgrind --leak-check=yes ./a.out