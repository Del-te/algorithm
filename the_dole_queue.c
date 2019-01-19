#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn 20

int a[maxn];
int n = 0, k = 0, m = 0;

int go(int locate, int step_length, int step_num)
{
    while (step_num--)
    {
        do
        {
        locate = (locate + step_length + n-1) % n + 1;
        }while(a[locate] == 0);   
    }
    return locate;
}
int main(int argc, char const *argv[])
{
    while (scanf("%d%d%d", &n, &k, &m) == 3 && n != 0)
    {
        // memset(a, 0, sizeof(int) * maxn);
        for (int i = 1; i <= n; i++)
            a[i] = i;

        int left = n;
        int p1 = n, p2 = 1;
        while (left != 0)
        {
        p1 = go(p1, -1, k);
        p2 = go(p2, 1, m);
        left--;
        if (p1 != p2)
        {
            printf("%3d %3d", p1, p2);
            left--;
        }
        else
            printf("%3d", p1);
        a[p1] = a[p2] = 0;
        if (left != 0)
            printf(",");
        }
        printf("\n");
    }
    system("pause");
    return 0;
}
