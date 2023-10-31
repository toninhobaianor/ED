#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaencadeada.h"

Tipocelula* Novacelula(){
    Tipocelula *cel;
    cel = (Tipocelula*)malloc(sizeof(Tipocelula));
    cel->item = -1;
    cel->prox = NULL;
    return cel;
}

Lista* NovaLista(){
    Lista *l;
    Tipocelula *p;
    p = Novacelula();
    l = (Lista*)malloc(sizeof(Lista));
    l->primeiro = p;
    l->ultimo = l->primeiro;
    l->tamanho = 0;
    return l;
}

int GetItem(int pos,Lista *l){
    Tipocelula *p;
    char arr[6] = "false";
    p = posiciona(pos,arr,l);
    return p->item;
}

void SetItem(int pos,int item,Lista *l){
    Tipocelula *p;
    char arr[6] = "false";
    p = posiciona(pos,arr,l);
    p->item = item;
}

void InsereInicio(int item,Lista *l){
    Tipocelula *p;
    Tipocelula *nova;
    p = l->primeiro;
    nova = Novacelula();
    nova->item = item;
    nova->prox = p->prox;
    p->prox = nova;
    l->tamanho += 1;
    if(nova->prox == NULL){
        l->ultimo = nova;
    }

}

void InserePosicao(int item,int pos,Lista *l){
    Tipocelula *p;
    Tipocelula *nova;
    char arr[5] = "true";

    p = posiciona(pos,arr,l);

    nova = Novacelula();
    nova->item = item;
    nova->prox = p->prox;
    p->prox = nova;
    l->tamanho += 1;

    if(nova->prox == NULL){
        l->ultimo = nova;
    }
}


int RemovePosicao(int pos,Lista *l){
    int aux;
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
    int aux;
    Tipocelula *p;
    if(l->tamanho == 0){
        printf("ERRO: lista vazia");
    }

    p = l->primeiro->prox;
    aux = -1;

    while(p!=NULL){
        if(p->item == c){
            aux = p->item;
            break;
        }
        p = p->prox;
    }
    return aux;
}

void Imprime(Lista *l){
    Tipocelula *p;
    int i;
    p = l->primeiro->prox;
    while(p!=NULL){
        i = p->item;
        printf("%d",i);
        p = p->prox;
    }
    printf("\n");
}

void limpa(Lista *l){
    Tipocelula *p;
    p = l->primeiro->prox;

    while(p!=NULL){
        l->primeiro->prox = p->prox;
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
