#include <stdio.h>
#include <stdlib.h>

int main()
{
  char *p;

  p = (char *) malloc(19 * sizeof(char));
  p = (char *) malloc(12);
  free(p);
  p = (char *) malloc(16);

  return 0;
}

// o free não funciona,pois tem uma chamada do p depois dele 
