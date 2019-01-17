#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn 101
char ans[maxn];
char gus[maxn];
int alp[26];
int flag = -2; // 输赢状态
int judge()    // -1 lose;0 chickened out;1 win;
{
    int i = 0;
    int chance = 7;
    int count = 0;
    for (i = 0; i < strlen(ans); i++)
        alp[ans[i] - 'a'] = 1;
    for (i = 0; i < 26; i++)
        if (alp[i] == 1)
            count++;
    for (i = 0; i < strlen(gus); i++)
    {
        if (alp[gus[i] - 'a'] == 0)
        {
            chance--;
        }
        else if (alp[gus[i] - 'a'] == 1)
        {
            count--;
            alp[gus[i] - 'a'] = -1; // 避免count重复减值
        }
        if (count == 0 && chance > 0) 
            return 1;
        if (chance == 0)
            return -1;
    }
    return 0;
}
int main(int argc, char const *argv[])
{
    int num = 0;
    while (scanf("%d%s%s", &num, ans, gus) == 3 && num != -1)
    {
        flag = judge();
        memset(alp, 0, sizeof(int) * 26); 
        // 一定记住只要用数组每次用都要清零！！！！！！
        // 遇到问题第一时间debug，不要盲猜！！！！！！
        printf("Round %d\n", num);
        if (flag == -1)
            printf("You lose.\n");
        else if (flag == 0)
            printf("You chickened out.\n");
        else if (flag == 1)
            printf("You win.\n");
        flag = -2;
    }
    system("pause");
    return 0;
}
