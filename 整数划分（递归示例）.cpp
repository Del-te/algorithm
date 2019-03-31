#include <iostream>
using namespace std;

void go(int n, int steps)
{
    if (n == 0)
    {
        return;
    }
    cout << n;
    if (steps < n && steps != 0)
    {
        cout << " + " << steps;
    }
    else for(int i = 0; i < steps; i++)
    {
        cout << " + 1";
    }
    cout << endl;
    go(n - 1, steps + 1);
}
int main()
{
    int n;
    cin >> n;
    go(n, 0);
    system("pause");
    return 0;
}
