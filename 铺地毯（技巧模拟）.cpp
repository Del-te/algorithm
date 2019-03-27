#include <iostream>
using namespace std;

const int maxn = 100005;

int ground[maxn][4];

int main()
{
    int n;
    cin >> n;
    for (int i = 0;i < n;i++)
    {
        cin >> ground[i][0] >> ground[i][1] 
            >> ground[i][2] >> ground[i][3];
        ground[i][2] += ground[i][0];
        ground[i][3] += ground[i][1];
    }
    int x, y;
    cin >> x >> y;
    for(int i = n; i >= 0; i--)
    {
        if (x >= ground[i][0] && x <= ground[i][2] 
            && y >= ground[i][1] && y <= ground[i][3]) {
            cout << i + 1;
            return 0;
        }
    }
    cout << -1;
    system("pause");
    return 0;
}
