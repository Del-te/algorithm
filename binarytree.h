#ifndef BINATRY_TREE_H
#define BINATRY_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct TreeNode {
    struct TreeNode *leftPtr;  
    int data;                  
    struct TreeNode *rightPtr;
};

typedef struct TreeNode TreeNode;

void insertNode(TreeNode **treePtr, int value);
TreeNode *search_pre(TreeNode *treePtr, int value);
TreeNode *search_parent(TreeNode *treePtr_a, TreeNode *treePtr_b, int value);
void outputTree(TreeNode *treePtr, int spaces);
int countSize(TreeNode *treePtr);
// void deleteNode(TreeNode **treePtr, int value);
// TreeNode *binaryTreeSereach(TreeNode * const treePtr, int value);

#endif // !BINATRY_TREE_H