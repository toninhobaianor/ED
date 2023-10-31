#ifndef LISTA_H
#define LISTA_H

struct celula {
    int item;
    struct celula* prox;
};
typedef struct celula Tipocelula;

Tipocelula* Novacelula();

typedef struct {
    Tipocelula *primeiro;
    Tipocelula *ultimo;
    int tamanho;
}Lista;

Lista* NovaLista();
int GetItem(int pos,Lista *l);
void SetItem(int pos,int item,Lista *l);
void InsereInicio(int item,Lista *l);
void InserePosicao(int item,int pos,Lista *l);
int RemovePosicao(int pos,Lista *l);
int Pesquisa(int c,Lista *l);
void Imprime(Lista *l);
void limpa(Lista *l);
Tipocelula* posiciona(int pos,char *arr,Lista *l);

#endif