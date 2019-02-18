// 题意：给两棵四分树的先序遍历，求二者合并之后（黑色部分合并）黑色像素的个数。p表示中间结点，f表示黑色（full），e表示白色（empty）
// 算法：先建树，然后统计
// 可以边建图,边画图,如果遇到黑色像素f就画图，如果遇到p就递归建图，一边画一边统计
#include<cstdio>
#include<cstring>

const int len = 32;
const int maxn = 1024 + 10;
char s[maxn];
// buf是图，先在里面画一遍第一个，不清空再画第二个就是相加的图了
int buf[len][len], cnt;

// 把字符串s[p..]导出到以(r,c)为左上角，边长为w的缓冲区中
// 2 1
// 3 4
void draw(const char* s, int& p, int r, int c, int w) { // p要传引用
  char ch = s[p++];
  // 如果是p就有四个子树，每个边长减小一半，最后肯定会遇到黑f
  if(ch == 'p') {
    draw(s, p, r,     c+w/2, w/2); // 1
    draw(s, p, r,     c    , w/2); // 2
    draw(s, p, r+w/2, c    , w/2); // 3
    draw(s, p, r+w/2, c+w/2, w/2); // 4
  } else if(ch == 'f') { // 画黑像素（白像素不画）（递归出口）
    for(int i = r; i < r+w; i++) // 按边长计数
      for(int j = c; j < c+w; j++)
      // 判断是否已经画过了
       if(buf[i][j] == 0) { buf[i][j] = 1; cnt++; }
  }
}

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    memset(buf, 0, sizeof(buf));
    cnt = 0;
    for(int i = 0; i < 2; i++) {
      scanf("%s", s);
      int p = 0;
      draw(s, p, 0, 0, len);
    }
    printf("There are %d black pixels.\n", cnt);
  }
  return 0;
}