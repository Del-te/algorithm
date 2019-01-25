#include <iostream>
using namespace std;

int main()
{
    int x = 0b1001;
    int count = 0;
    for(size_t i = 0; i < 32; i++)
    {
        if ((x & (1 << i)) == (1 << i)) {
            count++;
        }
    }
    cout << x << " " << count << endl;
    count = 0;
    for(size_t i = 0; i < 32; i++)
    {
        if ((x >> i) & 1 == 1)
            count++;
    }
    cout << x << " " << count << endl;
    count = 0;
    int t = x;
    while(x != 0)
    {
        x = x & (x-1);
        count++;
    }
    cout << t << " " << count << endl;
    system("pause");
    return 0;
}
// 二进制数中1的个数