// 仔细逻辑的把问题想全面
#include <iostream>
using namespace std;
const int maxn = 105;
int a[maxn];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n + 1; i++)
    {
        cin >> a[i];
    }

    for (int j = n; j > 0; j--)
    {
        if (j == n)
        {
            if (a[n - j] == 0)
            {
                continue;
            }
            if (a[n - j] == 1)
            {
                cout << "x^" << j;
            }
            else if (a[n - j] == -1)
            {
                cout << "-"
                     << "x^" << j;
            }
            else
                cout << a[n - j] << "x^" << j;
        }
        else if (j == 1)
        {
            if (a[n - j] == 1)
            {
                cout << "+" << "x";
            }
            else if (a[n - j] == -1)
            {
                cout << "-"  << "x";
            }

            else if (a[n - j] == 0)
            {
                continue;
            }

            else if (a[n - j] > 0)
            {
                cout << "+" << a[n - j] << "x";
            }
            else
            {
                cout << a[n - j] << "x";
            }
        }

        else if (a[n - j] == 1)
        {
            cout << "+"
                 << "x^" << j;
        }
        else if (a[n - j] == -1)
        {
            cout << "-"
                 << "x^" << j;
        }

        else if (a[n - j] == 0)
        {
            continue;
        }

        else if (a[n - j] > 0)
        {
            cout << "+" << a[n - j] << "x^" << j;
        }
        else
        {
            cout << a[n - j] << "x^" << j;
        }
    }
    // 最后常数项所有情况也要考虑好
    if (a[n] != 0)
    {

        if (a[n] > 0)
        {
            cout << "+" << a[n];
        }
        else
        {
            cout << a[n];
        }
    }
    system("pause");
    return 0;
}
