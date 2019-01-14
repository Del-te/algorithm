#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define maxn 101
const char *mirror_upper = "A   3  HIL JM O   2TUVWXY501SE Z  8 ";
const char *mirror_lower = " d b    i  lmnoqp   uvwx  ";
char ch_num(char ch)
{
    // if (isalpha(ch)) islower(ch)||isupper(ch)
    // {
    //     if (islower(ch))
    //         return mirror_lower[ch - 'a'];
    //     if (isupper(ch))
    //         return mirror_upper[ch - 'A'];
    // }
    if (isalpha(ch) == 2)
        return mirror_lower[ch - 'a'];
    if (isalpha(ch) == 1)
        return mirror_upper[ch - 'A'];
    if (isdigit(ch))
        return mirror_upper[ch - '0' + 26];
}
int is_mirror(char *s)
{
    int i = 0;
    int len = 0;
    len = strlen(s);
    for (i = 0; i < (len + 1) / 2; i++)
    {
        if (ch_num(s[i]) != s[(len - 1) - i])
            return 0;
    }
    return 1;
}
int main(int argc, char const *argv[])
{
    char s[maxn];
    memset(s, 0, sizeof(s));
    while (scanf("%s", s) == 1 && s[0] != '#')
    {
        if(is_mirror(s))
            printf("is mirror!\n");
        else 
            printf("is not mirror!\n");
    }
    system("pause");
    return 0;
}
