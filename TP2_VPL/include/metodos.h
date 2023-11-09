#ifndef METODOS_HPP
#define METODOS_HPP

#include "graph.h"
//teremos aqui a implementação dos metodos de ordenação e de qualquer outra função para resolver os problemas de gulosidade

void Bolha(Vertice *v,int n);
void Selecao(Vertice *v,int n);
void Insercao(Vertice *v,int n);

void Constroi(Vertice *A, int n);
void Refaz(int Esq, int Dir, Vertice *A);
void Heapsort(Vertice *v,int n);

void Particao(int Esq, int Dir,int *i, int *j,Vertice *A);
void Ordena(int Esq, int Dir, Vertice *A);
void Quicksort(Vertice *v,int n);

void merge(Vertice *v,Vertice *vs,int nl, int nr,int meio);
void Mergesort(Vertice *v,Vertice *vs,int Esquerda,int Direita);

int getNextGap(int gap);
void Meu_metodo(Vertice *v,int n);

Vertice procura(Vertice* v,int n,int id);
int gulosidade(Vertice *v,int n,Lista *l);

#endif
