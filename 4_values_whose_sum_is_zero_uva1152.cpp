// 中途相遇法
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 4000 + 5;
int n, c, A[maxn], B[maxn], C[maxn], D[maxn], sums[maxn * maxn];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d%d%d%d", &A[i], &B[i], &C[i], &D[i]);
        c = 0;
        // 计算并存储A[i]+B[i]
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                sums[c++] = A[i] + B[j];
        sort(sums, sums + c);
        long long cnt = 0;
        // 遍历寻找合适的C[i]+B[i]
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            // 寻找有几个合适的值的技巧
                cnt += upper_bound(sums, sums + c, -C[i] - D[j]) 
                       - lower_bound(sums, sums + c, -C[i] - D[j]);
        printf("%lld\n", cnt);
        if (T)
            printf("\n");
    }
    return 0;
}