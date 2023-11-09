#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../include/graph.h"
#include "../include/metodos.h"

//int main(int argc, char ** argv){
/*
int n = 0;
char esc;
scanf("%c %d", &esc, &n);

Vertice *vs;
vs = (Vertice*)malloc(n * sizeof(Vertice));

Vertice *v;
v = (Vertice*)malloc(n * sizeof(Vertice));


Lista *l;
l = NovaLista();
int re = 0;
int *vet;

for(int j = 0;j < n;j++){
  int k = 0;
  scanf("%d ",&k);
  vet = (int*)malloc(k * sizeof(int));
  
  for(int b = 0;b < k;b++){
        scanf("%d ",&re);
        vet[b] = re;
        re = 0;
    }
  if(j == 0){
    InsereInicio(vet,k,l);
  }
  else{
    InserePosicao(vet,k,j,l);
  }
}
  
Imprime(l);
int cor;
for(int i = 0;i < n;i++){
  scanf("%d",&cor);
  vs[i] = NovoVertice(i,cor,vs[i]);
}

int gul;
switch(esc){
    case 'b':
        Bolha(vs,n);
        gul = gulosidade(vs,n);
        printf("%d ",gul);
        if(gul == 1){
            for(int i = 0;i < n;i++){
                printf("%d ",vs[i].id);
            }
        }
        printf("\n");
        break;
    case 's':
        Selecao(vs,n);
        gul = gulosidade(vs,n);
        printf("%d ",gul);
        if(gul == 1){
            for(int i = 0;i < n;i++){
                printf("%d ",vs[i].id);
            }
        }
        printf("\n");
        break;
    case 'i':
        Insercao(vs,n);
        gul = gulosidade(vs,n);
        printf("%d ",gul);
        if(gul == 1){
            for(int i = 0;i < n;i++){
                printf("%d ",vs[i].id);
            }
        }
        printf("\n");
        break;
    case 'q':
        Quicksort(vs,n);
        gul = gulosidade(vs,n);
        printf("%d ",gul);
        if(gul == 1){
            for(int i = 0;i < n;i++){
                printf("%d ",vs[i].id);
            }
        }
        printf("\n");
        break;
    case 'm':
        Mergesort(vs,v,0,n);
        gul = gulosidade(v,n);
        printf("%d ",gul);
        if(gul == 1){
            for(int i = 0;i < n;i++){
                printf("%d ",v[i].id);
            }
        }
        printf("\n");
        break;
    case 'p':
        Heapsort(vs,n);
        gul = gulosidade(vs,n);
        printf("%d ",gul);
        if(gul == 1){
            for(int i = 0;i < n;i++){
                printf("%d ",vs[i].id);
            }
        }
        printf("\n");
        break;
    case 'y':
        printf("\n");
        break;
    default:
        exit(1);
    }
    limpa(l);
    free(vs);
    free(l);
*/
//}