#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include "../include/graph.h"
#include "../include/listaencadeada.h"

#define DADOS 1
#define VIZIO 2
#define IMPRI 3

static int opescolhida;
int opt;

void uso(){
// Descricao: imprime as opcoes de uso
// Entrada: nao tem
// Saida: impressao das opcoes de linha de comando{
  fprintf(stderr,"main\n");
  fprintf(stderr,"\t-d \t(Dados Basicos) \n");
  fprintf(stderr,"\t-n \t(Vizinhanças) \n");
  fprintf(stderr,"\t-k \t(imprimir)\n");
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
  while ((c = getopt(argc, argv, "dn:k:")) != EOF)
  {
    switch(c) {
      case 'd':
	      opescolhida = DADOS;
        break;
      case 'n':
	      opescolhida = VIZIO;
        break;
      case 'k':
	      opescolhida = IMPRI;
        break;
      default:
        uso();
        exit(1);
    }
  }
}

int main(int argc, char ** argv){

parse_args(argc,argv);
printf("\n");
Grafo *g;
g = NovoGrafo();
int i = 0;
int quant = 0;
  
switch(opescolhida){
    case DADOS:
        
        scanf("%d", &i);
        for(int j = 0;j <= i;j++){
          InsereVertice(g);
          
          //scanf("%d ",&quant);
          //for(int k = 1;k <= quant;k++){
           // printf("Hello");
           // InsereAresta(g,j+1,k);
          //}
        }
        int q = QuantidadeVertices(g);
        //int a = QuantidadeArestas(g);
        printf("%d",q);
        //printf("%d",a);
        printf("\n");
        break;
    case VIZIO:
        printf("\n");
        break;
    case IMPRI:
        printf("\n");
        break;
    default:
        uso();
        exit(1);
    }
}