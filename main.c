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
    int resultado;

    numero1 = criaComplexo(1000000000, 577350269);
    numero2 = criaComplexo(2, 2);

    resultado = comparaAngulosNumeros(numero1, numero2);

    if(resultado == 1)
        printf("1 maior\n");
    if(resultado == 0)
        printf("I\n");
    if(resultado == -1)
        printf("2 maior\n");

    //printf("%f\n", *retornaReal(resultado));
    //printf("%f\n", *retornaImaginario(resultado));

    destroiComplexo(numero1);
    destroiComplexo(numero2);
    //destroiComplexo(resultado);



    return 0;
}

//valgrind --leak-check=yes ./a.out