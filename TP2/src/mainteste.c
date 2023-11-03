#include "../include/graph.h"
#include "../include/metodos.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  /*Vertice *vs;
  vs = (Vertice *)malloc(3 * sizeof(Vertice));
  Vertice v;
  v = NovoVertice(1, 1, v);
  Vertice v1;
  v1 = NovoVertice(2, 2, v1);
  Vertice v2;
  v2 = NovoVertice(3, 3, v2);
  vs[0] = v2;
  vs[1] = v;
  vs[2] = v1;
  Bolha(vs, 3);
  Vertice v3;
  for (int i = 0; i < 3; i++) {
    v3 = vs[i];
    printf("%d", Getid(v3));
    printf("%d", Getcor(v3));
    printf("\n");
  }
  */
  // Lista*l;
  // l = NovaLista();
  // InsereInicio(1,l);
  // InserePosicao(1,1,l);
  // Imprime(l);
  // limpa(l);
  // free(l);
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
  Lista *l;
  Lista *l1;
  Colecao *c;
  l = NovaLista();
  l1 = NovaLista();
  c = NovaColecao();
  InsereInicio(1, l);
  InserePosicao(2, 1, l);
  InsereInicio(1, l1);
  InserePosicao(3, 1, l1);
  InsereIni(l, c);
  InserePos(1, l1, c);
  Escreve(c);
  AlteraLista(c, 4, 1);
  Escreve(c);
  apaga(c);
  free(c);
  limpa(l);
  free(l);
  limpa(l1);
  free(l1);
}