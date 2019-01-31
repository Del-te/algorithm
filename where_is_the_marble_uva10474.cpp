#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 10000;
int main()
{
    int n = 0, q = 0, c[maxn], x = 0, i = 0, l = 0, kase = 0;
    while (scanf("%d%d", &n, &q) == 2 && n)
    {
        memset(c, 0, sizeof(int) * maxn);
        for (i = 0; i < n; i++)
        {
            scanf("%d", &c[i]);
        }
        sort(c, c + n);
        while (q--)
        {
            scanf("%d", &x);  // 注意数据不要被提前吃掉
            l = lower_bound(c, c + n, x) - c;
            printf("CASE# %d:\n", ++kase);
            if (c[l] == x)
                printf("%d found at %d\n", x, l + 1);
            else
                printf("%d not found\n", x);
        }
    }
    system("pause");
    return 0;
}
