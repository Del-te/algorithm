#include <iostream>
#include <algorithm>
using namespace std;
int a[100] = {0};
int main()
{
    int p, n;
    scanf("%d %d", &p, &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    p = p % n;
    if (p != 0)
    {
        reverse(a, a + n);
        reverse(a, a + (n-p));
        reverse(a + (n-p), a + n);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d", a[i]);
        if (i < n - 1)
            printf(" ");
    }
    system("pause");
    return 0;
}
