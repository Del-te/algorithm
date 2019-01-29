#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 100000;
int hashtable[maxn];
long n;

int main()
{
    int x;
    cin >> n;
    int count = 2;
    memset(hashtable, 0, sizeof(int)*maxn);
    while (n--)
    {
        cin >> x;
        hashtable[x - 0]++;
    }
    for (size_t i = 0; i < maxn; i++)
    {
        if (hashtable[i] == 1)
        {
            cout << i;
            if (count != 1)
                cout << ' ';
            count--;
        }
    }
    return 0;
}
// 找出数组里两个只出现1次的数，其他均出现n次
// 日你妈数组要开这么大题里也不说下