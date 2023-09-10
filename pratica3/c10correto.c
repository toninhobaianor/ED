#include <stdlib.h>
#include <stdio.h>

int main(void){
  
  int *p;
  int i = 0;
  while(i < 4){
    p = malloc(128);
    printf("%ld\n", (long)p);
    i++;
    free(p);
  }
  return (0);
}