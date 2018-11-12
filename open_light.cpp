#include <cstdio>
#include <cstdlib>
#include <cstring>
#define maxn 105

using namespace std;

int a[maxn];

int main(int argc, char const *argv[])
{
    int n, k, first = 1;
    memset(a, 0, sizeof(a));
    scanf("%d%d", &n, &k);
    for (size_t i = 1; i <= k; i++)
        for (size_t j = 1; j <= n; j++)
        {
            if (j % i == 0)
                a[j] = !a[j];
        }

    for (size_t i = 1; i <= n; i++)
    {
        if (a[i])
        {
            if (first)
                first = 0;
            else
                printf(" ");
            printf("%u", i);
        }
    }
    printf("\n");
    system("pause");
    return 0;
}
