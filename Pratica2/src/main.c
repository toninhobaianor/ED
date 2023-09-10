#include "TP.h"
#include <getopt.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/resource.h>

#define FATITE 1
#define FIBITE 2
#define FIBREC 3
#define FATREC 4

static int opescolhida;
int opt;

float diffUserTime(struct rusage *start, struct rusage *end){
    return (end->ru_utime.tv_sec - start->ru_utime.tv_sec) +
           1e-6*(end->ru_utime.tv_usec - start->ru_utime.tv_usec);
}

float diffSystemTime(struct rusage *start, struct rusage *end){
    return (end->ru_stime.tv_sec - start->ru_stime.tv_sec) +
           1e-6*(end->ru_stime.tv_usec - start->ru_stime.tv_usec);
}

void uso() {
  // Descricao: imprime as opcoes de uso
  // Entrada: nao tem
  // Saida: impressao das opcoes de linha de comando{
  fprintf(stderr, "main\n");
  fprintf(stderr, "\t-a \t(fatorial iterativo)\n");
  fprintf(stderr, "\t-f \t(fibonaci iterativo)\n");
  fprintf(stderr, "\t-b \t(fibonaci recursivo)\n");
  fprintf(stderr, "\t-t \t(fatorial recursivo)\n");
}

void parse_args(int argc, char **argv) {
  // Descricao: le as opcoes da linha de comando e inicializa variaveis
  // Entrada: argc e argv
  // Saida: optescolhida, optx, opty

  // variaveis externas do getopt
  extern char *optarg;

  // variavel auxiliar
  int c;

  // inicializacao variaveis globais para opcoes
  opescolhida = -1;
  opt = -1;

  // getopt - letra indica a opcao, : junto a letra indica parametro
  // no caso de escolher mais de uma operacao, vale a ultima
  while ((c = getopt(argc, argv, "a:f:b:t:")) != EOF) {
    switch (c) {
    case 'a':
      opescolhida = FATITE;
      opt = atoi(optarg);
      break;
    case 'f':
      opescolhida = FIBITE;
      opt = atoi(optarg);
      break;
    case 'b':
      opescolhida = FIBREC;
      opt = atoi(optarg);
      break;
    case 't':
      opescolhida = FATREC;
      opt = atoi(optarg);
      break;
    default:
      uso();
      exit(1);
    }
  }
}

int main(int argc, char **argv) {
  struct rusage start, end;
  int i = 0;
  double time_spent = 0.0;
  parse_args(argc, argv);

  switch (opescolhida) {
  case FATITE:
    for(int j = 1;j<20;j++){
        
      clock_t begin3 = clock();
      getrusage(RUSAGE_SELF, &start);
      i = fatorial_ite(j);
      getrusage(RUSAGE_SELF, &end);
      clock_t end3 = clock();
      printf("%d", i);
      printf("\n");
      printf("  CPU time: %.06f sec user, %.06f sec system\n",
             diffUserTime(&start, &end), diffSystemTime(&start, &end));
      printf("\n");
      time_spent += (double)(end3 - begin3) / CLOCKS_PER_SEC;
 
      printf("The elapsed time is %f seconds", time_spent);
      printf("\n");
    }
    break;
  case FIBITE:
    for(int j = 0;j < 50;j++){
      clock_t begin2 = clock();
      getrusage(RUSAGE_SELF, &start);
      i = fibonaci_ite(j);
      getrusage(RUSAGE_SELF, &end);
      clock_t end2 = clock();
      printf("%d", i);
      printf("\n");
      printf("  CPU time: %.06f sec user, %.06f sec system\n",
             diffUserTime(&start, &end), diffSystemTime(&start, &end));
      time_spent += (double)(end2 - begin2) / CLOCKS_PER_SEC;
   
      printf("The elapsed time is %f seconds", time_spent);
      printf("\n");
    }
    break;
  case FIBREC:
    for(int j = 0;j < 20;j++){
      clock_t begin1 = clock();
      getrusage(RUSAGE_SELF, &start);
      i = fibonaci_rec(j);
      getrusage(RUSAGE_SELF, &end);
      clock_t end1 = clock();
      printf("%d", i);
      printf("\n");
      printf("  CPU time: %.06f sec user, %.06f sec system\n",
             diffUserTime(&start, &end), diffSystemTime(&start, &end));
      time_spent += (double)(end1 - begin1) / CLOCKS_PER_SEC;
   
      printf("The elapsed time is %f seconds", time_spent);
      printf("\n");
    }
    break;
  case FATREC:
    for(int j = 0;j<20;j++){
      clock_t begin4 = clock();
      getrusage(RUSAGE_SELF, &start);
      i = fatorial_rec(j);
      getrusage(RUSAGE_SELF, &end);
      clock_t end4 = clock();
      printf("%d", i);
      printf("\n");
      printf("  CPU time: %.06f sec user, %.06f sec system\n",
             diffUserTime(&start, &end), diffSystemTime(&start, &end));
      time_spent += (double)(end4 - begin4) / CLOCKS_PER_SEC;
 
      printf("The elapsed time is %f seconds", time_spent);
      printf("\n");
    }
    break;
  default:
    // nao deve ser executado, pois ha um erroAssert em parse_args
    uso();
    exit(1);
  }
}