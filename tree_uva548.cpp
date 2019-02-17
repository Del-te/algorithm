// 题意：给一棵点带权（权各不相同，都是正整数）二叉树的中序和后序遍历，找一个叶子使得它到根的路径上的权和最小。如果有多解，该叶子本身的权应尽量小
// 算法：递归建树，然后DFS。注意，直接递归求结果也可以，但是先建树的方法不仅直观，而且更好调试
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

// 因为各个结点的权值各不相同且都是正整数，直接用权值作为结点编号
const int maxv = 10000 + 10;
int in_order[maxv], post_order[maxv], lch[maxv], rch[maxv];
int n;

bool read_list(int *a)
{
    string line;
    if (!getline(cin, line))
        return false;
    stringstream ss(line);
    n = 0;
    int x;
    while (ss >> x)
        a[n++] = x;
    return n > 0;
}

// 把in_order[L1..R1]和post_order[L2..R2]建成一棵二叉树，返回树根
int build(int L1, int R1, int L2, int R2)
{
    // 递归出口
    if (L1 > R1)
        return 0; // 空树
    // 后序遍历最后一个就是根节点
    int root = post_order[R2];
    // 先根据后序遍历最后一个节点就是根节点找到根节点
    int p = L1;
    while (in_order[p] != root)
        p++;
    // 中序遍历根节点左边的都在左子树，右边的都在右子树
    // cnt是左子树的结点个数
    int cnt = p - L1; 
    // 递归建树
    // L1到p-1是中序序列里的左子树节点，L2到L2+cnt-1是后序序列里的左子树节点
    lch[root] = build(L1, p - 1, L2, L2 + cnt - 1); // p指向的是根节点，因为是角标所以要减1
    // p+1到r1是后序序列里的右子树节点，L2+cnt到R2-1是后序序列里的右子树节点
    rch[root] = build(p + 1, R1, L2 + cnt, R2 - 1);
    return root;
}

int best, best_sum; // 目前为止的最优解和对应的权和

void dfs(int u, int sum)
{
    sum += u;
    if (!lch[u] && !rch[u])
    { // 叶子
        if (sum < best_sum || (sum == best_sum && u < best))
        {
            best = u;
            best_sum = sum;
        }
    }
    // 递归搜索
    if (lch[u])
        dfs(lch[u], sum);
    if (rch[u])
        dfs(rch[u], sum);
}

int main()
{
    while (read_list(in_order)) // 读取中序序列
    {
        // 读取后序序列
        read_list(post_order);
        // 建树
        build(0, n - 1, 0, n - 1);
        // 变量初始化 
        best_sum = 1000000000;
        // 深度优先搜索
        dfs(post_order[n - 1], 0);
        cout << best << "\n";
    }
    return 0;
}