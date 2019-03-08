#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 50;
int ans[maxn]; // 结果数组
int vis[maxn]; // 访问标记数组
int isp[maxn]; // 素数数组，方便计算
int n;
int is_prime(int x)
{
    // 注意是i * i <= x，从2开始
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
void display()
{
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
        {
            cout << ' ';
        }
        cout << ans[i];
    }
    cout << endl;
}
void dfs(int cur)
{
    // 递归边界
    // 判断头尾相加是否为素数
    if (cur == n && isp[ans[0] + ans[n - 1]])
    {
        display();
        return;
    }
    // 注意循环上下限
    for (int i = 2; i <= n; i++)
    {
        // 如果i没有用过，并且与前一个数之和为素数
        if (!vis[i] && isp[i + ans[cur - 1]])
        {
            ans[cur] = i;
            vis[i] = 1;
            dfs(cur + 1);
            vis[i] = 0; // 撤销的是标记操作
        }
    }
}
int main()
{
    cin >> n;
    memset(vis, 0, sizeof(vis));
    for (int i = 2; i <= n*2; i++)
    {
        isp[i] = is_prime(i);
    }
    ans[0] = 1;
    dfs(1);
    system("pause");
    return 0;
}
