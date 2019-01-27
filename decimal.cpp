#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;
int main(int argc, char const *argv[])
{
    int a, b, c = 0;
    int t, count = 0;
    float result[100] = {0};
    while (scanf("%d%d%d", &a, &b, &c) == 3 && a != 0 && b != 0 && c != 0)
    {
        result[count] = (float)a / b;
        result[count] = (int)(result[count] * pow(10, c) + 0.5) / pow(10, c);
        count++;
    }
    for (int i = 0; i <= count - 1; i++)
    {
        printf("Case %d: %lf\n", i + 1, result[i]);
    }
    system("pause");
    return 0;
}
