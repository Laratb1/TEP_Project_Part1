#ifndef COMPLEXO_H
#define COMPLEXO_H

typedef struct TIPADO_(Complexo_st) * TIPADO_(Complexo_pt);

TIPADO_(Complexo_pt) TIPADO_(criaComplexo) (DESTE_TIPO_ *real, DESTE_TIPO_ *imag);

void TIPADO_(destroiComplexo) (TIPADO_(Complexo_pt) numComplexo);




#endif