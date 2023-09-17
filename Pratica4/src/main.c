#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include "TP.h"

#define FATITE 1
#define FIBITE 2
#define FIBREC 3
#define FATREC 4

static int opescolhida;
int opt;

void uso(){
// Descricao: imprime as opcoes de uso
// Entrada: nao tem
// Saida: impressao das opcoes de linha de comando{
  fprintf(stderr,"main\n");
  fprintf(stderr,"\t-a \t(fatorial iterativo) \n");
  fprintf(stderr,"\t-f \t(fibonaci iterativo) \n");
  fprintf(stderr,"\t-b \t(fibonaci recursivo)\n");
  fprintf(stderr,"\t-t \t(fatorial recursivo)\n");
}

void parse_args(int argc,char ** argv){

  // variaveis externas do getopt
  extern char *optarg;

  // variavel auxiliar
  int c;

  // inicializacao variaveis globais para opcoes
  opescolhida = -1;
  opt = -1;

  // getopt - letra indica a opcao, : junto a letra indica parametro
  // no caso de escolher mais de uma operacao, vale a ultima
  while ((c = getopt(argc, argv, "a:f:b:t:")) != EOF)
  {
    switch(c) {
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

int main(int argc, char ** argv){

parse_args(argc,argv);
int i = 0;
printf("\n");

switch(opescolhida){
  case FATITE:
    i = fatorial_ite(opt);
    printf("%d",i);
    printf("\n");
    break;
  case FIBITE:
    i = fibonaci_ite(opt);
    printf("%d",i);
    printf("\n");
    break;
  case FIBREC:
    i = fibonaci_rec(opt);
    printf("%d",i);
    printf("\n");
    break;
  case FATREC:
    i = fatorial_rec(opt);
    printf("%d",i);
    printf("\n");
    break;
  default:
    // nao deve ser executado, pois ha um erroAssert em parse_args
    uso();
	 exit(1);


}

}