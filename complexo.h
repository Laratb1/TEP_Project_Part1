#ifndef COMPLEXO_H
#define COMPLEXO_H
#define eps 0.00001

typedef struct Complexo_st *Complexo_pt;

Complexo_pt criaComplexo(TIPO_ numReal, TIPO_ numImag);

void destroiComplexo (Complexo_pt numComplexo);

TIPO_ *retornaReal (Complexo_pt numComplexo);

TIPO_ *retornaImaginario (Complexo_pt numComplexo);

void imprimeComplexo(Complexo_pt numComplexo);

Complexo_pt atribuiComplexo(Complexo_pt numComplexo1, Complexo_pt numComplexo2);

Complexo_pt copiaComplexo(Complexo_pt numero);

Complexo_pt converteDoubleParaLongInt(Complexo_pt numComplexo);

Complexo_pt converteLongIntParaDouble(Complexo_pt numComplexo);

Complexo_pt converteDoubleParaRacional(Complexo_pt numComplexo);

Complexo_pt converteRacionalParaDouble(Complexo_pt numComplexo);

Complexo_pt converteRacionalParaLongInt(Complexo_pt numComplexo);

Complexo_pt converteLongIntPataRacional(Complexo_pt numComplexo);

int verificaModuloZero(Complexo_pt numComplexo);

int verificaApenasReal(Complexo_pt numComplexo);

int verificaApenasImaginario(Complexo_pt numComplexo);

int comparaModuloNumeros(Complexo_pt numComplexo1, Complexo_pt numComplexo2);

int comparaAngulosNumeros(Complexo_pt numComplexo1, Complexo_pt numComplexo2);

long double retornaMagnitude(Complexo_pt numComplexo); 

long double retornaFase(Complexo_pt numComplexo);

void atribuiNovoValorReal(Complexo_pt numComplexo, TIPO_ novoValor);

void atribuiNovoValorImaginario(Complexo_pt numComplexo, TIPO_ novoValor);

void atribuiNovoValorModulo(Complexo_pt numComplexo, TIPO_ novoImag, TIPO_ novoReal);

TIPO_ retornaConjugado(Complexo_pt numComplexo);

Complexo_pt somaComplexo(Complexo_pt numComplexo1, Complexo_pt numComplexo2);
 
Complexo_pt subtraiComplexo(Complexo_pt numComplexo1, Complexo_pt numComplexo2);

Complexo_pt divideComplexo(Complexo_pt numComplexo1, Complexo_pt numComplexo2);

Complexo_pt multiplicaComplexo(Complexo_pt numComplexo1, Complexo_pt numComplexo2);

Complexo_pt acumulaSomando(Complexo_pt numComplexo1, Complexo_pt numComplexo2);

Complexo_pt acumulaMultiplicando(Complexo_pt numComplexo1, Complexo_pt numComplexo2);

Complexo_pt operacaoComplexo(Complexo_pt numComplexo1, Complexo_pt numComplexo2, char *operacao);

#endif