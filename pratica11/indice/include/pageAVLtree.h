// pageAVLTree.h

#ifndef PAGE_AVL_TREE_H
#define PAGE_AVL_TREE_H

struct PageAVLNode {
    int page;
    int height;
    struct PageAVLNode* left;
    struct PageAVLNode* right;
};

struct PageAVLTree {
    struct PageAVLNode* root;
};

struct PageAVLNode* createPageAVLNode(int p);
struct PageAVLTree* createPageAVLTree();
void freePageAVLTree(struct PageAVLNode* node);
int getHeight(struct PageAVLNode* N);
void updateHeight(struct PageAVLNode* N);
struct PageAVLNode* rightRotate(struct PageAVLNode* y);
struct PageAVLNode* leftRotate(struct PageAVLNode* x);
int getBalance(struct PageAVLNode* N);
struct PageAVLNode* insert(struct PageAVLNode* node, int page);
void insertPage(struct PageAVLTree* tree, int page);
void printInOrder(struct PageAVLNode* node);
void inOrder(struct PageAVLNode* node, void (*visit)(int));

#endif // PAGE_AVL_TREE_H