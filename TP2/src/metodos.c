#include <stdio.h>
#include <stdlib.h>
#include "../include/metodos.h"
#define Troca(A, B) {Vertice c = A; A = B; B = c; }

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

void Selecao(Vertice *v,int n,Colecao *c);
void Insercao(Vertice *v,int n,Colecao *c);

void Quicksort(Vertice *v,int n,Colecao *c);
void Mergesort(Vertice *v,int n,Colecao *c);
void Heapsort(Vertice *v,int n,Colecao *c);

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
        if(i == 0){
            j = Pesquisa(v2,l);
            if(j == 0){
                p = p->prox;
            }
            else{
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
        }
        else{
            aux = l->primeiro->prox;
            while(aux!=NULL){
                if(aux->item == v1){
                    aux->item = v2;
                    break;
                }
                aux = aux->prox;
            }
            p = p->prox;
        }
        
    }
}

int gulosidade(Vertice *v,Colecao *c);