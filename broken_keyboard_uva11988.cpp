// 数组模拟链表
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int maxn = 10 + 5;
// 光标位置，光标位于cur号字符之后面
int cur;
// 显示器最后一个字符是next[last]
int last;
// 模拟链表：例如next[0]存的是2，下一个节点就是next[2]
int next[maxn];

// 输入文本，从[1]开始存
char s[maxn];

int main()
{
    while (scanf("%s", s + 1) == 1)
    {
        int n = strlen(s + 1);
        last = cur = 0;
        next[0] = 0;  // 模拟链表初始化
        for (int i = 1; i <= n; i++)
        {
            char ch = s[i];
            if (ch == '[')
                cur = 0;
            else if (ch == ']')
                cur = last;
            // 最初我们需要一个头结点，不妨将它设为0，即Next[0]=0。
            // 头结点只是起到一个标记的作用，不表示真实的位置。
            // 链表中的头结点总是指向链表的第一个元素。然后开始插入元素。
            // 链表中插入元素就两句代码：Next[i]=head;head=i。
            // 第一句表示新元素i的下一个元素指向当前head指向的元素，
            // 第二句话是更新head的指向，指向新的第一个元素i。
            // 当所有元素插入完毕后，只需要从头结点开始，顺着Next数组即可按顺序输出整个链表。
            // 注意，这样的插入实际上是在尾部插入，链表的尾部在不断地变长。
            // 这道题中用cur来当做头结点，通过移动头结点的位置即可实现在链表的不同位置插入新元素。
            // 根据题意，当遇到‘['时，头结点变为0，遇到‘]'时，头结点变为last即可。
            else
            {
                // 链表插入操作
                next[i] = next[cur]; // 新元素i的下一个元素指向当前cur指向的元素
                next[cur] = i; // 更新cur的指向，指向新的第一个元素i
                if (cur == last)
                    last = i; // 更新“最后一个字符”编号
                cur = i;      // 移动光标
            }
        }
        for (int i = next[0]; i != 0; i = next[i])
            printf("%c", s[i]);
        printf("\n");
    }
    system("pause");
    return 0;
}