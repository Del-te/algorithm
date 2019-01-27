#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn 101

char str1[maxn];
char str2[maxn];
int count1[26];
int count2[26];

int comparator(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
void count()
{
    int i = 0, j = 0;
    for (i = 0; i < strlen(str1); i++)
        count1[str1[i] - 'A']++;
    for (j = 0; j < strlen(str2); j++)
        count2[str2[j] - 'A']++;
}
int judge()
{
    int i = 0;
    count();
    qsort(count1, 26, sizeof(int), comparator);
    qsort(count2, 26, sizeof(int), comparator);
    for (i = 0; i < 26; i++)
    {
        if (count1[i] != count2[i])
            return 0;
    }
    return 1;
}
int main(int argc, char const *argv[])
{
    memset(count1, 0, sizeof(int) * 26);
    memset(count2, 0, sizeof(int) * 26);
    memset(str1, 0x00, sizeof(char) * maxn);
    memset(str2, 0x00, sizeof(char) * maxn);
    while (scanf("%s%s", str1, str2) == 2 && str1[0] != '0')
    {
        if (judge())
            printf("YES!\n");
        else
            printf("NO!\n");
    }
    system("pause");
    return 0;
}
