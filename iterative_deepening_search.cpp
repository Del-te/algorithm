// 迭代加深搜索
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, maxh;
int a[1010];
bool dfs(int x, int cur)
{
    if (x << (maxh - cur) < n)
        return false; //乐观估计剪枝，当前深度到限制深度指数最多增长2^(maxh-cur)倍
    if (cur > maxh)
        return false; //达到限制深度
    a[cur] = x;
    if (x == n)
        return true;
    for (int i = 0; i <= cur; i++)
    {
        if (dfs(x + a[i], cur + 1))
            return true;
        if (dfs(x > a[i] ? x - a[i] : a[i] - x, cur + 1))
            return true;
    }
    return false;
}

int main()
{
    while (scanf("%d", &n) == 1 && n)
    {
        maxh = 0;
        memset(a, 0, sizeof(a));
        while (!dfs(1, 0))
        { //只要没找到答案就一直继续
            memset(a, 0, sizeof(a));
            maxh++; //增大深度限制
        }
        printf("%d\n", maxh); //最大深度就是答案
    }
    return 0;
}