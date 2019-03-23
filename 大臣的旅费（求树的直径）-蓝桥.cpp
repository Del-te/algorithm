// 求树直径原理：以任意点w开始，先做一次DFS（BFS），
// 找到最远点v，然后以此点v，进行一次DFS（BFS），
// 找到最远点u，u到v就是树的直径，记做d(u,v)。

// 此做法依然无法通过巨量数据
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 1000;
int g[maxn][maxn];
int vis[maxn][maxn];
long ans = 0;
long w = 0; 

void dfs(int i, int j, int cnt, int n)
{
	if(g[i][j] == 0 || vis[i][j] == 1)
	{
		for(int index = 1; index <= cnt; index++)
		{
			w += index + 10;
		}
		ans = max(w, ans);
		w = 0;
		return;
	}
	for(int nj = 1; nj <= n; nj++)
	{
		if(vis[j][nj] == 0)
		{
			vis[i][j] = 1;
			vis[j][i] = 1;
			cnt += g[i][j];
			dfs(j, nj, cnt, n);
			vis[i][j] = 0;
			vis[j][i] = 0;
			cnt -= g[i][j];
		}
	}
	return;
}

int main()
{
	memset(g, 0, sizeof(g));
	memset(vis, 0, sizeof(vis));
	int n;
	int a, b, v;
	cin >> n;
	int t = n - 1;
	while(t--)
	{
		cin >> a >> b >> v;
		g[a][b] = v;
		g[b][a] = v;
	}
	int i, j;
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= n; j++)
		{
			if(g[i][j] == 0)
				continue;
			else
			{ 
				dfs(i, j, 0, n);
				break;
			}
		}
	}
	dfs(i, j, 0, n);
	cout << ans;
	return 0;
} 