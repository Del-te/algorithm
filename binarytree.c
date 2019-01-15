#include "binarytree.h"
#include <stdio.h>
#include <stdlib.h>
// #include <time.h>
int main()
{
    int arr[] = {2, 4, 1, 5, 3, 7, 6, 8};
    int in;                   // input and result
    int i;                    /* loop counter */
    int item;                 /* value to deal with */
    int totalSpaces = 0;      /* spaces preceding output */
    TreeNode *rootPtr = NULL; /* points to the tree root */
    TreeNode *temp = NULL;    // temp pointer
    // srand(time(NULL)); /* randomize */
    printf("The numbers being placed in the tree are:\n\n");
    for (i = 0; i < sizeof(arr) / sizeof(int); i++)
    {
        item = arr[i];
        printf("%3d", item);
        insertNode(&rootPtr, item);
    }
    printf("\n\n\nnow the tree is:\n\n");
    if (rootPtr == NULL)
        printf("empty tree\n");
    else
        outputTree(rootPtr, totalSpaces);

    printf("\n\ntree size : %d\n", countSize(rootPtr));

    printf("please input the value which you wanto search:");
    scanf("%d", &in);
    if((temp = search_pre(rootPtr, in)) != NULL)
        printf("pre-search: %d\n", temp->data);
    else printf("%d is not found!\n", in);
    
    printf("please input the value which you wanto search its parent:");
    scanf("%d", &in);
    if((temp = search_parent(NULL, rootPtr, in)) != NULL)
        printf("%d's parent: %d\n", in, temp->data);
    else printf("%d is root!\n", in);
    // random delete Nodes, then output the tree
    // while (rootPtr != NULL)
    // {
    //     item = rand() % (sizeof(arr) / sizeof(int));
    //     printf("\n\nafter delete %d:\n\n", arr[item]);
    //     deleteNode(&rootPtr, arr[item]);

    //     if (rootPtr == NULL)
    //         printf("empty tree\n");
    //     else
    //         outputTree(rootPtr, totalSpaces);
    // }
    system("pause");
    return 0;
}
int countSize(TreeNode *treePtr)
{
    static int count = 0;
    if (treePtr != NULL)
    {
        count++;
        if (treePtr->leftPtr != NULL)
            countSize(treePtr->leftPtr);
        if (treePtr->rightPtr != NULL)
            countSize(treePtr->rightPtr);
    }
    return count;
}
TreeNode *search_pre(TreeNode *treePtr, int value)
{
    /*先序查找*/
    TreeNode *temp;
    if (treePtr == NULL)
        return NULL;
    if (value == treePtr->data)
        return treePtr;
    temp = search_pre(treePtr->leftPtr, value);
    if (temp != NULL)
        return temp;
    else
        return search_pre(treePtr->rightPtr, value);
}

void insertNode(TreeNode **treePtr, int value)
{
    /* if treePtr is NULL */
    if (*treePtr == NULL)
    {
        *treePtr = (TreeNode *)malloc(sizeof(TreeNode));
        if (*treePtr != NULL)
        {
            (*treePtr)->data = value;
            (*treePtr)->leftPtr = NULL;
            (*treePtr)->rightPtr = NULL;
        }
        else printf("%d not inserted. No memory available.\n", value);
    }
    else{
        /* insert node in left subtree */
        // 如果小于根节点键值，则插入根节点的左子树，
        if (value < (*treePtr)->data)
            insertNode(&((*treePtr)->leftPtr), value);
        else
        {
            // 如果大于根节点的键值，则插入根节点的右子树，
            /* insert node in right subtree */
            if (value > (*treePtr)->data)
                insertNode(&((*treePtr)->rightPtr), value);
            else
                printf("dup");
        }
    }
}

void outputTree(TreeNode *treePtr, int spaces)
{
    int loop;
    while (treePtr != NULL)
    {
        outputTree(treePtr->rightPtr, spaces + 4);
        for (loop = 1; loop <= spaces; loop++)
            printf(" ");
        printf("%d\n", treePtr->data);
        outputTree(treePtr->leftPtr, spaces + 4);
        treePtr = NULL;
    }
}

TreeNode *search_parent(TreeNode *treePtr_a, TreeNode *treePtr_b, int value)
{
    TreeNode *temp;
    if (treePtr_b == NULL)
        return NULL;
    if (value == treePtr_b->data)
        return treePtr_a;
    temp = search_parent(treePtr_b, treePtr_b->leftPtr, value);
    if (temp != NULL)
        return temp;
    else
        return search_parent(treePtr_b, treePtr_b->rightPtr, value);
}

