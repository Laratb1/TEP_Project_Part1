/*#ifdef TIPADO_ 
#ifdef DESTE_TIPO_ double
#ifdef DESTE_FORMATO_ */
#include <stdio.h>
#include <stdlib.h> 
#include <math.h> 
#include "vetor.h"

typedef struct Vetor_st{
	  int n; // numero de elementos atual
    int N; // numero máximo de elementos
    int i;
    double *elementos;
}Vetor_t;

typedef struct Vetor_st * Vetor_pt;

Vetor_pt criaVetor(int n, int i, double *elementos){ //Conferir essa parte com a Lara
    Vetor_pt vetor = (Vetor_t*) malloc(sizeof(Vetor_t));
    vetor->elementos = (double*) malloc(n * sizeof(double));
    
    vetor->n = n;
    vetor->N = 100;
    vetor->i = i;

    realocaEspaco(vetor);
    
    for(int c = 0; c < vetor->n; c++){
       *(vetor->elementos+c) = elementos[c];
    }

    return vetor;
}

void realocaEspaco(Vetor_pt vetor){ //acho que isso pode ficar dentro da funcao de criar vetor
    if(vetor->n >= vetor->N){
        vetor->elementos = (double*) realloc(vetor->elementos, 2 * vetor->n * sizeof(double));
    }
    if(vetor->n <= (vetor->N / 4)){
        vetor->elementos = (double*) realloc(vetor->elementos, 0.5 * vetor->n * sizeof(double));
    }
}

void destroiVetor(Vetor_pt vetor){
    free(vetor->elementos);
    vetor->elementos = NULL;
    free(vetor);
    vetor = NULL;
}

double retornaElementos(Vetor_pt vetor, int indice){
    return vetor->elementos[indice];
}

Vetor_pt atribuiVetor(Vetor_pt vetor1, Vetor_pt vetor2){
    for(int c = 0; c < vetor1->n; c++){
        *(vetor1->elementos+c) = *(vetor2->elementos+c);
    }
   return vetor1;
}

Vetor_pt criaCopiaVetor( Vetor_pt vetor){
  Vetor_pt vetorNovo = criaVetor(vetor->n, vetor->i, vetor->elementos);
  return vetorNovo;
}

int retornaNumeroAtualElementos(Vetor_pt vetor){
    return vetor->n;
}

int retornaNumeroMaxElementos(Vetor_pt vetor){
  return vetor->N;
} //milla

int retornaIndice(Vetor_pt vetor){
    return vetor->i;
}

double retornaPrimeiroElemento(Vetor_pt vetor){
    return *(vetor->elementos);
} //milla

double retornaProximoElemento(Vetor_pt vetor, int indice){
    vetor->i = indice + 1;
    return vetor->elementos[indice+1];
}

double retornaElementoAnterior(Vetor_pt vetor, int indice){
  return vetor->elementos[indice-1];
} //milla

double retornaUltimoElemento(Vetor_pt vetor){
    vetor->i = vetor->n-1;
    return vetor->elementos[vetor->n-1];
}

double retornaElementoDePosicaoI(Vetor_pt vetor, int indice){
    return vetor->elementos[indice];
} //milla

Vetor_pt atribuirValorNaIesimaPosicao(Vetor_pt vetor, int indice, double valor){
    vetor->elementos[indice] = valor;
    vetor->i = indice;

    return vetor;
}

void adicionaElemento(Vetor_pt vetor, double valor){
    vetor->elementos[vetor->n] = valor;
    vetor->n += 1;
} //milla

Vetor_pt eliminaElementoDePosicaoI(Vetor_pt vetor, int indice){ //Revisar o significado dessa funcao
    for(int c = indice; c < vetor->n; c++){
        vetor->elementos[c] = vetor->elementos[c+1];
    }
    vetor->n = vetor->n-1;
    //estou na duvida se faco esse realloc 
    vetor->elementos = (double*) realloc(vetor->elementos, vetor->n * sizeof(double));
    return vetor; //precisa?
}

// eh isso mesmo?
void eliminaTodosElementos(Vetor_pt vetor){
    for (int i = 0; i < vetor->n; i++){
      eliminaElementoDePosicaoI(vetor, i);
    }
} //milla

double valorDeMaiorModulo(Vetor_pt vetor){
    double maior;
    maior = fabs(vetor->elementos[0]);
    vetor->i = 0;
    for(int c = 0; c < vetor->n; c++){
        if(fabs(vetor->elementos[c]) > maior){
            maior = vetor->elementos[c];
            vetor->i = c;
        }
    }
    return maior;
}

double valorDeMenorModulo(Vetor_pt vetor){
  double menor = fabsl(vetor->elementos[0]);
  int i;
  for (int i = 0; i < vetor->n; i++){
    if (fabsl(vetor->elementos[i]) < menor){
      menor = vetor->elementos[i];
      vetor->i = i;
    }
  }
  return menor;
} //milla

