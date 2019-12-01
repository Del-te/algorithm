// 用数组实现二叉树
#include <iostream>
#include <vector>
#define type int
using namespace std;

vector<type> list;
vector<type> node;
vector<int> lch;
vector<int> rch;
int current = -1;

void create(type root)
{
    if (node.size() == 0)
    {
        node.push_back(root);
        lch.push_back(-1);
        rch.push_back(-1);
        current = 0;
    }
}

void add(type e)
{
    if (lch[current] == -1 && rch[current] == -1)
    {
        node.push_back(e);
        lch.push_back(-1);
        rch.push_back(-1);
        lch[current] = node.size() - 1;
    }
    else if (rch[current] == -1 && lch[current] != -1)
    {
        node.push_back(e);
        lch.push_back(-1);
        rch.push_back(-1);
        rch[current] = node.size() - 1;
    }
    if (lch[current] != -1 && rch[current] != -1)
        current++;
}

void postOrder(int index)
{
    if (index == -1)
    {
        return;
    }
    postOrder(lch[index]);
    postOrder(rch[index]);
    cout << node[index] << " ";
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        list.push_back(t);
    }
    create(list[0]);
    for (int i = 1; i < n; i++)
    {
        add(list[i]);
    }
    postOrder(0);
    system("pause");
    return 0;
}
