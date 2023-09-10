#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
  int i;
  int *a;

  for (i=0; i < 10; i++){
    a = malloc(sizeof(int) * 100);
  }
  for(i = 0; i < 10; i++){
    free(a[i]);
  }
  
  free(a);
  return 0;
}