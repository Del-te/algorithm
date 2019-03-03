#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1000;

int X[maxn];
int N;
int R;

int solve()
{
    int i = 0;
    int ans = 0;
    sort(X, X + N);
    while (i < N)
    {
        // s是没有被覆盖的最左边的点的位置
        int s = X[i]; // 原书是i++ 但是解题没有影响
        // 一直走到距离s大于R的点
        while (i < N && X[i] <= s + R)
            i++;
        // p是新加上标记的点的位置
        int p = X[i - 1];
        // 一直走到距离p大于R的节点的位置
        while (i < N && X[i] <= p + R)
            i++;
        ans++;
    }
    return ans;
}
int main()
{
    while (true)
    {
        cin >> R;
        cin >> N;
        if (R == -1 || N <= 0)
            break;
        for (int i = 0; i < N; i++)
        {
            cin >> X[i];
        }
        cout << solve() << endl;
    }
    system("pause");
    return 0;
}
