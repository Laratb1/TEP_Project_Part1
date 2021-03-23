#ifndef RACIONAIS_H
#define RACIONAIS_H

typedef struct Racional_st *Racional_pt;
typedef struct Racional_st Racional_t;

Racional_pt criaNumRacional(long int numerador, long int denominador);

long int retornaDen(Racional_pt numero);

long int retornaNum(Racional_pt numero);

void destroiNum(Racional_pt numRacional);

Racional_pt copiaNumRacional(Racional_pt num1, Racional_pt num2);

int comparaNumeros(Racional_pt valor1, Racional_pt valor2);

int verificaEquivalente(Racional_pt valor1, Racional_pt valor2);

int verificaDenominadorZero(Racional_pt numRacional);

int verificaNumeradorZero(Racional_pt numRacional);

int verificaAmbosZero(Racional_pt numRacional);

double somaRacionais(Racional_pt valor1, Racional_pt valor2);

Racional_pt acumulaRacional(Racional_pt valor1, Racional_pt valor2);
#endif