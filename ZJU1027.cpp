#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;
const int MaxN = 101;

// 两个基因序列
char str1[MaxN], str2[MaxN];
// 记录动态规划过程中产生的中间结果
// gene[i][j]表示基因子串str1[0...i-1]和str2[0...j-1]的分值
int gene[MaxN][MaxN];
// 基因分值矩阵
int score[5][5] = {{5, -1, -2, -1, -3},
                   {-1, 5, -3, -2, -4},
                   {-2, -3, 5, -2, -2},
                   {-1, -2, -2, 5, -1},
                   {-3, -4, -2, -1, 0}};

int get_max(int num1, int num2, int num3)
{
    int result = num1;
    if (num2 > result)
        result = num2;
    if (num3 > result)
        result = num3;
    return result;
}

int convert(char c)
{
    switch (c)
    {
    case 'A':
        return 0;
    case 'C':
        return 1;
    case 'G':
        return 2;
    case 'T':
        return 3;
    case '-':
        return 4;
    }
    return -1;
}

int main()
{
    int n;
    int len_a, len_b;
    cin >> n;
    for (int k = 0; k < n; k++)
    {
        cin >> len_a >> str1;
        cin >> len_b >> str2;

        gene[0][0] = 0;
        for (int i = 1; i <= len_b; i++)
            gene[0][i] = gene[0][i - 1] + score[4][convert(str2[i - 1])];
        for (int i = 1; i <= len_a; i++)
            gene[i][0] = gene[i - 1][0] + score[convert(str1[i - 1])][4];
        int m1, m2, m3;
        for (int i = 1; i <= len_a; i++)
            for (int j = 1; j <= len_b; j++)
            {
                // 三种情况
                m1 = gene[i - 1][j] + score[convert(str1[i - 1])][4];
                m2 = gene[i][j - 1] + score[4][convert(str2[j - 1])];
                m3 = gene[i - 1][j - 1] + score[convert(str1[i - 1])][convert(str2[j - 1])];
                gene[i][j] = get_max(m1, m2, m3);
            }
        cout << gene[len_a][len_b] << endl;
    }
    system("pause");
    return 0;
}
