// 题意：输入n个单词，是否可以排成一个序列，使得每个单词的第一个字母和上一个单词的最后一个字母相同
// 算法：把字母看作结点，单词看成有向边，则有解当且仅当图中有欧拉路径。注意要先判连通
// dfs解法
#include <bits/stdc++.h>
using namespace std;

const int maxn = 30;

int G[maxn][maxn];
int in[maxn], out[maxn];
int n;
int vis[maxn];

void dfs(int u)
{ //判断是否通路
    for (int v = 0; v < 26; v++)
    {
        if (G[u][v] && !vis[v])
        {
            vis[v] = 1;
            dfs(v);
        }
    }
}

bool euler(int u)
{
    int i;
    for (i = 0; i < 26; i++)
    {
        if (G[u][i])
        {
            G[u][i]--;
            n--;
            if (!n && euler(i))
                return true;
        }
    }
    if (i == 26)
        return false;
}

bool cycle()
{
    int cnt = 0;
    for (int i = 0; i < 26; i++) // 共26个字母
    {
        if (in[i] || out[i])
            if (!vis[i])
            {
                vis[i] = 1;
                cnt++;
                dfs(i);
            }
    }
    if (cnt > 1) // 强连通
        return false;
    return true;
}

// 欧拉路性质, 主要是判断是否符合基本的欧拉路的基本性质
bool euler()
{
    int a = 0, b = 0;
    for (int i = 0; i < 26; i++)
    {
        if (in[i] - out[i] == 1)
        {
            a++;
            if (a > 1)
                return false;
        }
        else if (out[i] - in[i] == 1)
        {
            b++;
            if (b > 1)
                return false;
        }
        else if (in[i] != out[i])
            return false;
    }
    return true;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    cin >> T;
    while (T--)
    {
        memset(G, 0, sizeof(G));
        memset(in, 0, sizeof(in));
        memset(out, 0, sizeof(out));
        memset(vis, 0, sizeof(vis));
        string word;
        cin >> n;
        while (n--)
        {
            cin >> word;
            // 第一个字母
            int u = word[0] - 'a';
            // 最后一个字母
            int v = word[word.size() - 1] - 'a';
            in[u]++;
            out[v]++;
            G[u][v] = G[v][u] = 1;
        }
        if (cycle() && euler())
            printf("Ordering is possible.\n");
        else
            printf("The door cannot be opened.\n");
    }
    return 0;
}