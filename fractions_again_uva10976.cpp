#include <cstdio>
#include <vector>
#include <cstdlib>
using namespace std;
int main()
{
    int k;
    while (scanf("%d", &k) == 1 && k)
    {
        vector<int> X, Y;
        for (int y = k + 1; y <= 2 * k; y++)
        {
            double x = 0;
            if (y != k)
                x = (double)k * y / (double)(y - k);
            // if( k * y % (y - k) == 0)
            // 判断一个浮点数是否为整数
            // 浮点数不可用 == 和！=来比较，因为存在误差！
            if ((int)x >= y && (x - (int)x < 0.000000001) && (x - (int)x > -0.000000001))
            {
                X.push_back((int)x);
                Y.push_back(y);
            }
        }
        printf("%d\n", X.size());
        for (size_t i = 0; i < X.size(); i++)
            printf("1/%d = 1/%d + 1/%d\n", k, X[i], Y[i]);
    }
    system("pause");
    return 0;
}
