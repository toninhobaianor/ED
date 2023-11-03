#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "../include/graph.h"

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
    int aux = 0;
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

// struct Celula

Celula* NovaCelula(Lista* liga){
    Celula *c;
    c = (Celula*)malloc(sizeof(Celula));
    c->ligacoes = liga;
    return c;
}


Lista* Getligacoes(Celula *c){
    Lista *liga;
    liga = c->ligacoes;
    return liga;
}

void Setligacoes(Celula *c,Lista* liga){
    c->ligacoes = liga;
}

// struct Colecao 

Colecao* NovaColecao(){
    Colecao *c;
    Lista *l;
    Celula *p;
    c = (Colecao*)malloc(sizeof(Colecao));
    l = NovaLista();
    p = NovaCelula(l);
    c->primeiro = p;
    c->ultimo = NULL;
    c->tamanho = 0;
    return c;
}

void InsereIni(Lista *l,Colecao *c){
    Celula *p;
    Celula *nova;
    p = c->primeiro;
    nova = NovaCelula(l);
    nova->prox = p->prox;
    p->prox = nova;
    c->tamanho += 1;
     if(nova->prox == NULL){
        c->ultimo = nova;
    }
}

void InserePos(int pos,Lista *l,Colecao *c){
    Celula *p;
    Celula *nova;
    char arr[5] = "true";

    p = posicio(pos,arr,c);

    nova = NovaCelula(l);
    nova->prox = p->prox;
    p->prox = nova;
    c->tamanho += 1;

    if(nova->prox == NULL){
        c->ultimo = nova;
    }
}

Lista* RemovePos(int pos,Colecao *c){
    Lista *aux;
    Celula *p;
    Celula *q;

    char arr[5] = "true";
    if(c->tamanho == 0){
        printf("ERRO: lista vazia");
    }

    p = posicio(pos,arr,c);
    q = p->prox;
    p->prox = q->prox;
    c->tamanho -= 1;
    aux = q->ligacoes;
    limpa(q->ligacoes);
    free(q);
    if(p->prox == NULL){
        c->ultimo = p;
    }
    return aux;
}
Celula Pesq(int p,Colecao *c);

void Escreve(Colecao *c){

    Celula *p;
    Lista *l;
    p = c->primeiro->prox;
    while(p!=NULL){
        l = p->ligacoes;
        Imprime(l);
        p = p->prox;
        printf("\n");
    }
    printf("\n");
}

void apaga(Colecao *c){

    Celula *p;
    p = c->primeiro->prox;
    while(p!=NULL){
        c->primeiro->prox = p->prox;
        limpa(p->ligacoes);
        p = c->primeiro->prox;
    }
    p = c->primeiro->prox;
    while(p!=NULL){
        c->primeiro->prox = p->prox;
        free(p);
        p = c->primeiro->prox;
    }
    c->ultimo = c->primeiro;
    c->tamanho = 0;
}

Celula* posicio(int pos,char *arr,Colecao *c){

    Celula *p;
    int i;
    if(pos > c->tamanho || pos <= 0){
        printf("esta posicao não existe");
    }
    p = c->primeiro;
    for(i = 1;i < pos;i++){
        p = p->prox;
    }

    if(strcmp(arr,"true") == 0){
        p = p->prox;
    }
    return p;
}