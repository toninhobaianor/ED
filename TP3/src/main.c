#include <stdio.h>
#include <stdlib.h>
#include "../include/heap.h"

int main(){
    Heap *p;
    p = NovoHeap(4);
    for(int i = 0;i < 7;i++){
      Matriz a;
      a = InicializaIndeMatriz(2);
      Inserir(p,a);
    }
    Matriz d;
    d = InicializaMatriz(2);
    AtualizaHeap(p, d, 0);
    AtualizaHeap(p, d, 1);
    Matriz e = ConsultaHeap(p,0,2);
    //Matriz f = MultiplicaMatriz(d, e);
    EscreveMatriz(e);

    DeletaHeap(p);
    return 0;
}