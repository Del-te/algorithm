#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

#include <iostream>
using namespace std;
#include <stdlib.h>
#include <queue>
#include <stack>

//二叉树节点
template <class T>
struct BinaryTreeNode
{
    BinaryTreeNode(const T& data)
    :_pLeft(NULL)
    , _pRight(NULL)
    , _data(data)
    {}

    BinaryTreeNode<T>* _pLeft;//左子树
    BinaryTreeNode<T>* _pRight;//右子树
    T _data;//数据
};

//二叉树
template<class T>
class BinaryTree
{
    typedef BinaryTreeNode<T>* pNode;
    typedef BinaryTreeNode<T> Node;
public:
    //无参构造函数
    BinaryTree()
        : _pRoot(NULL)
    {}
    //带参数的构造函数
    BinaryTree(T* arr, size_t size, const T& invalid)
    {
        size_t index = 0;
        _CreateBinaryTree(_pRoot, arr, size, index, invalid);
    }
    //拷贝构造函数
    BinaryTree(const BinaryTree<T>& bt)
    {
        _pRoot = _CopyBinaryTree(bt._pRoot);
    }
    //赋值运算符重载(两种方式均可)
    //BinaryTree& operator=(const BinaryTree<T>& bt)
    //{
    //  if (this != &bt)
    //  {
    //      _DestoryBinaryTree(_pRoot);
    //      _pRoot = _CopyBinaryTree(bt._pRoot);
    //  }
    //  return *this;
    //}
    BinaryTree& operator=(const BinaryTree<T>& bt)
    {
        swap(_pRoot, bt._pRoot);
        return *this;
    }
    //析构函数
    ~BinaryTree()
    {
        _DestoryBinaryTree(_pRoot);
    }
    //递归前序遍历
    void PreOrder()
    {
        _PreOrder(_pRoot);
        cout << endl;
    }
    //递归中序遍历
    void InOrder()
    {
        _InOrder(_pRoot);
        cout << endl;
    }
    //递归后序遍历
    void PostOrder()
    {
        _PostOrder(_pRoot);
        cout << endl;
    }
    //层序遍历(用队列)
    void LevelOrder()
    {
        queue<pNode> q;
        if (_pRoot)
            q.push(_pRoot);
        while (!q.empty())
        {
            pNode cur = q.front();
            q.pop();
            cout << cur->_data << " ";
            if (cur->_pLeft)
            {
                q.push(cur->_pLeft);
            }
            if (cur->_pRight)
            {
                q.push(cur->_pRight);
            }
        }
        cout << endl;
    }
    //非递归前序遍历
    void PreOrderNoR()
    {
        _PreOrderNoR2(_pRoot);
    }
    //非递归中序遍历
    void InOrderNoR()
    {
        _InOrderNoR(_pRoot);
    }
    //非递归后序遍历
    void PostOrderNoR()
    {
        _PostOrderNoR(_pRoot);
    }
    //二叉树节点个数
    size_t Size()
    {
        return _Size(_pRoot);
    }
    //二叉树叶子节点个数
    size_t LeafSize()
    {
        return _LeafSize(_pRoot);
    }
    //二叉树第K层节点个数
    size_t KSize(size_t k)
    {
        return _KSize(_pRoot, k);
    }
    //二叉树高度
    size_t Height()
    {
        return _Height(_pRoot);
    }
    //寻找二叉树中的节点
    pNode Find(const T& data)
    {
        return _Find(_pRoot, data);
    }
    //寻找某节点的双亲节点
    pNode FindParent(pNode node)
    {
        return _FindParent(_pRoot, node);
    }
    //寻找某节点的左孩子节点
    pNode FindLeftChild(pNode node)
    {
        return _FindLeftChild(_pRoot, node);
    }
    //寻找某节点的右孩子节点
    pNode FindRightChild(pNode node)
    {
        return _FindRightChild(_pRoot, node);
    }

//封装函数
private:
    //创建二叉树(前序遍历)
    void _CreateBinaryTree(pNode& pRoot, T* arr, size_t size, size_t& index, const T& invalid)
    {
        if (index < size&&invalid != arr[index])
        {
            pNode pNewNode = new Node(arr[index]);
            _CreateBinaryTree(pNewNode->_pLeft, arr, size, ++index, invalid);
            _CreateBinaryTree(pNewNode->_pRight, arr, size, ++index, invalid);
            pRoot = pNewNode;
        }
    }
    //拷贝二叉树
    pNode _CopyBinaryTree(pNode pRoot)
    {
        if (pRoot == NULL);
        {
            return NULL;
        }
        pNode tmp = new Node(pRoot->_data);
        tmp->_pLeft = _CopyBinaryTree(pRoot->_pLeft);
        tmp->_pRight = _CopyBinaryTree(pRoot->_pRight);
        return tmp;
    }
    //递归前序遍历
    void _PreOrder(pNode pRoot)
    {
        if (pRoot)
        {
            cout << pRoot->_data << " ";
            _PreOrder(pRoot->_pLeft);
            _PreOrder(pRoot->_pRight);
        }
    }
    //递归中序遍历
    void _InOrder(pNode pRoot)
    {
        if (pRoot)
        {
            _InOrder(pRoot->_pLeft);
            cout << pRoot->_data << " ";
            _InOrder(pRoot->_pRight);
        }
    }
    //递归后序遍历
    void _PostOrder(pNode pRoot)
    {
        if (pRoot)
        {
            _PostOrder(pRoot->_pLeft);
            _PostOrder(pRoot->_pRight);
            cout << pRoot->_data << " ";
        }
    }
    //非递归前序遍历
    //方法一：访问根之后直接访问左子树访问完
    void _PreOrderNoR(pNode pRoot)
    {
        stack<pNode> s;
        pNode cur = pRoot;
        while (cur || !s.empty())
        {   
            while (cur)
            {
                cout << cur->_data << " ";
                s.push(cur);
                cur = cur->_pLeft;
            }//此时左子树遍历完
            //取栈顶元素访问右子树(此时栈顶元素已经访问)
            pNode top = s.top();
            s.pop();
            //子问题
            cur = top->_pRight;
        }
        cout << endl;
    }
    //方法二：
    void _PreOrderNoR2(pNode pRoot)
    {
        if (pRoot == NULL)
            return;
        stack<pNode> s;
        s.push(pRoot);//根节点入栈
        while (!s.empty())
        {
            pNode top = s.top();
            cout << top->_data << " ";
            s.pop();
            if (top->_pRight)//先压右子树
                s.push(top->_pRight);
            if (top->_pLeft)//再压左子树
                s.push(top->_pLeft);
        }
        cout << endl;
    }
    //非递归中序遍历
    void _InOrderNoR(pNode pRoot)
    {
        stack<pNode> s;
        pNode cur = pRoot;
        while (cur || !s.empty())
        {
            while (cur)
            {
                s.push(cur);
                cur = cur->_pLeft;
            }//直到最左节点
            //取栈顶元素访问该元素并访问右子树
            pNode top = s.top();
            cout << top->_data << " ";
            s.pop();
            //子问题
            cur = top->_pRight;
        }
        cout << endl;
    }
    //非递归后序遍历
    void _PostOrderNoR(pNode pRoot)
    {
        stack<pNode> s;
        pNode cur = pRoot;
        pNode prev = NULL;//标记最近访问过的节点
        while (cur || !s.empty())
        {
            while (cur)
            {
                s.push(cur);
                cur = cur->_pLeft;
            }//直到最左节点

            pNode top = s.top();//取栈顶元素
            if (top->_pRight == NULL || top->_pRight == prev)//判断该节点的右子树是否为空
            {                                                //再判断是不是第一次在栈顶取到该元素 
                cout << top->_data << " ";
                prev = top;
                s.pop();
            }
            else//不为空，访问右子树
            {
                cur = top->_pRight;
            }
        }
        cout << endl;
    }
    //后序遍历递归销毁二叉树
    void _DestoryBinaryTree(pNode pRoot)
    {
        if (pRoot)
            return;
        _DestoryBinaryTree(pRoot->_pLeft);
        _DestoryBinaryTree(pRoot->_pRight);
        delete pRoot;
        pRoot = NULL;
    }
    //求节点个数
    size_t _Size(pNode pRoot)
    {
        if (!pRoot)
        {
            return 0;
        }
        return _Size(pRoot->_pLeft) + _Size(pRoot->_pRight) + 1;
    }
    //求叶子节点个数
    size_t _LeafSize(pNode pRoot)
    {
        if (!pRoot)
            return 0;
        if (pRoot->_pLeft == NULL && pRoot->_pRight == NULL)
            return 1;
        return _LeafSize(pRoot->_pLeft) + _LeafSize(pRoot->_pRight);
    }
    //求第K层节点的个数
    size_t _KSize(pNode pRoot, size_t k)
    {
        if (pRoot == NULL)
            return 0;
        if (k == 1)
            return 1;
        return _KSize(pRoot->_pLeft, k - 1) + _KSize(pRoot->_pRight, k - 1);
    }
    //求二叉树高度
    size_t _Height(pNode pRoot)
    {
        if (!pRoot)
            return 0;
        if (pRoot->_pLeft == NULL&&pRoot->_pRight == NULL)
            return 1;
        size_t LeftHeight = _Height(pRoot->_pLeft);
        size_t RightHeight = _Height(pRoot->_pRight);
        return LeftHeight > RightHeight ? LeftHeight + 1 : RightHeight + 1;
    }
    //找二叉树中的节点
    pNode _Find(pNode pRoot, const T& data)
    {
        if (pRoot == NULL)
            return NULL;
        if (pRoot->_data == data)
            return pRoot;
        pNode ret = NULL;
        ret = _Find(pRoot->_pLeft, data);
        if (ret)
            return ret;
        return _Find(pRoot->_pRight, data);
    }
    //找二叉树中节点的双亲节点
    pNode _FindParent(pNode pRoot, pNode node)
    {
        //树为空树   寻找的节点为空节点   寻找的节点是根节点(无双亲节点)
        if (pRoot == NULL || node == NULL || pRoot == node)
        {
            return NULL;
        }
        if (node == pRoot->_pLeft || node == pRoot->_pRight)
            return pRoot;
        if (pRoot->_pLeft)
            return _FindParent(pRoot->_pLeft, node);
        return _FindParent(pRoot->_pRight, node);
    }
    //寻找节点的左孩子
    pNode _FindLeftChild(pNode pRoot, pNode node)
    {
        if (node == NULL || pRoot == NULL)
        {
            return NULL;
        }
        pNode cur = _Find(pRoot, node->_data);
        return cur->_pLeft;
    }
    //寻找节点的右孩子
    pNode _FindRightChild(pNode pRoot, pNode node)
    {
        if (node == NULL || pRoot == NULL)
        {
            return NULL;
        }
        pNode cur = _Find(pRoot, node->_data);
        return cur->_pRight;
    }

private:
    pNode _pRoot;
};