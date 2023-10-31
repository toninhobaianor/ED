#ifndef GRAPH_HPP
#define GRAPH_HPP

/*  Você pode inserir os includes necessários para que sua classe funcione.
 * Nenhuma outra alteração neste arquivo é permitida
 */


/*  Você deve implementar struct s_grafo como um TAD que irá armazenar
 * os dados de um grafo. Lembrando que a estratégia utilizada deve ser uma
 * lista de adjacencia e deve ser implementada como uma lista encadeada.
 */
struct s_vert{
    int id;
    int cor;
};
typedef struct s_vert Vertice;

struct s_cel{
    Vertice v;
    int *ligacoes;
};
typedef struct s_cel Celula;

Vertice NovoVertice(int id,int cor);
int Getid(Vertice v);
int Getcor(Vertice v);

Celula NovaCelula(Vertice v,int* liga);
Vertice GetVertice(Celula c);
void SetVertice(Celula c,Vertice v);
int* Getligacoes(Celula c);
void Setligacoes(Celula c,int* liga);

#endif