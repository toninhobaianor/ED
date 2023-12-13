// pageAVLTree.c

#include "pageAVLTree.h"
#include <stdio.h>
#include <stdlib.h>

struct PageAVLNode* createPageAVLNode(int p) {
    struct PageAVLNode* newNode = (struct PageAVLNode*)malloc(sizeof(struct PageAVLNode));
    newNode->page = p;
    newNode->height = 1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct PageAVLTree* createPageAVLTree() {
    struct PageAVLTree* newTree = (struct PageAVLTree*)malloc(sizeof(struct PageAVLTree));
    newTree->root = NULL;
    return newTree;
}

void freePageAVLTree(struct PageAVLNode* node) {
    if (node != NULL) {
        freePageAVLTree(node->left);
        freePageAVLTree(node->right);
        free(node);
    }
}

int getHeight(struct PageAVLNode* N) {
    return (N == NULL) ? 0 : N->height;
}

void updateHeight(struct PageAVLNode* N) {
    if (N != NULL) {
        N->height = (getHeight(N->left) > getHeight(N->right) ? getHeight(N->left) : getHeight(N->right)) + 1;
    }
}

struct PageAVLNode* rightRotate(struct PageAVLNode* y) {
    struct PageAVLNode* x = y->left;
    struct PageAVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

struct PageAVLNode* leftRotate(struct PageAVLNode* x) {
    struct PageAVLNode* y = x->right;
    struct PageAVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

int getBalance(struct PageAVLNode* N) {
    return (N == NULL) ? 0 : getHeight(N->left) - getHeight(N->right);
}

struct PageAVLNode* insert(struct PageAVLNode* node, int page) {
    if (node == NULL) return createPageAVLNode(page);

    if (page < node->page) {
        node->left = insert(node->left, page);
    } else if (page > node->page) {
        node->right = insert(node->right, page);
    }

    updateHeight(node);

    int balance = getBalance(node);

    if (balance > 1 && page < node->left->page) {
        return rightRotate(node);
    }
    if (balance < -1 && page > node->right->page) {
        return leftRotate(node);
    }
    if (balance > 1 && page > node->left->page) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && page < node->right->page) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void insertPage(struct PageAVLTree* tree, int page) {
    tree->root = insert(tree->root, page);
}

void printInOrder(struct PageAVLNode* node) {
    if (node != NULL) {
        printInOrder(node->left);
        printf("%d ", node->page);
        printInOrder(node->right);
    }
}

void inOrder(struct PageAVLNode* node, void (*visit)(int)) {
    if (node != NULL) {
        inOrder(node->left, visit);
        visit(node->page);
        inOrder(node->right, visit);
    }
}