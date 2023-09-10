#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/resource.h>
#include "../include/TP.h"

float diffUserTime(struct rusage *start, struct rusage *end){
    return (end->ru_utime.tv_sec - start->ru_utime.tv_sec) +
           1e-6*(end->ru_utime.tv_usec - start->ru_utime.tv_usec);
}

float diffSystemTime(struct rusage *start, struct rusage *end){
    return (end->ru_stime.tv_sec - start->ru_stime.tv_sec) +
           1e-6*(end->ru_stime.tv_usec - start->ru_stime.tv_usec);
}

int main(int argc, char **argv) {
  struct rusage start, end;
  int op;
  int i;
  int k;
  scanf("%d ",&op);
  
  switch(op){
    case 1:
      for(int j = 0;j<12;j++){
        getrusage(RUSAGE_SELF, &start);
        i = fatorial_ite(j);
        getrusage(RUSAGE_SELF, &end);
        printf("%d",i);
        printf("\n");
        printf("  CPU time: %.06f sec user, %.06f sec system\n",
           diffUserTime(&start, &end), diffSystemTime(&start, &end));
      }
      break;
    case 2:
      i = fibonaci_ite(k);
      printf("%d",i);
      printf("\n");
      break;
    case 3:
      i = fibonaci_rec(k);
      printf("%d",i);
      printf("\n");
      break;
    case 4:
      i = fatorial_rec(k);
      printf("%d",i);
      printf("\n");
      break;
    default:
      break;
  }

}
