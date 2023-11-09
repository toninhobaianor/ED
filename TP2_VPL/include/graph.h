#ifndef GRAPH_HPP
#define GRAPH_HPP

struct s_vert{
    int id;
    int cor;
};

typedef struct s_vert Vertice;

Vertice NovoVertice(int id,int cor,Vertice v);
int Getid(Vertice v);
int Getcor(Vertice v);

struct celula {
    int *item;
    int tam;
    struct celula* prox;
};
typedef struct celula Tipocelula;

Tipocelula* Novacelula(int size);

typedef struct {
    Tipocelula *primeiro;
    Tipocelula *ultimo;
    int tamanho;
}Lista;

Lista* NovaLista();
int* GetItem(int pos,Lista *l);
void SetItem(int pos,int *item,Lista *l);
void InsereInicio(int *item,int size,Lista *l);
void InserePosicao(int *item,int size,int pos,Lista *l);
int* RemovePosicao(int pos,Lista *l);
int Pesquisa(int c,Lista *l);
void Imprime(Lista *l);
void limpa(Lista *l);
Tipocelula* posiciona(int pos,char *arr,Lista *l);

#endif