#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

#include <string>

class No {
public:
    int id;
    int altura;
    No *esq; 
    No *dir;
    No *pai;

    No(const int id,No *p);
};

class ArvoreAVL {
private:
    No* insert(No* node, const int id , No *p);
    void Remove(No* node, const int id);
    No* Rotacaodireita(No* y);
    No* Rotacaoesquerda(No* x);
    int getBalance(No* N);
    int getAltura(No* N);
    void updateAltura(No* N);
    void inOrder(No* node);
    void freeNode(No* node);

public:
    No* root;

    ArvoreAVL();
    ~ArvoreAVL(); // Destructor to free memory
    void insert(const int id);
    void remove(const int id);
    void printInOrder();
};

#endif // AVL_TREE_HPP