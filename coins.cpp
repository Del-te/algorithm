// 贪心算法：尽可能使用更少的硬币
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int coins[6] = {1, 5, 10, 50, 100, 500}; // 硬币的面值
    int c[6]; // 硬币的个数
    int A; // 要花多少钱
    int ans = 0; // 最少花几枚硬币
    memset(c, 0, sizeof(c));
    for(size_t i = 0; i < 6; i++)
    {
        scanf("%d", &c[i]);
    }
    scanf("%d", &A);
    for(size_t i = 5; i >= 0; i--)
    {
        // 使用硬币i的枚数
        int t = min(A / coins[i], c[i]);
        A -= t * coins[i];
        ans += t;
        if(A == 0)
            break;
    }
    printf("%d\n", ans);
    system("pause");
    return 0;
}