// 直接模拟最后一个小球路线
// 每个小球落在各个节点上，如果是第奇数次落在此节点，则走左子树，第偶数次走右子树
// 然后接着求下一个节点是第奇数次还是第偶数次，直到求到最底层
#include <cstdio>
int main()
{
    int T, D, I;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &D, &I);
        int k = 1;
        for (int i = 0; i < D - 1; i++)
            if (I % 2)
            {
                // 如果小球是第奇数个落在此节点
                k = k * 2; // 走左子树
                I = (I + 1) / 2; // 是走左子树的第（i+1）/2个小球
            }
            else
            {
                // 如果小球是第偶数个落在此节点
                k = k * 2 + 1; // 走右子树
                I /= 2; // 是走右子树的第i/2个小球
            }
        printf("%d\n", k);
    }
    return 0;
}
// 进制编码。经过模拟几次可以看出，球会让开关形成连续二进制数的表示（根是低位）。
// 当放入第k个球时，开关状态正好是二进制的k，利用模2的余数判断走向即可。
#include <iostream>
using namespace std;

int main()
{
  int n, c, d;
  cin >> n;
  while (n--)
  {
    cin >> d >> c;
    int k = 1;
    while (--d)
    {
      if (c % 2)
        k = k << 1;
      else
        k = (k << 1) + 1;
      c = (c + 1) >> 1;
    }
    cout << k << endl;
  }
  return 0;
}
// 从哈夫曼编码角度理解，结果正好是I-1的二进制逆序，感觉很厉害!

#include<cstdio>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    int D,I;
    while(scanf("%d",&D))
    {
        if(D==-1) break;
        scanf("%d",&I);
        int k=1;//k初始化为1，即最高位为1
        I-=1;   //求I-1的二进制逆序：
        while(--D)
        {
            if(I&1){
                k=(k<<1)+1;
            }else{
                k<<=1;
            }
            I>>=1;
        }
        printf("%d\n", k);
    }
    return 0;
}