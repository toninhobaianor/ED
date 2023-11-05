#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "metodos.h"

int main(){
    Vertice *vs;
    vs = (Vertice*)malloc(5 * sizeof(Vertice));
    Vertice v;
    v = NovoVertice(1,1,v);
    Vertice v1;
    v1 = NovoVertice(2,2,v1);
    Vertice v2;
    v2 = NovoVertice(3,3,v2);
    Vertice v3;
    v3 = NovoVertice(4,4,v3);
    Vertice v4;
    v4 = NovoVertice(5,5,v4);
    vs[0] = v4;
    vs[1] = v3;
    vs[2] = v1;
    vs[3] = v;
    vs[4] = v2;
    Bolha(vs,5);
    //Selecao(vs,3);
    //Insercao(vs,3);
    Vertice v5;
    for(int i = 0;i < 5;i++){
        v5 = vs[i];
        printf("%d",Getid(v5));
        printf("%d",Getcor(v5));
        printf("\n");
    }
    //int i = gulosidade(vs,5);
    //printf("%d",i);
    printf("\n");
    
    //Lista*l;
    //l = NovaLista();
    //InsereInicio(1,l);
    //InserePosicao(1,1,l);
    //Imprime(l);
    //limpa(l);
    //free(l);
    // lista dos vertices
    /*
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
}