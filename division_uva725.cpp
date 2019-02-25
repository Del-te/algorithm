#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    char buf[99];
    scanf("%d", &n);
    for (int fghij = 1234;; fghij++)
    {
        int abcde = fghij * n;
        // 检验全排列方法，先转换为c字符串，再排序，再for比较
        sprintf(buf, "%05d%05d", abcde, fghij);
        sort(buf, buf + 10);
        if (strlen(buf) > 10)
        {
            break;
        }
        bool flag = true;
        for (size_t i = 0; i < 10; i++)
        {
            if (buf[i] != '0' + i) // 注意char和int相比
            {
                flag = false;
            }
        }
        if (flag)
        {
            printf("%05d / %05d = %d\n", abcde, fghij, n);
        }
    }
    system("pause");
    return 0;
}
