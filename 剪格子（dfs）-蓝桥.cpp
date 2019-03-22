#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 10;
int a[maxn][maxn];
int vis[maxn][maxn];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
// 一共n行，一行m个 
int n, m;
int sum = 0;
int ans = 100;
int isin(int x, int y)
{
	if(x >= 0 && x < m && y >= 0 && y < n)	
		return 1;
	else 
		return 0; 
}
void dfs(int x, int y, int steps, int cnt)
{	
	
	if(cnt * 2 >= sum)
	{
		if(cnt * 2 == sum)
			ans = min(steps, ans);
		return;
	}
	for(int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(isin(nx, ny) && !vis[nx][ny])			
		{
			steps++;
			cnt += a[x][y];
			vis[x][y] = 1;
			dfs(nx, ny, steps, cnt);
			steps--;
			cnt -= a[x][y];
			vis[x][y] = 0;
		}
	}
	return;
}
int main()
{
	scanf("%d%d", &m, &n);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		{
			scanf("%d", &a[i][j]);
			sum += a[i][j];
		}
	memset(vis, 0, sizeof(vis));			
	if (sum % 2 == 1)
	{ 
		cout << '0';	
		return 0; 
	} 
	dfs(0, 0, 0, 0);
	cout << ans;
	return 0;
} 