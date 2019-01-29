#include <iostream>
using namespace std;
int gcd(int m, int n)
{
    if (n == 0)
        return m;
    return gcd(n, m % n);
}
int main()
{
    int m, n;
    while (cin >> m >> n)
    {
        cout << gcd(m, n) << endl;
    }
    system("pause");
    return 0;
}
// 用辗转相除法求最大公约数