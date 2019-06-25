#include <iostream>
#include <vector>
using namespace std;
const string pinyin[10] = 
    {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
int main()
{
    vector<int> n;
    char c;
    while ((c = getchar()) != '\n')
    {
        n.push_back(c - '0');
    }
    
    long long rst = 0;
    
    for (size_t i = 0; i < n.size(); i++)
    {
        rst += n[i];
    }

    vector<int> t;
    while (rst > 0)
    {
        t.push_back(rst % 10);
        rst /= 10;
    }

    for (int i = t.size(); i > 0; i--)
    {
        cout << pinyin[t[i-1]];
        if (i > 1)
        {
            cout << " ";
        }
    }
    system("pause");
    return 0;
}

// 读入一个正整数 n，计算其各位数字之和，用汉语拼音写出和的每一位数字。

// 输入格式：
// 每个测试输入包含 1 个测试用例，即给出自然数 n 的值。这里保证 n 小于 10
// ​100

// 输出格式：
// 在一行内输出 n 的各位数字之和的每一位，拼音数字间有 1 空格，但一行中最后一个拼音数字后没有空格。

// 输入样例：
// 1234567890987654321123456789
// 输出样例：
// yi san wu