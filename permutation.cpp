// 全排列
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    int a;
    cin >> a;
    char aa[6];
    sprintf(aa, "%d", a);
    sort(aa, aa + 3);
    do
    {
        for (size_t k = 0; k < 3; k++)
        {
            cout << aa[k] << ' ';
        }
        cout << endl;
    } while (next_permutation(aa, aa + 3));

    system("pause");
    return 0;
}
