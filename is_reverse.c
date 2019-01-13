#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn 101
int is_reverse(char *s)
{
    int i = 0;
    int len = strlen(s);
    for(i = 0;i < ((len+1)/2);i++)
    {
        if(*(s+i) != *(s+(len-1-i)))
            return 0;
    }
    return 1;
}

int main(int argc, char const *argv[])
{
    char s[maxn];
    memset(s, 56, sizeof(s));
    while(scanf("%s", s) == 1 && *s != '0')
        if(is_reverse(s))
            printf("is reverse\n");
        else
            printf("is not reverse\n");
    system("pause");    
    return 0;
}
