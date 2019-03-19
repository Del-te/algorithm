#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 50;
int vis1[3][maxn];
int vis2[3][maxn];
int a[maxn][maxn];
int N;
int count = 0;
void tracing_back2(int c)
{
    if (c >= N)
    {
        count++;
    }
    else
        for (int i = 0; i < N; i++)
        {
            if (a[c][i] && !vis2[0][i] && !vis2[1][c + i] && !vis2[2][c - i + N])
            {
                vis2[0][i] = vis2[1][c + i] = vis2[2][c - i + N] = 1;
                a[c][i] = 0;
                tracing_back2(c + 1);
                vis2[0][i] = vis2[1][c + i] = vis2[2][c - i + N] = 0;
                a[c][i] = 1;
            }
        }
}
void tracing_back1(int c)
{
    if (c >= N)
    {
        tracing_back2(0);
    }
    else
        for (int i = 0; i < N; i++)
        {
            if (a[c][i] && !vis1[0][i] && !vis1[1][c + i] && !vis1[2][c - i + N])
            {
                vis1[0][i] = vis1[1][c + i] = vis1[2][c - i + N] = 1;
                a[c][i] = 0;
                tracing_back1(c + 1);
                vis1[0][i] = vis1[1][c + i] = vis1[2][c - i + N] = 0;
                a[c][i] = 1;
            }
        }
}
int main()
{
    int c = 0;
    cin >> N;
	for(int i = 0;i < N;i++)
	{
		for(int j = 0;j < N;j++)
		{
			cin >> a[i][j];		
		}
	} 
    memset(vis1, 0, sizeof(vis1));
    memset(vis2, 0, sizeof(vis2));
    tracing_back1(c);
    cout << count << endl;
    return 0;
}
