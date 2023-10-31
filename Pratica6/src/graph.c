#include "../include/graph.h"
#include "../include/listaencadeada.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

Grafo *NovoGrafo() {
  Grafo *g;
  g = (Grafo *)malloc(sizeof(Grafo));
  g->le = (Listaenca *)malloc(sizeof(Listaenca));
  newlistaenca(g->le);
  g->tamanho = 0;
  return g;
}
void DeletaGrafo(Grafo *g) {
  limpaenca(g->le);
  free(g);
}

void InsereVertice(Grafo *g) {
  Lista *l;
  l = (Lista *)malloc(sizeof(Lista *));
  newlista(l);
  InserePosicaoenca(l, g->tamanho, g->le);
  g->tamanho += 1;
}
void InsereAresta(Grafo *g, int v, int w) {
  Lista *l;
  l = GetLista(v, g->le);
  TipoItem i;
  i.chave = w;
  InserePosicao(i, l->tamanho, l);
  SetLista(v, l, g->le);
}

int QuantidadeVertices(Grafo *g) { return g->tamanho - 1; }
int QuantidadeArestas(Grafo *g) {
  Tipocelulaenca *p;
  p = g->le->primeiro->prox;
  float count = 0;
  while (p != NULL) {
    g->le->primeiro->prox = p->prox;
    count += (p->l->tamanho - 1);
    p = g->le->primeiro->prox;
  }
  float c = count / 2;
  return ceil(c);
}

int GrauMinimo(Grafo *g);
int GrauMaximo(Grafo *g);

void ImprimeVizinhos(Grafo *g, int v);