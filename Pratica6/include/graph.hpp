#ifndef GRAPH_HPP
#define GRAPH_HPP

/*  Você pode inserir os includes necessários para que sua classe funcione.
 * Nenhuma outra alteração neste arquivo é permitida
 */


class Grafo{
    public:
        Grafo(bool debug);
        ~Grafo();

        void InsereVertice();
        void InsereAresta(int v, int w);

        int QuantidadeVertices();
        int QuantidadeArestas();

        int GrauMinimo();
        int GrauMaximo();

        void ImprimeVizinhos(int v);
        
    private:
        
        /*  Você deve implementar ListaAdjacencia como um TAD que irá armazenar
         * os dados do grafo. Lembrando que este TAD deve ser uma lista 
         * encadeada
         */
        ListaAdjacencia vertices;
};

#endif