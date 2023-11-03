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


struct s_cel{
    Lista* ligacoes;
    struct s_cel* prox;
};
typedef struct s_cel Celula;

typedef struct {
    Celula *primeiro;
    Celula *ultimo;
    int tamanho;
}Colecao;



Celula* NovaCelula(Lista* liga);
Lista* Getligacoes(Celula* c);
void Setligacoes(Celula* c,Lista* liga);

Colecao* NovaColecao();
void InsereIni(Lista *l,Colecao *c);
void InserePos(int pos,Lista *l,Colecao *c);
Lista* RemovePos(int pos,Colecao *c);
Celula Pesq(int p,Colecao *c);
void Escreve(Colecao *c);
void apaga(Colecao *c);
Celula* posicio(int pos,char *arr,Colecao *c);

#endif