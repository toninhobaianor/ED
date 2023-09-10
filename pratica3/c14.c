#include <stdio.h>

int main(void) {
  int n = 0;
  int i; 
  int fact = 1;

  printf("Positive integer:");
  scanf("%d", &n);
  
  for(i = 1; i<=n; i++) 
    fact = fact*i;

  printf("Factorial %d = %d\n", n, fact);
}

// o fact não tem nada,zero ou seja o fatorial não vai funcionar
