#include "../include/heap.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// criar como se fosse um heap de matrizes
// temos que atualizar as matrizes e sair atualizando os pais
// temos que pegar um intervalo e multiplicar por um vetor

Matriz InicializaMatriz(int Tam){
  Matriz mat;
  mat.linha0 = (int*)malloc(Tam * sizeof(int));
  mat.linha1 = (int*)malloc(Tam * sizeof(int));
  int esc;
  for(int i = 0;i < Tam;i++){
    scanf("%d",&esc);
    mat.linha0[i] = esc;
  }
  for(int i = 0;i < Tam;i++){
    scanf("%d",&esc);
    mat.linha1[i] = esc;
  }
  return mat;
}

Matriz InicializaIndeMatriz(int Tam){
  Matriz mat;
  mat.linha0 = (int*)malloc(Tam * sizeof(int));
  mat.linha1 = (int*)malloc(Tam * sizeof(int));
  mat.linha0[0] = 1;
  mat.linha0[1] = 0;
  mat.linha1[0] = 0;
  mat.linha1[1] = 1;
  return mat;
}


Matriz MultiplicaMatriz(Matriz A1,Matriz A2){
  Matriz mat;
  mat = InicializaIndeMatriz(2);
  mat.linha0[0] = A1.linha0[0] * A2.linha0[0] + A1.linha0[1] * A2.linha1[0];
  mat.linha0[1] = A1.linha0[0] * A2.linha0[1] + A1.linha0[1] * A2.linha1[1];
  
  mat.linha1[0] = A1.linha1[0] * A2.linha0[0] + A1.linha1[1] * A2.linha1[0];
  mat.linha1[1] = A1.linha1[0] * A2.linha0[1] + A1.linha1[1] * A2.linha1[1];
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

int *MultiplicaVetor(Matriz a,int *b){
  int *aux;
  aux =  (int*)malloc(2 * sizeof(int));
  aux[0] = a.linha0[0] * b[0] + a.linha0[1] * b[1];
  aux[1] = a.linha1[0] * b[0] + a.linha1[1] * b[1];
  return aux;
}

Heap* NovoHeap(int maxsize){
    int x = 0;
    int num = 0;
    while(maxsize > num){
        num = pow(2,x);
        x++;
    }
    num = (num * 2) - 1;
    Heap *h;
    h = (Heap *)malloc(sizeof(Heap));
    h->tamanho = 0;
    h->dados = (Matriz*)malloc(num * sizeof(Matriz));
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
    res = MultiplicaMatriz(aux,a);
    SetMatriz(h, res, tam);
    tam = GetAncestral(h, tam);
  }while(tam > 0);
    aux = GetMatriz(h,0);
    res = MultiplicaMatriz(aux,a);
    SetMatriz(h, res, 0);
}

Matriz ConsultaHeap(Heap *h,int i,int j){
  int tam = gettamanho(h)/2;
  Matriz res = InicializaIndeMatriz(2);
  Matriz aux;
  for(int k = i + tam;k < j + tam;k++){
    aux = GetMatriz(h, k);
    res = MultiplicaMatriz(res,aux);
  }
  return res;
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
