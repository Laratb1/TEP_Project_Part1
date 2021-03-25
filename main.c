#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "complexo_double.h"
#include "complexo_long_int.h"
#include "complexo_racional.h"

int main(){
    double *imag;
    double *real;
    Complexo_pt numero;

    numero = criaComplexo(real, imag);

    printf("%f", retornaReal(&numero));
    printf("%f", retornaImaginario(numero));

    destroiComplexo(numero);



    return 0;
}