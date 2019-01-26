#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int maxn = 30;
vector<int> pile[maxn];
int n;
// 找到a所在的木块堆及所在的高度，以引用的形式返回
void find_block(int a, int &p, int &h)
{
    for (p = 0; p < n; p++)
        for (h = 0; h < pile[p].size(); h++)
            if (pile[p][h] == a)
                return;
}
// 把p堆高度为h及以上的木块整体移动到p2堆的底部
void pile_onto(int p, int h, int p2)
{
    for (size_t i = h; i < pile[p].size(); i++)
        pile[p2].push_back(pile[p][i]);
    pile[p].resize(h);
}
// 把p堆上h高度以上的木块都回归原位
void back_above(int p, int h)
{
    for (size_t i = h + 1; i < pile[p].size(); i++)
    {
        int b = pile[p][i];
        pile[b].push_back(b);
    }
    pile[p].resize(h + 1);
}
void print()
{
    for (size_t i = 0; i < n; i++)
    {
        cout << i << ":";
        for (size_t j = 0; j < pile[i].size(); j++)
            cout  << " " << pile[i][j] ;
        cout << endl;
    }
}
int main()
{
    string s1, s2;
    int a, b;
    cin >> n;
    for (size_t i = 0; i < n; i++)
        pile[i].push_back(i);
    while (cin >> s1 >> a >> s2 >> b)
    {
        int pa, pb, ha, hb;
        find_block(a, pa, ha);
        find_block(b, pb, hb);
        if (pa == pb)
            continue;
        if (s1 == "move") // 提取出命令的共同点
            back_above(pa, ha);
        if (s2 == "onto")
            back_above(pb, hb);
        pile_onto(pa, ha, pb);
    }
    print();
    system("pause");
    return 0;
}
// 1、move a onto b：把木块a、b上的木块放回各自的原位，再把a放到b上；
// 2、move a over b：把a上的木块放回各自的原位，再把a发到含b的堆上；
// 3、pile a onto b：把b上的木块放回各自的原位，再把a连同a上的木块移到b上；
// 4、pile a over b：把a连同a上木块移到含b的堆上。
// 当输入quit时，结束操作并输出0~n-1的位置上的木块情况
// Sample Input 
// 10
// move 9 onto 1
// move 8 over 1
// move 7 over 1
// move 6 over 1
// pile 8 over 6
// pile 8 over 5
// move 2 over 1
// move 4 over 9
// quit
// Sample Output 
//  0: 0
//  1: 1 9 2 4
//  2:
//  3: 3
//  4:
//  5: 5 8 7 6
//  6:
//  7:
//  8:
//  9:
