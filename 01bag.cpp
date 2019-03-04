#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 100;
int dp[maxn + 1][maxn + 1];
int n;
int w;
int W[maxn], V[maxn];
int rec(int i, int j)
{
    if (dp[i][j] > 0) 
    {
        // 已经计算过的话，直接使用前面的值
        return dp[i][j];
    }
    int res;
    if (i == n) 
    {
        res = 0;
    }
    else if (j < W[i])
    {
        res = rec(i + 1, j);
    }
    else
    {
        res = max(rec(i + 1, j), rec(i + 1, j - W[i]) + V[i]);
    }
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
    memset(dp, -1, sizeof(dp));    
    cout << rec(0, w) << endl;
    system("pause");
    return 0;
}
