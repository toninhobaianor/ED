 #include <stdlib.h>

int* f(int *x) {

  x = malloc(10 * sizeof(int));
  x[10] = 0; 
  return x;
}

int main(void) {

  int *x;
  f(x);
  free(x);

  return 0;
}

