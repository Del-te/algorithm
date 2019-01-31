#include <stdio.h>
#include <stdlib.h>

long long C(int n, int m)
{
    long long ans = 1; // 不能等于0，0乘以任何数都为0！
    int i = 0;
    if (m < n - m)
        m = n - m;
    for (i = m + 1; i <= n; i++)
        ans *= i;
    for (i = 1; i <= n - m; i++)
        ans /= i;
    return ans;
}
int main(int argc, char const *argv[])
{
    int n, m;
    while (scanf("%d%d", &n, &m) == 2 && (n != 0 && m != 0))
        printf("%lld\n", C(n, m));
    system("pause");
    return 0;
}