int quantElementosDeValorV(Vetor_pt vetor, double valor){
    int quant;
    for(int c = 0; c < vetor->n; c++){
        // verificar eps
        if(vetor->elementos[c] == valor || fabs(vetor->elementos[c]-valor) < eps){
            quant++;
        }
    }
    return quant;
}

// Tentar fazer de um jeito mais simples
Vetor_pt retornaVetorComPosicoesQueTemV(Vetor_pt vetor, double valor){
    Vetor_pt vetorComPosicoes;
    int n = 0;
    for(int i = 0; i < vetor->n; i++){
      if (vetor->elementos[i] == valor){
        n++;
      }
    }
    double elementos[n];
    n = 0;
    for(int i = 0; i < vetor->n; i++){
      if (vetor->elementos[i] == valor){
        elementos[n] = i;
        n++;
      }
    }
    vetorComPosicoes = criaVetor(n, 0, elementos);
    return vetorComPosicoes;
} //milla

int criterioOrdenacao (const void * a, const void * b){ // Compara os de conteúdos "a" e "b" e retorna para a função qsort se "a" é maior, menor ou igual que "b"

  if (*(double*)a == *(double*)b){
    return 0; // Iguais
  }
  else if (*(double*)a < *(double*)b){
    return -1; //  A "a" vem antes da "b"
  }
  else{
    return 1; //  A "a" vem depois da "b"
  }
}

//Conferir
void ordenarVetor(Vetor_pt vetor){
  qsort(vetor->elementos, vetor->n, sizeof(double), criterioOrdenacao);
} //usar qsort, lara

Vetor_pt intercalaVetor(Vetor_pt vetor1, Vetor_pt vetor2){
  int n = vetor1->n + vetor2->n;
  int iv1 = 0, iv2 =0;
  double elementos[n];
  Vetor_pt vetorNovo = criaVetor(n, 0, elementos);
  for (int i = 0; i < n; i++){
    if(i%2 == 0){
      vetorNovo->elementos[i] = vetor1->elementos[iv1];
      iv1++;
    }
    else{
      vetorNovo->elementos[i] = vetor2->elementos[iv2];
      iv2++;
    }
  }   
  return vetorNovo;
}//milla

Vetor_pt somaVetores(Vetor_pt vetor1, Vetor_pt vetor2){
  Vetor_pt vetorNovo = criaCopiaVetor(vetor1);

  for (int i = 0; i < vetorNovo->n; i++){
    vetorNovo->elementos[i] += vetor2->elementos[i];
  }
  return vetorNovo;
} // lara

double produtoInternoVetores (Vetor_pt vetor1, Vetor_pt vetor2){
  double produtoInterno = 0;

  for (int i = 0; i < vetor1->n; i++){
    produtoInterno += vetor1->elementos[i]*vetor2->elementos[i];
  }
  return produtoInterno;
} //milla

Vetor_pt subtraiVetores(Vetor_pt vetor1, Vetor_pt vetor2){
  Vetor_pt vetorNovo = criaCopiaVetor(vetor1);

  for (int i = 0; i < vetorNovo->n; i++){
    vetorNovo->elementos[i] -= vetor2->elementos[i];
  }
  return vetorNovo;
} //lara

void multiplicaVetorPorEscalar(Vetor_pt vetor, double escalar){
    for (int i = 0; i < vetor->n; i++){
      vetor->elementos[i] *= escalar;
    }
} //milla

void acumulaVetor (Vetor_pt vetor1, Vetor_pt vetor2){
  for (int i = 0; i < vetor1->n; i++){
    vetor1->elementos[i] += vetor2->elementos[i];
  }
} //lara

double mediaArimetica (Vetor_pt vetor){
    double media = 0;
    for (int i = 0; i < vetor->n; i++){
      media += vetor->elementos[i];
    }
    return media/vetor->n;
} // milla

double varianciaVetor (Vetor_pt vetor){
    double media = mediaArimetica(vetor);
    double variancia = 0;
    for (int i = 0; i < vetor->n; i++){
      variancia += pow((vetor->elementos[i] - media), 2);
    }
    variancia = variancia/vetor->n;
    return variancia;
} // lara

double desvioPadrao (Vetor_pt vetor){
  double DP;
  DP = sqrt(varianciaVetor(vetor));
  
  return DP;
} // milla

//Fiz do jeito "burro" porque nao entendi muito bem o metodo no link que o Saulo colocou no arquivo, depois vou tentar ver melhor
double medianaVetor (Vetor_pt vetor){
  ordenarVetor(vetor);
  double mediana = 0;
  if (vetor->n%2 == 0){
    mediana = (vetor->elementos[(vetor->n/2)-1] + vetor->elementos[vetor->n/2])/2;
  }
  else{
    mediana = vetor->elementos[(vetor->n-1)/2];
  }
  return mediana;
} // lara