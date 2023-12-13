#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "../include/heap.h"

int main(){
  Heap *p;
  int n;
  int q;
  
  int a;
  
  int x;
  int y;
  int tz;
  int td;
  
  Matriz m;
  int *res;
  res =  (int*)malloc(2 * sizeof(int));
  char esc[1];
  
  scanf("%d %d",&n,&q);
  p = NovoHeap(n);
  
  for(int i = 0;i < (n*4);i++){
      Matriz e;
      e = InicializaIndeMatriz(2);
      Inserir(p,e);
  }
  
  for(int i = 0;i < q;i++){
    scanf("%s ",esc);
    
    if(strcmp(esc,"u") == 0){
      scanf("%d",&a);
      m = InicializaMatriz();
      AtualizaHeap(p,m,a);
    }
    else{
      scanf("%d %d %d %d",&tz,&td,&x,&y);
      m = ConsultaHeap(0,(n/2) - 1,p,0,tz,td);
      res = MultiplicaVetor(m,x,y,res);
      for(int j = 0;j < 2;j++){
        if(res[j] > 100000000){
            printf("%d ",1);
        }
        else{
            printf("%d ",res[j]);
        }
      }
      printf("\n");
    }
  }
  free(res);
  DeletaHeap(p);
}