#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "graph.h"

Vertice NovoVertice(int id,int cor){
    Vertice v;
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


Celula NovaCelula(Vertice v,int* liga){
    Celula c;
    c.v = v;
    c.ligacoes = liga;
    return c;
}

Vertice GetVertice(Celula c){
    return c.v;
}

void SetVertice(Celula c,Vertice v){
    c.v = v;
}

int* Getligacoes(Celula c){
    int *liga;
    liga = c.ligacoes;
    return liga;
}

void Setligacoes(Celula c,int* liga){
    c.ligacoes = liga;
}