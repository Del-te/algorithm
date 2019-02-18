// 题意：输入一个字符矩阵，统计字符@组成多少个八连块
#include <cstdio>
#include <cstring>
const int maxn = 100 + 5;

char pic[maxn][maxn]; // 读入的字符矩阵
int m, n, idx[maxn][maxn];  // 行 列  标记矩阵

void dfs(int r, int c, int id)
{
    if (r < 0 || r >= m || c < 0 || c >= n) // 避免越界
        return;
    if (idx[r][c] > 0 || pic[r][c] != '@') // 如果已经标记过了 或 不是@
        return;
    // 连通分量编号
    idx[r][c] = id; 
    for (int dr = -1; dr <= 1; dr++) // dfs周围八个方向
        for (int dc = -1; dc <= 1; dc++)
            if (dr != 0 || dc != 0)
                dfs(r + dr, c + dc, id);
}

int main()
{
    while (scanf("%d%d", &m, &n) == 2 && m && n) // m行n列
    {
        // 读入字符矩阵
        for (int i = 0; i < m; i++)
            scanf("%s", pic[i]);
        // 标记矩阵初始化
        memset(idx, 0, sizeof(idx));
        // 连通块个数
        int cnt = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (idx[i][j] == 0 && pic[i][j] == '@') // 如果没被标记过并且是@
                    dfs(i, j, ++cnt);
        printf("%d\n", cnt);
    }
    return 0;
}