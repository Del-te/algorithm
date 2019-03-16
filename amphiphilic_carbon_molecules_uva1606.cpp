#include<iostream>  
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

const int maxn = 1000+5;

int n;
int ans;

struct node
{
    int x, y;
    int color;
    double rad;
    bool operator < (const node&rhs) const
    {
        return rad < rhs.rad;
    }
}op[maxn],p[maxn];


bool left(node a, node b)
{
    return a.x*b.y - a.y*b.x >= 0;
}

void solve()
{
    if (n <= 3)  { ans = n; return; }
    ans = 0;
    for (int i = 0; i < n; i++)  //枚举选择基点,一共有n个基点可以选择
    {
        int k = 0;
        for (int j = 0; j < n; j++)    //计算出各个点关于基点的相对坐标
        {
            if (i == j)  continue;
            p[k].x = op[j].x - op[i].x;
            p[k].y = op[j].y - op[i].y;
            if (op[j].color)    //如果为黑点，则可以将它旋转180之后变为白点来计数
            {
                p[k].x = -p[k].x; p[k].y = -p[k].y;
            }
            p[k].rad = atan2(p[k].y, p[k].x);   //求极角,返回角度值
            k++;
        }
        sort(p, p + k);
        //基准点-p[L]为分割线，基准点-p[R]为扫描线
        int    L = 0, R = 0, cnt = 2;   //初始点数设为2，即分隔线上的两个点
        while (L < k)   //每个点都尝试与基点成为分割线
        {
            if (R == L)  { R = (R + 1) % k; cnt++; }  //空区域，数量+1，后面还会减去的
            while (R != L && left(p[L], p[R]))   //R不等于L并且在180度之内
            {
                R = (R + 1) % k;
                cnt++;
            }
            cnt--; //分隔线旋转，原本在分隔线上的点到了右边，所以要减去
            L++;  //分隔线旋转
            ans = max(ans, cnt);
        }
    }
}

int main()
{
    //freopen("D:\\txt.txt", "r", stdin);
    while (cin >> n && n)
    {
        for (int i = 0; i < n; i++)
            cin >> op[i].x >> op[i].y >> op[i].color;
        solve();
        cout << ans << endl;
    }
    return 0;
}