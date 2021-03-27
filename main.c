#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "complexo_double.h"
#include "complexo_long_int.h"
#include "complexo_racional.h"

int main(){
    double imag;
    double real;
    Complexo_pt numero1, numero2, resultado;

    numero1 = criaComplexo(2, 3);
    numero2 = criaComplexo(5, 8);

    resultado = converteDoubleParaLongInt(numero1);

    printf("%f\n", *retornaReal(numero1));
    printf("%f\n", *retornaImaginario(numero1));

    destroiComplexo(numero1);
    destroiComplexo(numero2);
    destroiComplexo(resultado);



    return 0;
}

//valgrind --leak-check=yes ./a.out