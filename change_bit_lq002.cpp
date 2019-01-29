#include <iostream>
using namespace std;

int main()
{
    int A, B, count = 0;
    cin >> A >> B;
    A ^= B;
    for (size_t i = 0; i < 32; i++)
    {
        if (((A >> i) & 1) == 1)
            count++;
    }
    cout << count;
    return 0;
}
// 给定两个整数A和B，需要改变几个二进制位才能将A转为B
// 运用了异或找不同，右移和与计算1的个数