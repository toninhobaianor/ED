// avlTree.h

#ifndef AVL_TREE_H
#define AVL_TREE_H

#include "pageAVLTree.h"
#include <string.h>

struct AVLNode {
    char* word;
    int height;
    struct AVLNode* left;
    struct AVLNode* right;
    struct PageAVLTree* pagesTree;
};

struct AVLTree {
    struct AVLNode* root;
};

struct AVLNode* createAVLNode(const char* w, int page);
struct AVLTree* createAVLTree();
void freeAVLTree(struct AVLNode* node);
int getHeightAVL(struct AVLNode* N);
void updateHeightAVL(struct AVLNode* N);
struct AVLNode* rightRotateAVL(struct AVLNode* y);
struct AVLNode* leftRotateAVL(struct AVLNode* x);
int getBalanceAVL(struct AVLNode* N);
struct AVLNode* insertAVL(struct AVLNode* node, const char* word, int page);
void insertAVLNode(struct AVLTree* tree, const char* word, int page);
void printInOrderAVL(struct AVLNode* node);
void inOrderAVL(struct AVLNode* node, void (visit)(const char, int));

#endif // AVL_TREE_H