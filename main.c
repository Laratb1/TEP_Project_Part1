#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "vetor_double.h"
#include "vetor_int.h"
#include "vetor_complexo.h"

int main(){
    int n, N, i;
    double elementos[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26};
    double *pv = elementos; 
    Vetor_pt vetor1, veotr2;

    vetor1 = criaVetor(26, 0, pv);

    for(int i = 0; i < 5; i++){
        printf("%f ", retornaElementos(vetor1, i));
    }

    destroiVetor(vetor1);


    return 0; 
}
