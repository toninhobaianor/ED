#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "graph.h"

// struct Vertice
Vertice NovoVertice(int id,int cor,Vertice v){
    v.id = id;
    v.cor = cor;
    return v;
}

int Getid(Vertice v){
    return v.id;
}

int Getcor(Vertice v){
    return v.cor;
}

Tipocelula* Novacelula(int size){
    Tipocelula *cel;
    cel = (Tipocelula*)malloc(sizeof(Tipocelula));
    int *n;
    n = (int*)malloc(size * sizeof(int));
    cel->item = n;
    cel->tam = size;
    cel->prox = NULL;
    return cel;
}

Lista* NovaLista(){
    Lista *l;
    Tipocelula *p;
    p = Novacelula(1);
    int *aux;
    aux = p->item;
    aux[0] = -1;
    p->item = aux;
    l = (Lista*)malloc(sizeof(Lista));
    l->primeiro = p;
    l->ultimo = l->primeiro;
    l->tamanho = 0;
    return l;
}

int* GetItem(int pos,Lista *l){
    Tipocelula *p;
    char arr[6] = "false";
    p = posiciona(pos,arr,l);
    return p->item;
}

void SetItem(int pos,int *item,Lista *l){
    Tipocelula *p;
    char arr[6] = "false";
    p = posiciona(pos,arr,l);
    p->item = item;
}

void InsereInicio(int *item,int size,Lista *l){
    Tipocelula *p;
    Tipocelula *nova;
    p = l->primeiro;
    nova = Novacelula(size);
    nova->item = item;
    nova->prox = p->prox;
    p->prox = nova;
    l->tamanho += 1;
    if(nova->prox == NULL){
        l->ultimo = nova;
    }

}

void InserePosicao(int *item,int size,int pos,Lista *l){
    Tipocelula *p;
    Tipocelula *nova;
    char arr[5] = "true";

    p = posiciona(pos,arr,l);

    nova = Novacelula(size);
    nova->item = item;
    nova->prox = p->prox;
    p->prox = nova;
    l->tamanho += 1;

    if(nova->prox == NULL){
        l->ultimo = nova;
    }
}


int* RemovePosicao(int pos,Lista *l){
    int *aux;
    Tipocelula *p;
    Tipocelula *q;

    char arr[5] = "true";
    if(l->tamanho == 0){
        printf("ERRO: lista vazia");
    }

    p = posiciona(pos,arr,l);
    q = p->prox;
    p->prox = q->prox;
    l->tamanho -= 1;
    aux = q->item;
    free(q);
    if(p->prox == NULL){
        l->ultimo = p;
    }
    return aux;
}

int Pesquisa(int c,Lista *l){
    int *aux;
    Tipocelula *p;
    if(l->tamanho == 0){
        printf("ERRO: lista vazia");
    }

    p = l->primeiro->prox;

    while(p!=NULL){
        aux = p->item;
        for(int i = 0;i < p->tam;i++){
            if(aux[i] == c){
                return 1;
                break;
            }
        }
        p = p->prox;
    }
    return 0;
}

void Imprime(Lista *l){
    Tipocelula *p;
    int *i;
    p = l->primeiro->prox;
    while(p!=NULL){
        i = p->item;
        for(int j = 0;j < p->tam;j++){
            printf("%d ",i[j]);
        }
        printf("\n");
        p = p->prox;
    }
    printf("\n");
}

void limpa(Lista *l){
    Tipocelula *p;
    p = l->primeiro->prox;

    while(p!=NULL){
        l->primeiro->prox = p->prox;
        free(p->item);
        free(p);
        p = l->primeiro->prox;
    }
    l->ultimo = l->primeiro;
    l->tamanho = 0;
}

Tipocelula* posiciona(int pos,char *arr,Lista *l){
    
    Tipocelula *p;
    int i;
    if(pos > l->tamanho || pos <= 0){
        printf("esta posicao não existe");
    }
    p = l->primeiro;
    for(i = 1;i < pos;i++){
        p = p->prox;
    }

    if(strcmp(arr,"true") == 0){
        p = p->prox;
    }
    return p;
}
