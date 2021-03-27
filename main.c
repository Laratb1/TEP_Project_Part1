#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "complexo_double.h"
#include "complexo_long_int.h"
#include "complexo_racional.h"

int main(){
    double imag;
    double real;
    Complexo_pt numero;

    numero = criaComplexo(2, 3);

    printf("%f\n", *retornaReal(numero));
    printf("%f\n", *retornaImaginario(numero));

    destroiComplexo(numero);



    return 0;
}

//valgrind --leak-check=yes ./a.out