#ifndef COMPLEXO_H
#define COMPLEXO_H

typedef struct Vetor_st *Vetor_pt;

Vetor_pt criaVetor(int n, int i, double *elementos);

void realocaEspaco(Vetor_pt vetor);

Vetor_pt destroiVetor(Vetor_pt vetor);

double retornaElementos(Vetor_pt vetor, int indice);

Vetor_pt atribuiVetor(Vetor_pt vetor1, Vetor_pt vetor2);

Vetor_pt criaCopiaVetor(Vetor_pt vetor); //milla

int retornaNumeroAtualElementos(Vetor_pt vetor);

int retornaNumeroMaxElementos(Vetor_pt vetor); //milla

int retornaIndice(Vetor_pt vetor);
// essas cinco funcoes devem retornar TIPO_ e nao double
double retornaPrimeiroElemento(Vetor_pt vetor); //milla

double retornaProximoElemento(Vetor_pt vetor, int indice);

double retornaElementoAnterior(Vetor_pt vetor, int indice); //milla

double retornaUltimoElemento(Vetor_pt vetor);

double retornaElementoDePosicaoI(Vetor_pt vetor, int indice); //milla

//trocar o double aqui tambem 2
Vetor_pt atribuirValorNaIesimaPosicao(Vetor_pt vetor, int indice, double valor);

Vetor_pt incrementaValor(Vetor_pt vetor, double valor); //milla

Vetor_pt eliminaElementoDePosicaoI(Vetor_pt vetor, int indice);

Vetor_pt eliminaTodosElementos(Vetor_pt vetor); //milla

double valorDeMaiorModulo(Vetor_pt vetor);
#endif
