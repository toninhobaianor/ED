// avlTree.c

#include "avlTree.h"
#include <stdio.h>
#include <stdlib.h>

struct AVLNode* createAVLNode(const char* w, int page) {
    struct AVLNode* newNode = (struct AVLNode*)malloc(sizeof(struct AVLNode));
    newNode->word = strdup(w);
    newNode->height = 1;
    newNode->left = newNode->right = NULL;
    newNode->pagesTree = createPageAVLTree();
    insertPage(newNode->pagesTree, page);
    return newNode;
}

struct AVLTree* createAVLTree() {
    struct AVLTree* newTree = (struct AVLTree*)malloc(sizeof(struct AVLTree));
    newTree->root = NULL;
    return newTree;
}

void freeAVLTree(struct AVLNode* node) {
    if (node != NULL) {
        freeAVLTree(node->left);
        freeAVLTree(node->right);
        freePageAVLTree(node->pagesTree->root);
        free(node->pagesTree);
        free(node->word);
        free(node);
    }
}

int getHeightAVL(struct AVLNode* N) {
    return (N == NULL) ? 0 : N->height;
}

void updateHeightAVL(struct AVLNode* N) {
    if (N != NULL) {
        N->height = (getHeightAVL(N->left) > getHeightAVL(N->right) ? getHeightAVL(N->left) : getHeightAVL(N->right)) + 1;
    }
}

struct AVLNode* rightRotateAVL(struct AVLNode* y) {
    struct AVLNode* x = y->left;
    struct AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeightAVL(y);
    updateHeightAVL(x);

    return x;
}

struct AVLNode* leftRotateAVL(struct AVLNode* x) {
    struct AVLNode* y = x->right;
    struct AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeightAVL(x);
    updateHeightAVL(y);

    return y;
}

int getBalanceAVL(struct AVLNode* N) {
    return (N == NULL) ? 0 : getHeightAVL(N->left) - getHeightAVL(N->right);
}

struct AVLNode* insertAVL(struct AVLNode* node, const char* word, int page) {
    if (node == NULL) {
        return createAVLNode(word, page);
    }

    int compareResult = strcmp(word, node->word);

    if (compareResult < 0) {
        node->left = insertAVL(node->left, word, page);
    } else if (compareResult > 0) {
        node->right = insertAVL(node->right, word, page);
    } else {
        insertPage(node->pagesTree, page);
        return node;
    }

    updateHeightAVL(node);

    int balance = getBalanceAVL(node);

    // Left Left Case
    if (balance > 1 && compareResult < 0) {
        return rightRotateAVL(node);
    }

    // Right Right Case
    if (balance < -1 && compareResult > 0) {
        return leftRotateAVL(node);
    }

    // Left Right Case
    if (balance > 1 && compareResult > 0) {
        node->left = leftRotateAVL(node->left);
        return rightRotateAVL(node);
    }

    // Right Left Case
    if (balance < -1 && compareResult < 0) {
        node->right = rightRotateAVL(node->right);
        return leftRotateAVL(node);
    }

    return node;
}

void insertAVLNode(struct AVLTree* tree, const char* word, int page) {
    tree->root = insertAVL(tree->root, word, page);
}

void printInOrderAVL(struct AVLNode* node) {
    if (node != NULL) {
        printInOrderAVL(node->left);
        printf("%s: ", node->word);
        inOrder(node->pagesTree->root, &printInOrder);
        printf("\n");
        printInOrderAVL(node->right);
    }
}

void inOrderAVL(struct AVLNode* node, void (visit)(const char, int)) {
    if (node != NULL) {
        inOrderAVL(node->left, visit);
        visit(node->word, node->pagesTree->root->page);
        inOrderAVL(node->right, visit);
    }
}