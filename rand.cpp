// 测试随机数功能
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    // 初始化，不写默认为srand(1)
    srand(time(NULL));
    for (size_t i = 0; i < 20; i++)
    {
        // 1 ~ 10 闭区间随机数，最大范围为rand_max
        cout << rand() % 10 + 1 << endl;
    }
    cout << endl;
    for (size_t i = 0; i < 20; i++)
    {
        // 超出rand_max范围的写法，有较大误差
        cout << (rand() / (double)RAND_MAX) * 100000000 << endl;
    }
    system("pause");
    return 0;
}