// TreeNode *binaryTreeSereach(TreeNode *const treePtr, int value)
// {
//     TreeNode *tempPtr = treePtr;
//     while (tempPtr != NULL && tempPtr->data != value)
//     {
//         // 若相等，则返回指向该节点的指针，
//         // 若查找的键值比它大，则从根节点的右子树开始查找，
//         // 若查找的键值比它小，则从根节点的左子树开始查找。
//         if (value > tempPtr->data)
//             tempPtr = tempPtr->rightPtr;
//         else
//             tempPtr = tempPtr->leftPtr;
//     }
//     return tempPtr;
// }

// void deleteNode(TreeNode **treePtrP, int value)
// {
//     TreeNode *deleteNodePtr = *treePtrP;
//     TreeNode *parentNodeOfDeletePtr = NULL;
//     TreeNode *substituteNodePtr;
//     TreeNode *parentNodeOfSubstitutePtr;
//     //find deleNode and its parentNode
//     while (deleteNodePtr != NULL && value != deleteNodePtr->data)
//     {
//         parentNodeOfDeletePtr = deleteNodePtr;

//         if (deleteNodePtr->data > value)
//         {
//             deleteNodePtr = deleteNodePtr->leftPtr;
//         }
//         else
//         {
//             deleteNodePtr = deleteNodePtr->rightPtr;
//         }
//     }
//     //case that can't find such Node
//     if (deleteNodePtr == NULL)
//     {
//         printf("no such Node, delete fail\n\n");
//         return;
//     }
//     //delete a leafNode
//     if (deleteNodePtr->leftPtr == NULL && deleteNodePtr->rightPtr == NULL)
//     {
//         //delete Node is root
//         if (parentNodeOfDeletePtr == NULL)
//         {
//             *treePtrP = NULL;
//         }
//         else if (parentNodeOfDeletePtr->leftPtr == deleteNodePtr)
//         {
//             parentNodeOfDeletePtr->leftPtr = NULL;
//         }
//         else
//         {
//             parentNodeOfDeletePtr->rightPtr = NULL;
//         }
//     }
//     //delete a Node which has a left child Node
//     else if (deleteNodePtr->leftPtr != NULL && deleteNodePtr->rightPtr == NULL)
//     {
//         //delete Node is root
//         if (parentNodeOfDeletePtr == NULL)
//         {
//             *treePtrP = deleteNodePtr->leftPtr;
//         }
//         else if (parentNodeOfDeletePtr->rightPtr == deleteNodePtr)
//             parentNodeOfDeletePtr->rightPtr = deleteNodePtr->leftPtr;
//         else
//             parentNodeOfDeletePtr->leftPtr = deleteNodePtr->leftPtr;
//     }

//     //delete a Node which has a right child Node
//     else if (deleteNodePtr->leftPtr == NULL && deleteNodePtr->rightPtr != NULL)
//     {
//         //delete Node is root
//         if (parentNodeOfDeletePtr == NULL)
//         {
//             *treePtrP = deleteNodePtr->rightPtr;
//         }
//         else if (parentNodeOfDeletePtr->rightPtr == deleteNodePtr)
//             parentNodeOfDeletePtr->rightPtr = deleteNodePtr->rightPtr;
//         else
//             parentNodeOfDeletePtr->leftPtr = deleteNodePtr->rightPtr;
//     }
//     //delete a Node which has a left and a right child Node
//     else
//     {
//         parentNodeOfSubstitutePtr = deleteNodePtr;
//         substituteNodePtr = deleteNodePtr->leftPtr;
//         //search down and right to find substituteNode and its parentNode
//         while (substituteNodePtr->rightPtr != NULL)
//         {
//             parentNodeOfSubstitutePtr = substituteNodePtr;
//             substituteNodePtr = substituteNodePtr->rightPtr;
//         }
//         //delete Node is root
//         if (parentNodeOfDeletePtr == NULL)
//         {
//             *treePtrP = substituteNodePtr;
//         }
//         else if (parentNodeOfDeletePtr->leftPtr == deleteNodePtr)
//         {
//             parentNodeOfDeletePtr->leftPtr = substituteNodePtr;
//         }
//         else
//         {
//             parentNodeOfDeletePtr->rightPtr = substituteNodePtr;
//         }
//         substituteNodePtr->rightPtr = deleteNodePtr->rightPtr;
//         if (parentNodeOfSubstitutePtr != deleteNodePtr)
//         {
//             substituteNodePtr->leftPtr = deleteNodePtr->leftPtr;

//             if (parentNodeOfSubstitutePtr->leftPtr == substituteNodePtr)
//             {
//                 parentNodeOfSubstitutePtr->leftPtr = substituteNodePtr->leftPtr;
//             }
//             else
//             {
//                 parentNodeOfSubstitutePtr->rightPtr = substituteNodePtr->leftPtr;
//             }
//         }
//     }
//     free(deleteNodePtr);
// }