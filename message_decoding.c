#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char translate_code[8][1 << 8];
int readchar()
{
    while (1)
    {
        int ch = getchar();
        if (ch != '\n' && ch != '\r')
            return ch;
    }
}
int readint(int length)
{
    int sum = 0;
    while (length--)
        sum = sum * 2 + (readchar() - '0');
    return sum;
}
int readcodes()
{
    int length = 0, value = 0;
    int ch;
    memset(translate_code, 0, sizeof(char) * 8 * (1 << 8));
    for (length = 1; length < 8; length++)
        for (value = 0; value < (1 << length) - 1; value++)
        {
            ch = getchar();
            if (ch != '\n' && ch != '\r' && ch != EOF)
                translate_code[length][value] = ch;
            else
                return 1;
        }
    return 0;
}
int main(int argc, char const *argv[])
{
    int len = 0;
    int val = 0;
    int i = 0;
    while (readcodes() == 1)
    {
        while ((len = readint(3)) != 0)
            while ((val = readint(len)) != (1 << len) - 1)
                printf("%c", translate_code[len][val]);
        printf("\n");
    }
    return 0;
}
/* $#**\0100000101101100011100101000 */