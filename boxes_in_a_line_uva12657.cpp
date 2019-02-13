#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100 + 5;
int n, left[maxn], right[maxn];

inline void link(int L, int R)
{
    right[L] = R;
    left[R] = L;
}

int main()
{
    int m, kase = 0;
    while (scanf("%d%d", &n, &m) == 2)
    {
        // 双向链表初始化
        for (int i = 1; i <= n; i++)
        {
            left[i] = i - 1;
            right[i] = (i + 1) % (n + 1); // 求余n+1避免越界
        }
        // 让模拟链表循环
        right[0] = 1;
        left[0] = n;

        int op, X, Y, inv = 0;

        while (m--)
        {
            scanf("%d", &op);
            if (op == 4)
                inv = !inv;
            else
            {
                scanf("%d%d", &X, &Y);
                if (op == 3 && right[Y] == X)
                    swap(X, Y);
                // 如果是12操作并且已经进行过奇数次4操作，那么12操作要掉个
                if (op != 3 && inv)
                    op = 3 - op;
                // 忽略无需进行的操作，减少开支
                if (op == 1 && X == left[Y])
                    continue;
                if (op == 2 && X == right[Y])
                    continue;
                // 进行12操作
                // x的左边 x的右边 y的左边 y的右边
                int LX = left[X], RX = right[X], LY = left[Y], RY = right[Y];
                if (op == 1)
                {
                    link(LX, RX);
                    link(LY, X);
                    link(X, Y);
                }
                else if (op == 2)
                {
                    link(LX, RX);
                    link(Y, X);
                    link(X, RY);
                }
                else if (op == 3)
                {
                    if (right[X] == Y)
                    {
                        link(LX, Y);
                        link(Y, X);
                        link(X, RY);
                    }
                    else
                    {
                        link(LX, Y);
                        link(Y, RX);
                        link(LY, X);
                        link(X, RY);
                    }
                }
            }
        }

        int b = 0;
        long long ans = 0;
        for (int i = 1; i <= n; i++)
        {
            b = right[b]; // 向右移动
            if (i % 2 == 1) // 如果是奇数次
                ans += b; // 所有奇数位置编号之和
        }
        // 如果进行过4操作并且n是偶数，ans用总的编号之和减去奇数编号之和
        if (inv && n % 2 == 0)
            ans = (long long)n * (n + 1) / 2 - ans;
        printf("Case %d: %lld\n", ++kase, ans);
    }
    return 0;
}