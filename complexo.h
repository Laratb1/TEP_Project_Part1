#ifndef COMPLEXO_H
#define COMPLEXO_H

typedef struct Complexo_st *Complexo_pt;

Complexo_pt criaComplexo (double numReal, double numImag);

void destroiComplexo (Complexo_pt numComplexo);

double *retornaReal (Complexo_pt numComplexo);

double *retornaImaginario (Complexo_pt numComplexo);

Complexo_pt atribuiComplexo(Complexo_pt numComplexo1, Complexo_pt numComplexo2);

Complexo_pt copiaComplexo(Complexo_pt numero);

Complexo_pt converteDoubleParaLongInt(Complexo_pt numComplexo);

Complexo_pt converteLongIntParaDouble(Complexo_pt numComplexo);

Complexo_pt converteDoubleParaRacional(Complexo_pt numComplexo);

Complexo_pt converteRacionalParaDouble(Complexo_pt numComplexo);

Complexo_pt converteRacionalParaLongInt(Complexo_pt numComplexo);

Complexo_pt converteLongIntPataRacional(Complexo_pt numComplexo);
#endif