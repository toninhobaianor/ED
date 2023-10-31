#ifndef LISTA_H
#define LISTA_H

#include <stdbool.h>

typedef signed int TipoChave;

typedef struct{
    TipoChave chave;
}TipoItem;

void ImprimeChave(TipoItem i);
void setChave(TipoChave c,TipoItem i);
TipoChave getChave(TipoItem i);

struct celula {
    TipoItem item;
    struct celula* prox;
};
typedef struct celula Tipocelula;

void newcelula(Tipocelula *cel);

typedef struct {
    Tipocelula *primeiro;
    Tipocelula *ultimo;
    int tamanho;
}Lista;

void newlista(Lista *l);
TipoItem GetItem(int pos,Lista *l);
void SetItem(int pos,TipoItem item,Lista *l);
void InserePosicao(TipoItem item,int pos,Lista *l);
TipoItem RemovePosicao(int pos,Lista *l);
TipoItem Pesquisa(TipoChave c,Lista *l);
void Imprime(Lista *l);
void limpa(Lista *l);
Tipocelula* posiciona(int pos,bool arr,Lista *l);

struct celulaenca {
    Lista *l;
    struct celulaenca* prox;
};
typedef struct celulaenca Tipocelulaenca;

void newcelulaenca(Tipocelulaenca *cel);

typedef struct {
    Tipocelulaenca *primeiro;
    Tipocelulaenca *ultimo;
    int tamanho;
}Listaenca;

void newlistaenca(Listaenca *l);
Lista* GetLista(int pos,Listaenca *le);
void SetLista(int pos,Lista *l,Listaenca *le);
void InserePosicaoenca(Lista *l,int pos,Listaenca *le);
Lista* RemovePosicaoenca(int pos,Listaenca *le);
void limpaenca(Listaenca *l);
Tipocelulaenca* posicionaenca(int pos,bool arr,Listaenca *le);


#endif