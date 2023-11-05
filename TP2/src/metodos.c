#include <stdio.h>
#include <stdlib.h>
#include "metodos.h"
#define Troca(A, B) {Vertice c = A; A = B; B = c; }
// metodos basicos funcionando
void Bolha(Vertice *v,int n){
    int i, j;
    for(i = 0; i < n-1; i++){
        for(j = 1; j < n-i; j++){
            if (v[j].cor < v[j-1].cor){
                Troca(v[j-1], v[j]);
            }
        }
    }   
}

void Selecao(Vertice *v,int n){
    int i, j, Min;
    for (i = 0; i < n - 1; i++){
        Min = i;
        for (j = i + 1 ; j < n; j++){
            if (v[j].cor < v[Min].cor){
                Min = j;
            }
        }
        Troca(v[i], v[Min]);
    }
}

void Insercao(Vertice *v,int n){
    int i,j;
    Vertice aux;
    for (i = 1; i < n; i++) {
        aux = v[i];
        j = i - 1;
        while (( j >= 0 ) && (aux.cor < v[j].cor)){
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = aux;
    }
}

// problemas com o heap
void Refaz(int Esq, int Dir, Vertice *A){
    int i, j;
    Vertice x;
    i = Esq;
    j = i * 2;
    x = A[i];
    while (j <= Dir){
        if (j < Dir){
            if (A[j].cor < A[j+1].cor){ 
                j++;
            }
        }
        if (x.cor >= A[j].cor){
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
    Esq = n / 2 + 1;
    while (Esq > 1) {
        Esq--;
        Refaz(Esq, n, A);
    }
}

void Heapsort(Vertice *v,int n,Colecao *c){
    int Esq; 
    int Dir;
    Vertice x;
    Constroi(v, n); 
    Esq = 1; 
    Dir = n;
    while (Dir > 1){ 
        x = v[1];
        v[1] = v[Dir];
        v[Dir] = x;
        Dir--;
        Refaz(Esq, Dir, v);
    }
}

//quick funcionando 
void Particao(int Esq, int Dir,int *i, int *j,Vertice *A){
    Vertice x;
    Vertice w;
    *i = Esq; 
    *j = Dir;
    x = A[(*i + *j)/2]; /* obtem o pivo x */
    do
    {
        while (x.cor > A[*i].cor){
            (*i)++;
        }
        while (x.cor < A[*j].cor){
            (*j)--;
        }
        if(*i <= *j){
            w = A[*i]; 
            A[*i] = A[*j]; 
            A[*j] = w;
            (*i)++; (*j)--;
        }
    } while (*i <= *j);
}

void Ordena(int Esq, int Dir, Vertice *A){ 
    int i;
    int j;
    Particao(Esq, Dir, &i, &j, A);
    if (Esq < j){
        Ordena(Esq, j, A);
    }
    if (i < Dir){
        Ordena(i, Dir, A);
    }
}

void Quicksort(Vertice *v,int n,Colecao *c){
    Ordena(0, n-1, v);
}


// terminar o merge sort e testar
void merge(Vertice *v,int nl, int nr) {
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < nl && j < nr) {
        if (v[i].cor < v[nr - j].cor) {
            v[k] = v[i];
            i++;
        } 
        else {
            v[k] = v[j];
            j++;
        }
        k++;
    }
    if (k < nl + nr) {
        for(; i < nl; i++) {
            v[k] = v[i];
            k++;
        }
        for(; j < nr; j++) {
            v[k] = v[j];
            k++;
        }
    }

}


void Mergesort(Vertice *v,int Esquerda,int Direita,Colecao *c){
    if (Esquerda < Direita) {
        int Meio = Esquerda + (Direita - Esquerda) / 2;

        // Ordenar a metade esquerda
        Mergesort(v, Esquerda, Meio,c);

        // Ordenar a metade direita
        Mergesort(v, Meio + 1, Direita,c);

        // Mesclar as duas metades ordenadas
        merge(v, Esquerda,Direita);
    }
}

//pensar,criar,fazer e testar meu proprio metodo
void Meu_metodo(Vertice *v,int n,Colecao *c);

void AlteraLista(Colecao *c,int v1,int v2){
    int i;
    int j;
    Celula *p;
    Tipocelula *aux;
    p = c->primeiro->prox;
    Lista *l;
    while(p!=NULL){
        l = p->ligacoes;
        i = Pesquisa(v1,l);
        j = Pesquisa(v2,l);
        if(i == 1){
            aux = l->primeiro->prox;
            while(aux!=NULL){
                if(aux->item == v1){
                    aux->item = v2;
                    break;
                }
                aux = aux->prox;
            }
            if(j == 1){
                while(aux!=NULL){
                    if(aux->item == v2){
                        aux->item = v1;
                        break;
                    }
                    aux = aux->prox;
                }
                p = p->prox;
            }
            else{
                p = p->prox;
            }
        }
        else{
            if(j == 1){
                aux = l->primeiro->prox;
                while(aux!=NULL){
                    if(aux->item == v2){
                        aux->item = v1;
                        break;
                    }
                    aux = aux->prox;
                }
                p = p->prox;
            }
            else{
                p = p->prox;
            }
            
        }
    }
}

int gulosidade(Vertice *v,int n){
    int k = v[n - 1].cor;
    int count = 1;
    int y = k - 1;
    for(int i = 1;i < n;i++){
        if(v[n - i].cor == y){
            y--;
            count++;
        }
    }
    if(count < k){
        return 0;
    }
}