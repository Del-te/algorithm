// 题意：输入n和m，以及m个二元组(i,j)，求1~n的一个排列使得对于每个(i,j)，i在j的前面
// 算法：拓扑排序。注意m可能等于0
#include <cstdio>
#include <cstring>
const int maxn = 1000;
// g[i][j]表示i要先于j
// m表示关系数量，n表示有多少个任务
// flag是标记数组，0表示未访问，-1表示正在访问，1表示已经访问
// topo是拓扑序列结果
int n, m, G[maxn][maxn], flag[maxn], topo[maxn], t;
bool dfs(int u)
{
  // -1表示正在访问
  flag[u] = -1;
  for (int v = 0; v < n; v++)
    if (G[u][v])
    {
      if (flag[v] < 0)
        return false;
      else if (!flag[v])
        dfs(v);
    }
  // 1表示访问过了
  flag[u] = 1;
  topo[--t] = u;
  return true;
}

bool toposort()
{
  t = n;
  // 标记数组初始化
  memset(flag, 0, sizeof(flag));
  for (int u = 0; u < n; u++)
    if (!flag[u]) // 如果未被访问过
      if (!dfs(u))
        return false;
  return true;
}

int main()
{
  while (scanf("%d%d", &n, &m) == 2 && n)
  {
    memset(G, 0, sizeof(G));
    for (int i = 0; i < m; i++)
    {
      // 二元组
      int u, v;
      scanf("%d%d", &u, &v);
      u--;
      v--;
      //因为题意是从1开始的节点，所以存储进去的时候必须减一
      G[u][v] = 1;
      // 表示u偏序v关系成立
    }
    if (toposort())
    {
      for (int i = 0; i < n - 1; i++)
        printf("%d ", topo[i] + 1);
      printf("%d\n", topo[n - 1] + 1);
    }
    else
      printf("No\n"); // 题目没说无解输出什么，应该是保证有解吧
  }
}