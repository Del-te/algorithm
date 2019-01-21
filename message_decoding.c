#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char codes[8][1 << 8];
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
    memset(codes, 0, sizeof(char) * 8 * (1 << 8));
    codes[1][0] = readchar();
    for (length = 1; length < 8; length++)
        for (value = 0; value < (1 << length) - 1; value++)
        {
            ch = getchar();
            if (ch != '\n' && ch != '\r' && ch != EOF)
                codes[length][value] = ch;
            else
                return 1;
        }
    return 0;
}
int main(int argc, char const *argv[])
{
    int len = 0;
    int val = 0;
    while (readcodes() == 1)
    {
        while ((len = readint(3)) != 0)
            while ((val = readint(len)) != (1 << len) - 1)
                printf("%c", codes[len][val]);
        printf("\n");
    }
    return 0;
}

// ABCDEFGHIJKLMNOPQRSTUVWXYZ
// 100001110001111
// 011101111
// 100000100100010010001100111010100101111
// 0100011
// 00101
// 011010110111
// 100011110101111
// 011100110111
// 10001011111
// 011000111
// 100100101011111
// 011011100100111
// 010000011
// 100001100011111
// 011100110111
// 10000001111
// 010000011
// 10010001111
// 000
// U
// 00100000000001
// 000
// TNM AEIOU
// 00
// 10
// 101100011
// 1010001001110110011
// 11
// 00
// 0
// $#**\
// 0
// 10
// 0
// 0001011011
// 0
// 001110010100
// 0