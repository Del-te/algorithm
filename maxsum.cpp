// 分治法: 最大连续和
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100;
int in[maxn];

int maxsum(int *A, int x, int y)
{
    int v, L, R, maxs;
    if (y - x == 1) {
        return A[x];
    }
    // 第一步：划分成[x, m)和[m, y)
    int m = x + (y - x) / 2; // 二分划界
    // 第二步：递归求解
    maxs = max(maxsum(A, x, m), maxsum(A, m, y));
    // 第三步：合并1---从分界点开始往左的最大连续和L
    v = 0;
    L = A[m - 1];
    for(int i = m - 1; i >= x; i--)
    {
        L = max(L, v += A[i]);
    }
    // 第三步：合并2---从分界点开始往右的最大连续和R
    v = 0;
    R = A[m];
    for(int i = m; i < y; i++)
    {
        R = max(R, v += A[i]);
    }
    // 把子问题的解与L和R比较
    return max(maxs, L + R);
}
int main()
{
    int t, i = 0;
    while(cin >> t && t != 0){
        in[i] = t;
        i++;
    }
    cout << maxsum(in, 0, 99) << endl;
    system("pause");
    return 0;
}
