#ifndef COMPLEXO_H
#define COMPLEXO_H

typedef struct Vetor_st *Vetor_pt;

Vetor_pt criaVetor(int n, int i, double *elementos);

void realocaEspaco(Vetor_pt vetor);

Vetor_pt destroiVetor(Vetor_pt vetor);

double retornaElementos(Vetor_pt vetor, int indice);

Vetor_pt atribuiVetor(Vetor_pt vetor1, Vetor_pt vetor2);

#endif
