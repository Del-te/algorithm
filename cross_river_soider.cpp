#include <cstdio>
#include <cstdlib>
using namespace std;
int B1, B2, horse1, horse2;
bool barrier[21][21];
long long count[21][21];
int main()
{
    scanf("%d%d%d%d", &B1, &B2, &horse1, &horse2);
    //数组初始化
    for (int i = 0; i <= B1; i++)
        for (int j = 0; j <= B2; j++)
            barrier[i][j] = true;
    for (int i = 0; i <= B1; i++)
        for (int j = 0; j <= B2; j++)
            count[i][j] = 1;
    //标记马能踢到的地方
    if (horse1 - 2 >= 0 && horse2 - 1 >= 0)
        barrier[horse1 - 2][horse2 - 1] = false;
    if (horse1 - 2 >= 0 && horse2 + 1 <= B2)
        barrier[horse1 - 2][horse2 + 1] = false;

    if (horse1 - 1 >= 0 && horse2 - 2 >= 0)
        barrier[horse1 - 1][horse2 - 2] = false;
    if (horse1 - 1 >= 0 && horse2 + 2 <= B2)
        barrier[horse1 - 1][horse2 + 2] = false;

    if (horse1 + 1 <= B2 && horse2 - 2 >= 0)
        barrier[horse1 + 1][horse2 - 2] = false;
    if (horse1 + 2 <= B1 && horse2 - 1 >= 0)
        barrier[horse1 + 2][horse2 - 1] = false;

    if (horse1 + 1 <= B1 && horse2 + 2 <= B2)
        barrier[horse1 + 1][horse2 + 2] = false;
    if (horse1 + 1 <= B1 && horse2 + 1 <= B2)
        barrier[horse1 + 2][horse2 + 1] = false;

    barrier[horse1][horse2] = false;
    for (int i = 0; i <= B1; i++)
    {
        for (int j = 0; j <= B2; j++)
            printf("%d ", barrier[i][j]);
        printf("\n");
    } //回溯求解路径
    for (int i = 0; i <= B1; i++)
    {
        for (int j = 0; j <= B2; j++)
        {
            if (barrier[i][j])
            {
                if (i == 0 && j == 0)
                    continue;
                else if (i == 0)
                    count[i][j] = count[i][j - 1];
                else if (j == 0)
                    count[i][j] = count[i - 1][j];
                else
                    count[i][j] = count[i - 1][j] + count[i][j - 1];
            }
            else
                count[i][j] = 0;
        }
    }
    
    printf("\n");

    for (int i = 0; i <= B1; i++){
        for (int j = 0; j <= B2; j++)
            printf("%lld ", count[i][j]);
        printf("\n");
    }
    
    printf("\n");

    printf("%lld", count[B1][B2]);
    system("pause"); // 防止程序一闪而过，提交时应删去
    return 0;
}
