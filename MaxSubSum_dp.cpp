#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1005;

long long dp[maxn];
long long a[maxn];
long long n;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dp[i] = a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i] = max(dp[i], dp[i - 1] + a[i]);
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, dp[i]);
    cout << ans << endl;
    system("pause");
    return 0;
}