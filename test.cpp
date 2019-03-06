#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 100;
int dp[maxn + 1][maxn + 1];
int N;
int W;
int w[maxn];
int v[maxn];

void input()
{
	cin >> N;
	for (size_t i = 0; i < N; i++)
	{
		cin >> w[i] >> v[i];
	}
	cin >> W;
}
int solove()
{
	for (int i = N - 1; i >= 0; i--)
	{
		for (int j = 0; j <= W; j++)
		{
			if (w[i] > j)
			{
				dp[i][j] = dp[i + 1][j];
			}
			else
			{
				dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - w[i]] + v[i]);
			}
		}
	}
	return dp[0][W];
}
int main()
{
	memset(dp, -1, sizeof(dp));
	input();
	cout << solove() << endl;
	system("pause");
	return 0;
}
