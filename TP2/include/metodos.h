#ifndef METODOS_HPP
#define METODOS_HPP

#include "graph.h"
//teremos aqui a implementação dos metodos de ordenação e de qualquer outra função para resolver os problemas de gulosidade

void Bolha(Vertice *v,int n);
void Selecao(Vertice *v,int n);
void Insercao(Vertice *v,int n);

void Constroi(Vertice *A, int n);
void Refaz(int Esq, int Dir, Vertice *A);
void Heapsort(Vertice *v,int n,Colecao *c);

void Particao(int Esq, int Dir,int *i, int *j,Vertice *A);
void Ordena(int Esq, int Dir, Vertice *A);
void Quicksort(Vertice *v,int n,Colecao *c);

void merge(Vertice *v,int nl, int nr);
void Mergesort(Vertice *v,int Esquerda,int Direita,Colecao *c);


void Meu_metodo(Vertice *v,int n,Colecao *c);

void AlteraLista(Colecao *c,int v1,int v2);

int gulosidade(Vertice *v,int n);

#endif
