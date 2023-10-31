#include <stdio.h>
#include <stdlib.h>
#include "listaencadeada.h"

int main(){
    Lista*l;
    l = NovaLista();
    InsereInicio(1,l);
    //InserePosicao(1,1,l);
    Imprime(l);
    limpa(l);
    free(l);
}