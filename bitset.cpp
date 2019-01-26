#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    bitset<8> x("10011101");
    bitset<8> a("10101010");
    bitset<8> b("01010101");
    bitset<8> ou, ji, result;
// 交换二进制数的奇偶位
    ou = (x & a);
    ji = (x & b);
    result = ((ou >> 1) ^ (ji << 1)); 
    cout << x << '\n'
         << a << '\n'
         << b << '\n'
         << ou << '\n'
         << ji << '\n'
         << result << '\n'
         << endl;
    cout << "x: " << x << '\n'
         << "x.all(): " << x.all() << '\n'     // x是否全为1
         << "x.any(): " << x.any() << '\n'     // x中是否有某位为1
         << "x.none(): " << x.none() << '\n'   // x中是否没有1
         << "x.size(): " << x.size() << '\n'   // x有几位
         << "x.count(): " << x.count() << '\n' // x中共有几个1
         << "x.flip(): " << x.flip() << '\n'   // x中每位都取反
         << "x.reset(): " << x.reset() << '\n' // x全部置零
         << "x.set(5): " << x.set(5) << '\n' // x除了指定位（从低到高，从0开始数）置为1，其他位置为0
         << "x.to_string(): " << x.to_string() << '\n' // 转为字符串类型
         << "x.to_ulong(): " << x.to_ullong() << endl;  // 转为长整型
        system("pause");
    return 0;
}