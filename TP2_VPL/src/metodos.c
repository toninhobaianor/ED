#include "../include/metodos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Troca(A, B)                                                            \
  {                                                                            \
    Vertice c = A;                                                             \
    A = B;                                                                     \
    B = c;                                                                     \
  }
// metodos basicos funcionando
void Bolha(Vertice *v, int n) {
  int i, j;
  for (i = 0; i < n - 1; i++) {
    for (j = 1; j < n - i; j++) {
      if (v[j].cor < v[j - 1].cor) {
        Troca(v[j - 1], v[j]);
      }
    }
  }
}

void Selecao(Vertice *v, int n) {
  int i, j, Min;
  for (i = 0; i < n - 1; i++) {
    Min = i;
    for (j = i + 1; j < n; j++) {
      if (v[j].cor < v[Min].cor) {
        Min = j;
      }
    }
    Troca(v[i], v[Min]);
  }
}

void Insercao(Vertice *v, int n) {
  int i, j;
  Vertice aux;
  for (i = 1; i < n; i++) {
    aux = v[i];
    j = i - 1;
    while ((j >= 0) && (aux.cor < v[j].cor)) {
      v[j + 1] = v[j];
      j--;
    }
    v[j + 1] = aux;
  }
}

// problemas com o heap
void Refaz(int Esq, int Dir, Vertice *A) {
  int i;
  int j;
  Vertice x;
  i = Esq;
  j = i * 2;
  x = A[i];
  while (j <= Dir) {
    if (j < Dir) {
      if (A[j].cor < A[j + 1].cor) {
        j++;
      }
    }
    if (x.cor >= A[j].cor) {
      break;
    }
    A[i] = A[j];
    i = j;
    j = i * 2;
  }
  A[i] = x;
}

void Constroi(Vertice *A, int n) {
  int Esq;
  Esq = ((n - 1) / 2) + 1;
  while (Esq > 0) {
    Esq--;
    Refaz(Esq, n, A);
  }
}

void Heapsort(Vertice *v, int n) {
  int Esq;
  int Dir;
  Vertice x;
  Constroi(v, n);
  Esq = 0;
  Dir = n - 1;
  while (Dir >= 1) {
    x = v[0];
    v[0] = v[Dir];
    v[Dir] = x;
    Dir--;
    Refaz(Esq, Dir, v);
  }
}

// quick funcionando
void Particao(int Esq, int Dir, int *i, int *j, Vertice *A) {
  Vertice x;
  Vertice w;
  *i = Esq;
  *j = Dir;
  x = A[(*i + *j) / 2]; /* obtem o pivo x */
  do {
    while (x.cor > A[*i].cor) {
      (*i)++;
    }
    while (x.cor < A[*j].cor) {
      (*j)--;
    }
    if (*i <= *j) {
      w = A[*i];
      A[*i] = A[*j];
      A[*j] = w;
      (*i)++;
      (*j)--;
    }
  } while (*i <= *j);
}

void Ordena(int Esq, int Dir, Vertice *A) {
  int i;
  int j;
  Particao(Esq, Dir, &i, &j, A);
  if (Esq < j) {
    Ordena(Esq, j, A);
  }
  if (i < Dir) {
    Ordena(i, Dir, A);
  }
}

void Quicksort(Vertice *v, int n) { Ordena(0, n - 1, v); }

// terminar o merge sort e testar
void merge(Vertice *v, Vertice *vs, int nl, int nr, int meio) {
  int i = 0;
  int j = 0;
  int k = 0;
  while (i < meio && j < meio + 1) {
    if (v[nl + i].cor <= v[meio + 1 + j].cor) {
      vs[k] = v[nl + i];
      i++;
    } else {
      vs[k] = v[meio + 1 + j];
      j++;
    }
    k++;
  }
  if (k < nl + nr) {
    for (; i < meio; i++) {
      vs[k] = v[nl + i];
      k++;
    }
    for (; j < meio + 1; j++) {
      vs[k] = v[meio + 1 + j];
      k++;
    }
  }
}

void Mergesort(Vertice *v, Vertice *vs, int Esquerda, int Direita) {
  if (Esquerda < Direita) {
    int Meio = (Direita - 1 + Esquerda) / 2;
    // Ordenar a metade esquerda
    Mergesort(v, vs, Esquerda, Meio);

    // Ordenar a metade direita
    Mergesort(v, vs, Meio + 1, Direita - 1);

    // Mesclar as duas metades ordenadas
    merge(v, vs, Esquerda, Direita, Meio);
  }
}

int getNextGap(int gap) {
  gap = (gap * 10) / 13;

  if (gap < 1) {
    return 1;
  }
  return gap;
}

// pensar,criar,fazer e testar meu proprio metodo
void Meu_metodo(Vertice *v, int n) {
  // Initialize gap
  int gap = n;
  char swapped[6] = "true";

  while (gap != 1 || strcmp(swapped, "true") == 0) {
    gap = getNextGap(gap);

    strcpy(swapped, "false");

    // Compare all elements with current gap
    for (int i = 0; i < n - gap; i++) {
      if (v[i].cor > v[i + gap].cor) {
        Troca(v[i], v[i + gap]);
        strcpy(swapped, "true");
      }
    }
  }
}

Vertice procura(Vertice *v, int n, int id) {
  Vertice aux;
  for (int i = 0; i < n; i++) {
    if (v[i].id == id) {
      aux = v[i];
    }
  }
  return aux;
}

int gulosidade(Vertice *v,int n,Lista *l){
    //aqui precisamos olhar os vizinhos de um vertice,para saber se ele tem vizinhos menores que ele
    int k = v[n - 1].cor;
    int count = 1;
    int y = k - 1;
    for(int i = 1;i <= n;i++){
        if(v[n - i].cor == y){
            y--;
            count++;
        }
    }
    if(count < k){
        return 0;
    }
    int cor = 1;
    int i = 0;
    int cont = 1;
    int *conexoes;
    Vertice vert_atual;
    while(i < n){
        int vert_id = v[i].id;
        int vert_cor = v[i].cor;
        conexoes = GetItem(vert_id + 1,l);
        int tam = GetSize(vert_id + 1,l);
        if(tam == 0){
            cont++;
        }
        int vert_atual_id;
        int vert_cor_atual;

        for(int j = 0;j < tam;j++){
            vert_atual_id = conexoes[j];
            printf("%d ",vert_atual_id);
            vert_atual = procura(v,n,vert_atual_id);
            vert_cor_atual = vert_atual.cor;

            if(vert_cor_atual == vert_cor){
                return 0;
            }
            if(vert_cor_atual == cor && vert_cor > 1){
                cor++;
            }
            if(cor == vert_cor && vert_cor > 1){
                cont++;
                break;
            }

        }
        printf("\n");
        cor = 1;
        i++;
    }

    if(cont == n){
        return 1;
    }

    return 0;
}