#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
 
int n,m,cnt;
const int maxn = 210;
int g[maxn][maxn];
int num[6];
char st[6] = {'A', 'D', 'J', 'K', 'S', 'W'};
char str[]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
int s[16][4]=
{
    {0,0,0,0},{0,0,0,1},{0,0,1,0},{0,0,1,1},
    {0,1,0,0},{0,1,0,1},{0,1,1,0},{0,1,1,1},
    {1,0,0,0},{1,0,0,1},{1,0,1,0},{1,0,1,1},
    {1,1,0,0},{1,1,0,1},{1,1,1,0},{1,1,1,1}
};
// 是否未越界
bool is_in(int x,int y)
{
    if(x>=0&&x<=n+1&&y>=0&&y<=m+1)
        return true;
    else return false;
}
// dfs白色区域
void dfs(int x,int y)
{
    if(!is_in(x,y)||g[x][y]!=0)
        return;
    g[x][y]=-1; // 走过的用-1标记
    dfs(x-1,y);
    dfs(x+1,y);
    dfs(x,y-1);
    dfs(x,y+1);
}
// dfs黑色区域
void dfs2(int x,int y)
{
    if(!is_in(x,y)||g[x][y]==-1)
        return;
    // 如果遇到了白色区域
    if(g[x][y]==0) 
    {
        // 统计白洞个数
        cnt++; 
        dfs(x,y);
        return;
    }
    g[x][y]=-1; // 走过的用-1标记
    dfs2(x-1,y);
    dfs2(x+1,y);
    dfs2(x,y-1);
    dfs2(x,y+1);
}
 
int main()
{
    int kase=0;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0) break;
        kase++;
        memset(g, 0, sizeof(g));
        memset(num, 0, sizeof(num));
        for(int i=1;i<=n;i++)
        {
            getchar();
            char ch;
            int len=1;
            for(int j=0;j<m;j++)
            {
                scanf("%c",&ch);
                // 将数组转换为二进制
                for(int k=0;k<16;k++)
                {
                    if(ch==str[k])
                    {
                        for(int l=0;l<4;l++)
                            g[i][len++]=s[k][l];
                        break;
                    }
                }
            }
        }
        m=m*4;
        dfs(0,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(g[i][j]==1)
                {
                    cnt=0;
                    dfs2(i,j);
                    if(cnt==0) num[5]++;
                    if(cnt==1) num[0]++;
                    if(cnt==2) num[3]++;
                    if(cnt==3) num[2]++;
                    if(cnt==4) num[4]++;
                    if(cnt==5) num[1]++;
                }
            }
        }
        printf("Case %d: ",kase);
        for(int i=0;i<6;i++)
        {
            printf(" %d ",num[i]);
            while(num[i]--)
            {
                printf("%c",st[i]);
            }
        }
        printf("\n");
    }
}