#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
struct BigInteger
{
    static const int BASE = 100000000;
    static const int WIDTH = 8;
    vector<int> s;

    BigInteger(long long num = 0) { *this = num; } // 构造函数
    BigInteger operator=(long long num)
    { // 赋值运算符
        s.clear();
        do
        {
            s.push_back(num % BASE);
            num /= BASE;
        } while (num > 0);
        return *this;
    }
    BigInteger operator=(const string &str)
    { // 赋值运算符
        s.clear();
        int x;
        // 若有32位，分成(32-1)/8+1=4块；
        // 若有31位，分成(31-1)/8+1=4块；
        // 若有33位，分成(33-1)/8+1=5块，所有情况通吃，好技巧。
        int len = (str.length() - 1) / WIDTH + 1;
        for (int i = 0; i < len; i++)
        {
            int end = str.length() - i * WIDTH;
            int start = max(0, end - WIDTH);
            // substr()获得字符串s中 从第 位开始的长度为  的字符串
            // 默认时的长度为从开始位置到尾
            // c_str() 以 char* 形式传回 string 内含字符串
            // 如果一个函数要求char*参数，可以使用c_str()方法：
            // string s = "Hello World!";
            // printf("%s", s.c_str()); //输出 "Hello World!"c_str() 以 char* 形式传回 string 内含字符串
            // sscanf()从一个c字符串中读进与指定格式相符的数据.
            sscanf(str.substr(start, end - start).c_str(), "%d", &x);
            s.push_back(x);
        }
        return *this;
    }
    BigInteger operator+(const BigInteger &b) const
    {
        BigInteger c;
        c.s.clear();
        for (int i = 0, g = 0;; i++)
        {
            if (g == 0 && i >= s.size() && i >= b.s.size())
                break;
            int x = g;
            if (i < s.size())
                x += s[i];
            if (i < b.s.size())
                x += b.s[i];
            c.s.push_back(x % BASE);
            g = x / BASE;
        }
        return c;
    }
};

ostream &operator<<(ostream &out, const BigInteger &x)
{
    out << x.s.back();
    for (int i = x.s.size() - 2; i >= 0; i--)
    {
        char buf[20];
        sprintf(buf, "%08d", x.s[i]);
        for (int j = 0; j < strlen(buf); j++)
            out << buf[j];
    }
    return out;
}

istream &operator>>(istream &in, BigInteger &x)
{
    string s;
    if (!(in >> s))
        return in;
    x = s;
    return in;
}

int main()
{
    BigInteger a;
    a = "1111111111";
    a = a + a;
    system("pause");
    return 0;
}
