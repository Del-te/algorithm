// N皇后问题
#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 50;
int vis[3][maxn]; // 数组大小要管够
int N;
int count = 0;
void tracing_back(int cur)
{
    // 要把0到7行全判断完才能算一个解
    if (cur >= N)
    {
        count++;
    }
    else for (int i = 0; i < N; i++)
    {
        // 先判断有没有走过，再进行操作
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
    // 从第0行开始
    tracing_back(cur);
    cout << count << endl;
    system("pause");
    return 0;
}
