
#include <getopt.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../include/pilhaindexada.h"

#define AVALIA 1
#define SATISF 2

static int opescolhida;
char *opt;

void uso() {
  // Descricao: imprime as opcoes de uso
  // Entrada: nao tem
  // Saida: impressao das opcoes de linha de comando{
  fprintf(stderr, "main\n");
  fprintf(stderr, "\t-a \t(Avaliacao de expressao) \n");
  fprintf(stderr, "\t-s \t(Satisfabilidade) \n");
}

void parse_args(int argc, char **argv) {

  // variaveis externas do getopt
  extern char *optarg;

  // variavel auxiliar
  int c;

  // inicializacao variaveis globais para opcoes
  opescolhida = -1;

  // getopt - letra indica a opcao, : junto a letra indica parametro
  // no caso de escolher mais de uma operacao, vale a ultima
  while ((c = getopt(argc, argv, "a:s:")) != EOF) {
    switch (c) {
    case 'a':
      opescolhida = AVALIA;
      opt = optarg;
      break;
    case 's':
      opescolhida = SATISF;
      opt = optarg;
      break;
    default:
      uso();
      exit(1);
    }
  }
}

char *separa(char *res) {
  int count = 0;
  int j = 0;
  char *aux;
  aux = (char *)malloc(sizeof(char));
  for (int i = 0; i < strlen(res); i++) {
    if (res[i] == ' ') {
      count++;
      if (count == 2) {
        printf("%c",res[i + 1]);
        aux[j] = res[i + 1];
        j++;
      }
    }
  }
  return aux;
}

int main(int argc, char **argv) {
  char *res;
  parse_args(argc, argv);
  // printf("%s",opt);
  // printf("\n");
  printf("%d", strlen(opt));
  printf("\n");
  res = separa(opt);
  printf("\n");
  printf("%s", res);
}