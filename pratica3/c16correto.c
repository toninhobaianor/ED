#include <stdio.h>
#include <stdlib.h>

int actual_calc(int a, int b){
  int c;
  c=a/b;
  return c;
}

int calc(){
  int a;
  int b;
  int c;
  a=13;
  b=0;
  c = actual_calc(a, b);
  return c;
}

int main(){
  calc();
  return 0;
}