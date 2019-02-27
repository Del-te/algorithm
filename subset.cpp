// 生成子集
#include <cstdio>
#include <cstdlib>
using namespace std;
// 打印a[n]的子集s
void print_subset(char *a, int n, int s) 
{
  // 输出二进制表示的s中为1的位
  for (int i = 0; i < n; i++)
  {
    // 1 << i 就是 2的i次方，二进制也就是第i位为1，其他位是0
    if (s & (1 << i)) 
    {
      printf("%c ", a[i]);
    }
  }
}
int main()
{
  const int n = 5;
  char a[n] = {'a', 'b', 'c', 'd', 'e'};
  for (int i = 0; i < (1 << n); i++) // 枚举各子集所对应二进制编码
  {
    print_subset(a, n, i);
    printf("\n");
  }
  system("pause");
  return 0;
}
/*
  把集合用二进制编码表示，全集就是每一位都为1， 例如一个子集就为101100
  把全集定义为ALL_BITS = (1 << N) - 1;
  A的补集就是A ^ ALL_BITS;
  A & B 就是集合的交 
  A | B 就是集合的并
  A ^ B 就是集合的对称差（集合的并减去集合的交）
*/