#include <iostream>
#include <string>
using namespace std;

bool Judge(string s, int P, int A, int T, string a, string b, string c) {
    // 要有PAT
    if (P == string::npos || A == string::npos || T == string::npos)
    {
        return false;
    }
    for (size_t i = 0; i < s.length(); i++)
    {
        // 除了PAT不能有别哒
        if (s[i] != 'P' && s[i] != 'A' && s[i] != 'T')
        {
            return false;
        }
    }
    // 其中 a、 b、 c 均或者是空字符串，或者是仅由字母 A 组成的字符串。
    for (size_t i = 0; i < a.length(); i++)
    {
        if (a[i] != 'A')
        {
            return false;
        } 
    }
    for (size_t i = 0; i < b.length(); i++)
    {
        if (b[i] != 'A')
        {
            return false;
        } 
    }
    for (size_t i = 0; i < c.length(); i++)
    {
        if (c[i] != 'A')
        {
            return false;
        } 
    }

    // 情况2
    // 情况二b一定为A，ac相等
    if (b == "A" && a != c)
    {
        return false;
    }
    // 情况3
    if (c.length() != a.length() * b.length())
    {
        return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        string a, b, c, x;
        cin >> s;
        int P = 0, A = 0, T = 0;
        P = s.find_first_of('P');
        A = s.find_first_of('A');
        T = s.find_first_of('T');
        a = s.substr(0, P);
        b = s.substr(P + 1, T - P - 1); // substr()第二个参数为子字符串长度
        c = s.substr(T + 1, s.length());
        if (Judge(s, P, A, T, a, b, c)) 
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    system("pause");
    return 0;
}
// 题目描述也太晦涩了吧

// 答案正确”是自动判题系统给出的最令人欢喜的回复。本题属于 PAT 的“答案正确”大派送 —— 只要读入的字符串满足下列条件，系统就输出“答案正确”，否则输出“答案错误”。

// 得到“答案正确”的条件是：

// 字符串中必须仅有 P、 A、 T这三种字符，不可以包含其它字符；
// 任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，或者是仅由字母 A 组成的字符串；
// 如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a、 b、 c 均或者是空字符串，或者是仅由字母 A 组成的字符串。
// 现在就请你为 PAT 写一个自动裁判程序，判定哪些字符串是可以获得“答案正确”的。

// 输入格式：
// 每个测试输入包含 1 个测试用例。第 1 行给出一个正整数 n (<10)，是需要检测的字符串个数。接下来每个字符串占一行，字符串长度不超过 100，且不包含空格。

// 输出格式：
// 每个字符串的检测结果占一行，如果该字符串可以获得“答案正确”，则输出 YES，否则输出 NO。

// 输入样例：
// 8
// PAT
// PAAT
// AAPATAA
// AAPAATAAAA
// xPATx
// PT
// Whatever
// APAAATAA
// 输出样例：
// YES
// YES
// YES
// YES
// NO
// NO
// NO
// NO