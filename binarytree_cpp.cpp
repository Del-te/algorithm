#define _CRT_SECURE_NO_WARNINGS 1

#include "binarytree_cpp.h"
#include <iostream>
using namespace std;

void FunTest1()
{
    char arr1[] = { 'A', 'B', 'D', '#', 'G', '#', '#', '#', 'C', 'E', '#', '#', 'F' };
    BinaryTree<char> bt1(arr1, sizeof(arr1) / sizeof(arr1[0]), '#');
    bt1.PreOrder();
    bt1.InOrder();
    bt1.PostOrder();
    bt1.LevelOrder();
    cout << bt1.Size() << endl;
    cout << bt1.LeafSize() << endl;
    cout << bt1.KSize(3) << endl;
    cout << bt1.Height() << endl;
    cout << bt1.KSize(4) << endl;

    BinaryTreeNode<char>* ret1 = bt1.Find('B');
    BinaryTreeNode<char>* ret2 = bt1.FindParent(ret1);
    BinaryTreeNode<char>* ret3 = bt1.FindLeftChild(ret1);
    BinaryTreeNode<char>* ret4 = bt1.FindRightChild(ret1);
    bt1.PreOrderNoR();
    bt1.InOrderNoR();
    bt1.PostOrderNoR();
}

int main()
{
    FunTest1();
    system("pause");
    return 0;
}