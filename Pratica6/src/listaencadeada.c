#include "listaencadeada.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool arr[2] = {true, false};

void newcelula(Tipocelula *cel) {
  cel->item.chave = -1;
  cel->prox = NULL;
}

void ImprimeChave(TipoItem i) { printf("%d", i.chave); }

void setChave(TipoChave c, TipoItem i) { i.chave = c; }

TipoChave getChave(TipoItem i) {
  TipoChave c = 0;
  c = i.chave;
  return c;
}

TipoItem GetItem(int pos, Lista *l) {
  Tipocelula *p;
  p = posiciona(pos, arr[1], l);
  return p->item;
}

void SetItem(int pos, TipoItem item, Lista *l) {
  Tipocelula *p;
  p = posiciona(pos, arr[1], l);
  p->item = item;
}

void InserePosicao(TipoItem item, int pos, Lista *l) {
  Tipocelula *p;
  Tipocelula *nova;
  nova = (Tipocelula *)malloc(sizeof(Tipocelula));
  p = posiciona(pos, arr[0], l);
  newcelula(nova);
  nova->item = item;
  nova->prox = p->prox;
  p->prox = nova;
  l->tamanho += 1;

  if (nova->prox == NULL) {
    l->ultimo = nova;
  }
}

void newlista(Lista *l) {
  Tipocelula *p;
  p = (Tipocelula *)malloc(sizeof(Tipocelula));
  newcelula(p);
  l->primeiro = p;
  l->ultimo = l->primeiro;
}

TipoItem RemovePosicao(int pos, Lista *l) {
  TipoItem aux;
  Tipocelula *p;
  Tipocelula *q;

  if (l->tamanho == 0) {
    printf("ERRO: lista vazia");
  }
  p = posiciona(pos, arr[0], l);
  q = p->prox;
  p->prox = q->prox;
  l->tamanho -= 1;
  aux = q->item;
  free(q);
  if (p->prox == NULL) {
    l->ultimo = p;
  }
  return aux;
}

TipoItem Pesquisa(TipoChave c, Lista *l) {
  TipoItem aux;
  Tipocelula *p;

  if (l->tamanho == 0) {
    printf("ERRO: lista vazia");
  }
  p = l->primeiro->prox;
  setChave(-1, aux);
  while (p != NULL) {
    if (getChave(p->item) == c) {
      aux = p->item;
      break;
    }
    p = p->prox;
  }
  return aux;
}

void Imprime(Lista *l) {
  Tipocelula *p;
  p = l->primeiro->prox;

  while (p != NULL) {
    ImprimeChave(p->item);
    p = p->prox;
  }
  printf("\n");
}

void limpa(Lista *l) {
  Tipocelula *p;
  p = l->primeiro->prox;

  while (p != NULL) {
    l->primeiro->prox = p->prox;
    free(p);
    p = l->primeiro->prox;
  }
  l->ultimo = l->primeiro;
  l->tamanho = 0;
}

Tipocelula *posiciona(int pos, bool arr, Lista *l) {

  Tipocelula *p;
  int i;
  if (pos > l->tamanho || pos <= 0) {
    printf("esta posicao não existe");
  }
  p = l->primeiro;
  for (i = 1; i < pos; i++) {
    p = p->prox;
  }

  if (arr = true) {
    p = p->prox;
  }
  return p;
}

void newcelulaenca(Tipocelulaenca *cel) {
  Lista *l;
  l = (Lista *)malloc(sizeof(Lista));
  newlista(l);
  cel->l = l;
  cel->prox = NULL;
}

void newlistaenca(Listaenca *l) {
  l->primeiro = NULL;
  l->ultimo = l->primeiro;
}

Lista *GetLista(int pos, Listaenca *le) {
  Tipocelulaenca *p;
  p = posicionaenca(pos, arr[1], le);
  return p->l;
}

void SetLista(int pos, Lista *l, Listaenca *le) {
  Tipocelulaenca *p;
  p = posicionaenca(pos, arr[1], le);
  p->l = l;
}

void InserePosicaoenca(Lista *l, int pos, Listaenca *le) {
  Tipocelulaenca *p;
  Tipocelulaenca *nova;
  nova = (Tipocelulaenca *)malloc(sizeof(Tipocelulaenca));
  p = posicionaenca(pos, arr[0], le);
  newcelulaenca(nova);
  nova->l = l;
  nova->prox = p->prox;
  p->prox = nova;
  le->tamanho += 1;

  if (nova->prox == NULL) {
    le->ultimo = nova;
  }
}

Lista *RemovePosicaoenca(int pos, Listaenca *le) {
  Lista *aux;
  Tipocelulaenca *p;
  Tipocelulaenca *q;

  if (le->tamanho == 0) {
    printf("ERRO: lista vazia");
  }
  p = posicionaenca(pos, arr[0], le);
  q = p->prox;
  p->prox = q->prox;
  le->tamanho -= 1;
  aux = q->l;
  free(q);
  if (p->prox == NULL) {
    le->ultimo = p;
  }
  return aux;
}

void limpaenca(Listaenca *l) {
  Tipocelulaenca *p;
  p = l->primeiro->prox;

  while (p != NULL) {
    l->primeiro->prox = p->prox;
    limpa(p->l);
    free(p);
    p = l->primeiro->prox;
  }

  l->ultimo = l->primeiro;
  l->tamanho = 0;
}

Tipocelulaenca *posicionaenca(int pos, bool arr, Listaenca *le) {

  Tipocelulaenca *p;
  int i;
  if (pos > le->tamanho || pos <= 0) {
    printf("esta posicao não existe");
  }
  p = le->primeiro;

  for (i = 1; i < pos; i++) {
    p = p->prox;
  }

  if (arr = true) {
    p = p->prox;
  }
  return p;
}