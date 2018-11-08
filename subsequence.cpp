#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
int main(int argc, char const *argv[]) 
{
    int n, m;
    double result[100] = {0};
    long long t = 0;
    int count = 0;
    while(scanf("%d%d", &n, &m) == 2 
            && (n < m && m < 1000000)
            && n && m) 
    {
        for(int i = 0; i <= m - n; i++)
        {
            t = (n + i) * (n + i);
            // isinf() 判断是否为无穷大（小），是返回true，否返回false
            if(isinf(double(1.0/t)))
                result[count] = 0.00001;
            // 这个1.0很重要！！！！！
            else
                result[count] += 1.0 / t;
        }
        count++; 
    }
    
    for(int i = 0; i < count; i++)
    {
        printf("Case %d: %.5lf\n", i+1, result[i]);
    }
    system("pause");
    return 0;
}

