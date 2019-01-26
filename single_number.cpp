#include <iostream>
#include <cstring>
using namespace std;

int hashtable[10]; // 共10个数字
int main()
{
    char x[] = {"12123566537887449"};  // 9
    memset(hashtable, 0, sizeof(int) * 256);
    for(size_t i = 0; i < strlen(x); i++)
        hashtable[x[i]-'0']++;
    for(size_t i = 0; i < 10; i++)
        if (hashtable[i] == 1)
            cout << i << endl;
    system("pause");
    return 0;
}
// 找出只出现一次的数字，其他均出现k次
// 思路：哈希表
// 第一次出现n次的字符，出现最多次的字符也可用哈希表思路做