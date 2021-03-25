#ifndef COMPLEXO_H
#define COMPLEXO_H

typedef struct Complexo_st *Complexo_pt;

Complexo_pt *criaComplexo (DESTE_TIPO_ *real, DESTE_TIPO_ *imag);

void destroiComplexo (Complexo_pt numComplexo);

DESTE_TIPO_ *retornaReal (Complexo_pt numComplexo);

DESTE_TIPO_ *retornaImaginario (Complexo_pt numComplexo);



#endif