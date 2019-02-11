#include <cstdio>
#include <stack>
using namespace std;
const int MAXN = 1000 + 10;

int n, target[MAXN];

int main()
{
  while (scanf("%d", &n) == 1)
  {
    stack<int> s;
    // 待调整序列中正被处理的编号
    int A = 1;
    // 期望序列中正在处理的编号
    int B = 1;
    for (int i = 1; i <= n; i++)
      scanf("%d", &target[i]);
    int ok = 1;
    while (B <= n)
    {
      // 如果与期望一样直接驶出
      if (A == target[B])
      {
        A++;
        B++;
      }
      // 如果栈顶的车厢与期望车厢一致，从栈里驶出
      else if (!s.empty() && s.top() == target[B])
      {
        s.pop();
        B++;
      }
      // 如果待入栈车厢与栈顶车厢都不满足期望期望车厢
      else if (A <= n)
        s.push(A++);
      // 如果车厢已经全部驶出A还不行就是不能
      else
      {
        ok = 0;
        break;
      }
    }
    // 三目运算符可以用在printf 和 cout 里
    printf("%s\n", ok ? "Yes" : "No");
  }
  return 0;
}