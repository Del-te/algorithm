#include <iostream>
using namespace std;

bool solve(int &w) // 引用方式传值
{
    int w1, d1, w2, d2;
    int b1 = true, b2 = true;
    cin >> w1 >> d1 >> w2 >> d2;
    if (w1 == 0)
        b1 = solve(w1);
    if (w2 == 0)
        b2 = solve(w2);
    w = w1 + w2; // 引用方式传值
    return b1 && b2 && (w1 * d1 == w2 * d2);
}
int main()
{
    int T, W;
    cin >> T;
    while (T--)
    {
        if (solve(W))
            cout << "YES!\n";
        else
            cout << "NO!\n";
        if (T != 0)
            cout << '\n';
    }
    system("pause");
    return 0;
}
