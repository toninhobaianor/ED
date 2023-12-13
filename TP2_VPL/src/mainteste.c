#include <stdio.h>
#include <stdlib.h>
#include "../include/graph.h"
#include "../include/metodos.h"


int main(){
    // teste geral
    Vertice *vs;
    vs = (Vertice*)malloc(5 * sizeof(Vertice));

    //Vertice *v6;
    //v6 = (Vertice*)malloc(6 * sizeof(Vertice));

    Vertice v;
    v = NovoVertice(0,1,v);
    Vertice v1;
    v1 = NovoVertice(1,2,v1);
    Vertice v2;
    v2 = NovoVertice(2,1,v2);
    Vertice v3;
    v3 = NovoVertice(3,3,v3);
    Vertice v4;
    v4 = NovoVertice(4,2,v4);
  
    vs[0] = v1;
    vs[1] = v;
    vs[2] = v2;
    vs[3] = v3;
    vs[4] = v4;

    Lista*l;
    l = NovaLista();
    int *vet;
    vet = (int*)malloc(2 * sizeof(int));
    int *vet1;
    vet1 = (int*)malloc(2 * sizeof(int));
    int *vet2;
    vet2 = (int*)malloc(2 * sizeof(int));

    int *vet3;
    vet3 = (int*)malloc(2 * sizeof(int));
    int *vet4;
    vet4 = (int*)malloc(2 * sizeof(int));
  
    vet[0] = 1;
    vet[1] = 4;

    vet1[0] = 0;
    vet1[1] = 2;
  
    vet2[0] = 1;
    vet2[1] = 3;
  
    vet3[0] = 2;
    vet3[1] = 4;

    vet4[0] = 0;
    vet4[1] = 3;

    InsereInicio(vet,2,l);
    InserePosicao(vet1, 2, 1,l);
    InserePosicao(vet2, 2, 2,l);
    InserePosicao(vet3, 2, 3,l);
    InserePosicao(vet4, 2, 4,l);

    Bolha(vs,5);

    int i = gulosidade(vs,5,l);
    printf("%d ",i);
    /*Vertice v5;
    for(int i = 0;i < 5;i++){
        v5 = vs[i];
        printf("%d ",Getid(v5));
        printf("%d ",Getcor(v5));
        printf("\n");
    }*/
    free(vs);
    limpa(l);
    free(l);
    //free(v6);
    /*
    Vertice *vs;
    vs = (Vertice*)malloc(6 * sizeof(Vertice));

    Vertice *v6;
    v6 = (Vertice*)malloc(6 * sizeof(Vertice));
      
    Vertice v;
    v = NovoVertice(0,1,v);
    Vertice v1;
    v1 = NovoVertice(1,2,v1);
    Vertice v2;
    v2 = NovoVertice(2,3,v2);
    Vertice v3;
    v3 = NovoVertice(3,2,v3);
    Vertice v4;
    v4 = NovoVertice(4,1,v4);
    Vertice v7;
    v7 = NovoVertice(5,1,v7);
    vs[0] = v;
    vs[1] = v1;
    vs[2] = v2;
    vs[3] = v3;
    vs[4] = v4;
    vs[5] = v7;
    //Meu_metodo(vs, 4);
    //Heapsort(vs, 4);
    Mergesort(vs,v6,0, 6);
    //Bolha(vs,6);
    //Selecao(vs,3);
    //Insercao(vs,3);
  free(vs);
  free(v6);
    //int i = gulosidade(vs,5);
    //printf("%d",i);
    Vertice v5;
    for(int i = 0;i < 6;i++){
        v5 = vs[i];
        printf("%d",Getid(v5));
        printf("%d",Getcor(v5));
        printf("\n");
    }
    */
    //printf("\n");
    /*
    //Lista*l;
    //l = NovaLista();
    //InsereInicio(1,l);
    //InserePosicao(1,1,l);
    //Imprime(l);
    //limpa(l);
    //free(l);
    // lista dos vertices
    
    Vertice v;
    v = NovoVertice(1,1,v);
    Vertice v1;
    v1 = NovoVertice(2,2,v);
    Vertice v2;
    //printf("%d",Getid(v));
    //printf("%d",Getcor(v));
    */

    // lista de ligações
    /*Lista *l;
    Lista *l1;
    Lista *l2;
    Lista *l3;
    Colecao *c;
    l = NovaLista();
    InsereInicio(2,l);

    l1 = NovaLista();
    InsereInicio(0,l1);
    InserePosicao(1,1,l1);
    InserePosicao(3,2,l1);

    l2 = NovaLista();
    InsereInicio(2,l2);
    InserePosicao(3,1,l2);

    l3 = NovaLista();
    InsereInicio(1,l3);
    InserePosicao(2,1,l3);

    c = NovaColecao();
    InsereIni(l,c);
    InserePos(1,l1,c);
    InserePos(2,l2,c);
    InserePos(3,l3,c);

    Escreve(c);

    AlteraLista(c,1,2);

    Escreve(c);

    apaga(c);
    free(c);
    limpa(l);
    free(l);
    limpa(l1);
    free(l1);
    limpa(l2);
    free(l2);
    limpa(l3);
    free(l3)*/
    //nova lista de ligaçoes
  /*
    Lista*l;
    l = NovaLista();
    int *vet;
    vet = (int*)malloc(2 * sizeof(int));
    int *vet2;
    vet2 = (int*)malloc(3 * sizeof(int));
    int *vet1;
    vet[0] = 1;
    vet[1] = 2;

    vet2[0] = 5;
    vet2[1] = 0;
    vet2[2] = 1;
  
    InsereInicio(vet,2,l);
    InserePosicao(vet2, 3, 1,l);
    vet1 = GetItem(2, l);
    for(int i = 0;i < 3;i++){
      printf("%d",vet1[i]);
    }
    //InserePosicao(1,1,l);
    //Imprime(l);
    limpa(l);
    free(l);
  */
}
        