#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    int n;
    int a[20];
    memset(a, 0, sizeof(a));
    while (scanf("%d", &n) == 1 && n)
    {
        long long result = 0;
        for (size_t i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (int start = 0; start < n; start++)
        {
            long long t = 1;
            for (int end = start; end < n; end++)
            {
                t *= a[end];
                if (t > result)
                {
                    result = t;
                }
            }
        }
        printf("%lld\n", result);
    }
    system("pause");
    return 0;
}
