#include <iostream>
using namespace std;

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 9};
    int x1 = 0;
    for (int i = 0; i < 10; i++)
        x1 = x1 ^ (i + 1);
    for (int i = 0; i < 11; i++)
        x1 = x1 ^ a[i];
    cout << x1 << endl;
    system("pause");
    return 0;
}
// 第一个for，x1 = 1^2^3...^9^10
// 第二个for，x1 = (1^2^3...^9^10)^a[]中每个元素
// 重复的一共异或了3次，其余的被消掉了
// 0^a = a; a^a = 0;