#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 100;
int dp[maxn + 1][maxn + 1]; // 记忆数组
int n; // 一共几个物品
int w; // 背包限重
int W[maxn], V[maxn]; // W[i]是第i个物品的重量，V[i]是第i个物品的价值
// 从第i个物品开始挑选总重小于j的部分
int rec(int i, int j)
{
    if (dp[i][j] > 0) 
    {
        // 已经计算过的话，直接使用前面的值
        return dp[i][j];
    }
    int res;
    // 递归边界
    if (i == n) 
    {
        res = 0;
    }
    // 如果无法选择第i个物品
    else if (j < W[i])
    {
        // 尝试挑选下一个物品
        res = rec(i + 1, j);
    }
    // 选择和没选择两种都试一下
    else
    {
        // 选择价值最大的一个分支
        res = max(rec(i + 1, j), rec(i + 1, j - W[i]) + V[i]);
    }
    // 将计算结果放到记忆数组并返回
    return (dp[i][j] = res);
}
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> W[i] >> V[i];
    }
    cin >> w;
    // 将记忆数组初始化
    memset(dp, -1, sizeof(dp));  
    // 从第0个物品，总重为w开始  
    cout << rec(0, w) << endl;
    system("pause");
    return 0;
}
// 动态规划常常适用于有重叠子问题和最优子结构性质的问题，动态规划方法所耗时间往往远少于朴素解法。
// 动态规划背后的基本思想非常简单。大致上，若要解一个给定问题，我们需要解其不同部分（即子问题），再合并子问题的解以得出原问题的解。
// 通常许多子问题非常相似，为此动态规划法试图仅仅解决每个子问题一次，从而减少计算量：一旦某个给定子问题的解已经算出，则将其记忆化
// 存储，以便下次需要同一个子问题解之时直接查表。这种做法在重复子问题的数目关于输入的规模呈指数增速时特别有用。
// https://blog.csdn.net/jushang0235/article/details/78841915