// N皇后问题
#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 50;
int C[maxn], vis[3][maxn];
int N;
int count = 0;
void tracing_back(int cur)
{
    if (cur >= N)
    {
        count++;
    }
    else for (int i = 0; i < N; i++)
    {
        if (!vis[0][i] && !vis[1][cur + i] && !vis[2][cur - i + N])
        {
            vis[0][i] = vis[1][cur + i] = vis[2][cur - i + N] = 1;
            tracing_back(cur + 1); // 参数不要用自增运算符
            vis[0][i] = vis[1][cur + i] = vis[2][cur - i + N] = 0;
        }
    }
}
int main()
{
    int cur = 0;
    cin >> N;
    memset(vis, 0, sizeof(vis));
    tracing_back(cur);
    cout << count << endl;
    system("pause");
    return 0;
}
