#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "vetor_double.h"
#include "vetor_int.h"
#include "vetor_complexo.h"

int main(){
    double elementos1[] = {5, 2, 7, 4, 1};
    double elementos2[] = {6, 7, 8, 9, 10};
    double *pv1 = elementos1;
    double *pv2 = elementos2; 
    Vetor_pt vetor1, vetor2, resultado;
    double valor;

    vetor1 = criaVetor(5, 0, pv1);
    vetor2 = criaVetor(5, 0, pv2);

    valor = valorDeMaiorModulo(vetor1);

    for(int i = 0; i < 5; i++){
        printf("%f ", retornaElementos(vetor1, i));
    }
    printf("\n");
    printf("%d\n", retornaIndice(vetor1));
    printf("%f\n", valor);

    destroiVetor(vetor1);
    destroiVetor(vetor2);
    

    return 0; 
}
