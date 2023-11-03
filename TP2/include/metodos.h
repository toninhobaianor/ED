#ifndef METODOS_HPP
#define METODOS_HPP

#include "graph.h"
//teremos aqui a implementação dos metodos de ordenação e de qualquer outra função para resolver os problemas de gulosidade

void Bolha(Vertice *v,int n);
void Selecao(Vertice *v,int n,Colecao *c);
void Insercao(Vertice *v,int n,Colecao *c);

void Quicksort(Vertice *v,int n,Colecao *c);
void Mergesort(Vertice *v,int n,Colecao *c);
void Heapsort(Vertice *v,int n,Colecao *c);

void Meu_metodo(Vertice *v,int n,Colecao *c);

void AlteraLista(Colecao *c,int v1,int v2);

int gulosidade(Vertice *v,Colecao *c);

#endif
