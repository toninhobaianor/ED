#include "../include/heap.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// criar como se fosse um heap de matrizes
// temos que atualizar as matrizes e sair atualizando os pais
// temos que pegar um intervalo e multiplicar por um vetor

Matriz InicializaMatriz(){
  Matriz mat;
  int esc;
  int esc2;
  scanf("%d %d",&esc,&esc2);
  
  mat.linha0[0] = esc;
  mat.linha0[1] = esc2;

  scanf("%d %d",&esc,&esc2);
  mat.linha1[0] = esc;
  mat.linha1[1] = esc2;

  return mat;
}

Matriz InicializaIndeMatriz(){
  Matriz mat;
  mat.linha0[0] = 1;
  mat.linha0[1] = 0;
  mat.linha1[0] = 0;
  mat.linha1[1] = 1;
  return mat;
}


Matriz MultiplicaMatriz(Matriz A1,Matriz A2,int i,int j){
  Matriz mat;
  mat = InicializaIndeMatriz(2);
  if(j > i){
      mat.linha0[0] = A2.linha0[0] * A1.linha0[0] + A2.linha0[1] * A1.linha1[0];
      mat.linha0[1] = A2.linha0[0] * A1.linha0[1] + A2.linha0[1] * A1.linha1[1];
      
      mat.linha1[0] = A1.linha1[0] * A2.linha0[0] + A1.linha1[1] * A2.linha1[0];
      mat.linha1[1] = A1.linha1[0] * A2.linha0[1] + A1.linha1[1] * A2.linha1[1];
  }
  else{
      mat.linha0[0] = A1.linha0[0] * A2.linha0[0] + A1.linha0[1] * A2.linha1[0];
      mat.linha0[1] = A1.linha0[0] * A2.linha0[1] + A1.linha0[1] * A2.linha1[1];
  
      mat.linha1[0] = A1.linha1[0] * A2.linha0[0] + A1.linha1[1] * A2.linha1[0];
      mat.linha1[1] = A1.linha1[0] * A2.linha0[1] + A1.linha1[1] * A2.linha1[1];
  }
  return mat;
}

void EscreveMatriz(Matriz a){
    printf("%d ",a.linha0[0]);
    printf("%d",a.linha0[1]);
    printf("\n");
    printf("%d ",a.linha1[0]);
    printf("%d",a.linha1[1]);
    printf("\n");
}

int *MultiplicaVetor(Matriz a,int b,int c,int *aux){
  aux[0] = a.linha0[0] * b + a.linha0[1] * c;
  aux[1] = a.linha1[0] * b + a.linha1[1] * c;
  return aux;
}

Heap* NovoHeap(int maxsize){
    Heap *h;
    h = (Heap *)malloc(sizeof(Heap));
    h->tamanho = 0;
    h->dados = (Matriz*)malloc((maxsize * 4) * sizeof(Matriz));
    return h;
}

void DeletaHeap(Heap* h){
    free(h->dados);
    free(h);
}

void Inserir(Heap* h, Matriz x){
    h->dados[h->tamanho] = x;
    h->tamanho += 1; 
}

Matriz GetMatriz(Heap* h,int pos){
  Matriz res;
  //int aux = gettamanho(h);
  //int tam = pos + (aux/2);
  res = h->dados[pos];
  return res;
}

void SetMatriz(Heap* h,Matriz a,int pos){
  //int aux = gettamanho(h);
  //int tam = pos + (aux/2);
  h->dados[pos] = a;
}

int GetAncestral(Heap* h, int posicao){
    return (posicao-1)/2;
}
int GetSucessorEsq(Heap* h, int posicao){
    return (2*posicao) + 1;
}
int GetSucessorDir(Heap* h, int posicao){
    return (2*posicao) + 2;
}

int gettamanho(Heap* h){
  int tam;
  tam = h->tamanho;
  return tam;
}

void AtualizaHeap(Heap* h,Matriz a,int pos){
  int auxi = gettamanho(h);
  int tam = pos + (auxi/2);
  Matriz res;
  Matriz aux;
  do{
    aux = GetMatriz(h,tam);
    res = MultiplicaMatriz(aux,a,tam,tam);
    SetMatriz(h, res, tam);
    tam = GetAncestral(h, tam);
  }while(tam > 0);
    aux = GetMatriz(h,0);
    res = MultiplicaMatriz(aux,a,0,0);
    SetMatriz(h, res, 0);
}

Matriz ConsultaHeap(int com,int fim,Heap *h,int p,int i,int j){
  Matriz aux = InicializaIndeMatriz();
  if(j < com || fim < i) return aux;
  if(i <= com && fim <= j) return h->dados[p];
  int m = (com + fim)/2;
  return MultiplicaMatriz(ConsultaHeap(com,m,h,GetSucessorEsq(h,p),i,j),ConsultaHeap(m + 1,fim,h,GetSucessorDir(h,p),i,j),GetSucessorEsq(h,p),GetSucessorDir(h,p));
}

//Retorna 1 caso h esteja vazio, 0 caso contrário.
int Vazio(Heap* h){
    if(sizeof(h->dados) == 0){
        return 1;
    }
    else{
        return 0;
    }
} 
