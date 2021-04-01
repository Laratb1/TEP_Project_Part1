#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "complexo_double.h"
#include "complexo_long_int.h"
#include "complexo_racional.h"

int main(){

    printf("====== PROCESSAMENTO NUMEROS COMPLEXOS DO TIPO DOUBLE ======");

    Complexo_pt numComplexo1 = criaComplexo(56.99939, 49.93948);
    Complexo_pt numComplexo2 = criaComplexo(29.353243, 45.2343554);
    Complexo_pt resultado;

    resultado = atribuiComplexo(numComplexo1, numComplexo2);

    imprimeComplexo(resultado);
    

    destroiComplexo(numComplexo1);
    destroiComplexo(numComplexo2);

    return 0;
}





/*int main(){
    double imag;
    double real;
    Complexo_pt numero1, numero2;
    Complexo_pt resultado;

    numero1 = criaComplexo(1.5787, 2.7643);
    numero2 = criaComplexo(3, 4);

    numero1 = atibuiComplexo(numero1, numero2);

    if(resultado == 1)
        printf("V\n");
    if(resultado == 0)
        printf("F\n");
    if(resultado == -1)
        printf("2 maior\n");
        
    printf("%f\n", *retornaReal(numero1));
    printf("%f\n", *retornaImaginario(numero1));

    //printf("%f\n", resultado);

    destroiComplexo(numero1);
    destroiComplexo(numero2);
    destroiComplexo(resultado);



    return 0;
}*/

//valgrind --leak-check=yes ./a.out