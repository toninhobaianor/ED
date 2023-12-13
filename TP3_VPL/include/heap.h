#ifndef HEAP_HPP
#define HEAP_HPP

typedef struct s_mat{
    int linha0[2];
    int linha1[2];
}Matriz;

Matriz InicializaMatriz();
Matriz InicializaIndeMatriz();
Matriz MultiplicaMatriz(Matriz A1,Matriz A2,int i,int j);
void EscreveMatriz(Matriz A);
int *MultiplicaVetor(Matriz a,int b,int c,int *aux);

typedef struct s_heap{
    int tamanho;
    Matriz* dados;
} Heap;

Heap* NovoHeap(int maxsize);
void DeletaHeap(Heap* h);
void Inserir(Heap* h,Matriz x);

void SetMatriz(Heap* h,Matriz a,int pos);
Matriz GetMatriz(Heap* h,int pos);
int GetAncestral(Heap* h, int posicao);
int GetSucessorEsq(Heap* h, int posicao);
int GetSucessorDir(Heap* h, int posicao);

int gettamanho(Heap* h);
void AtualizaHeap(Heap* h,Matriz a,int pos);
Matriz ConsultaHeap(int com,int fim,Heap *h,int p,int i,int j);
//Retorna 1 caso h esteja vazio, 0 caso contrário.
int Vazio(Heap* h); 

#endif