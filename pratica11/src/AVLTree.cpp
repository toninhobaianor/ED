#include "../include/AVLTree.hpp"
#include <iostream>
#include <algorithm>

No::No(const int id,No *p) : id(id), altura(1), esq(nullptr), dir(nullptr), pai(p){}

ArvoreAVL::ArvoreAVL() : root(nullptr) {}

ArvoreAVL::~ArvoreAVL() {
    freeNode(root);
}

void ArvoreAVL::freeNode(No* node) {
    if (node != nullptr) {
        freeNode(node->esq);
        freeNode(node->dir);
        delete node;
    }
}

int ArvoreAVL::getAltura(No* N) {
    if (N == nullptr) return 0;
    return N->altura;
}

void ArvoreAVL::updateAltura(No* N) {
    N->altura = std::max(getAltura(N->esq), getAltura(N->dir)) + 1;
}

No* ArvoreAVL::Rotacaodireita(No* y) {
    y->pai->esq = y->dir;
    y->dir = y->pai;

    updateAltura(y);
    updateAltura(y->pai);

    return y->dir;
}

No* ArvoreAVL::Rotacaoesquerda(No* x) {
    x->pai->dir = x->esq;
    x->esq = x->pai;

    updateAltura(x);
    updateAltura(x->pai);

    return x->esq;
}

int ArvoreAVL::getBalance(No* N) {
    if (N == nullptr) return 0;
    return getAltura(N->esq) - getAltura(N->dir);
}

No* ArvoreAVL::insert(No* node, const int id,No *p) {
    if(node == nullptr){
        return new No(id,p);
    }
    if(id < node->id){
        node->esq = insert(node->esq,id,node);
    }
    else if(id > node->id){
        node->dir = insert(node->dir,id,node);
    }
    updateAltura(node);

    int balance = getBalance(node);

    // esq esq Case
    if (balance > 1 && id < node->esq->id) 
        return Rotacaodireita(node->pai);

    // dir dir Case
    if (balance < -1 && id > node->dir->id) 
        return Rotacaoesquerda(node->pai);

    // esq dir Case
    if (balance > 1 && id > node->esq->id) {
        node->esq = Rotacaoesquerda(node->esq);
        return Rotacaodireita(node);
    }

    // dir esq Case
    if (balance < -1 && id < node->dir->id) {
        node->dir = Rotacaodireita(node->dir);
        return Rotacaoesquerda(node);
    }
    return node;
}

void ArvoreAVL::Remove(No* node, const int id){
    if(id == node->id){
        if(node->dir == nullptr && node->esq == nullptr){
            free(node);
        }
        else if(node->dir != nullptr &&node->esq == nullptr){
            node->pai = node->dir;
            node->dir = nullptr;
            node->pai = nullptr;
            free(node);
        }
        else if(node->dir == nullptr && node->esq != nullptr){
            node->pai = node->esq;
            node->esq = nullptr;
            node->pai = nullptr;
            free(node);

        }
        else if(node->dir != nullptr && node->esq != nullptr){

        }
    }
    if(id < node->id){
        Remove(node->esq,id);
    }
    else if(id > node->id){
        Remove(node->dir,id);
    }
}


void ArvoreAVL::insert(const int id) {
    root = insert(root, id,nullptr);
}
void ArvoreAVL::remove(const int id){
    Remove(root,id);
}

void ArvoreAVL::printInOrder() {
    inOrder(root);
}

void ArvoreAVL::inOrder(No* node) {
    if (node != nullptr) {
        inOrder(node->esq);
        std::cout << node->id << ": ";
        std::cout << std::endl;
        inOrder(node->dir);
    }
}
