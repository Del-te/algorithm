#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

const int maxn = 256 + 10;

struct Node{
  bool have_value;
  int v;
  Node* left, *right;  // 二叉树递归定义
  Node():have_value(false),left(NULL),right(NULL){}
};
// 首先实例化根节点
Node* root;

Node* newnode() { return new Node(); }

bool failed;
void addnode(int v, char* s) {
  int n = strlen(s);
  Node* u = root;
  for(int i = 0; i < n; i++)
    if(s[i] == 'L') {
      if(u->left == NULL) u->left = newnode();
      u = u->left;
    } else if(s[i] == 'R') {
      if(u->right == NULL) u->right = newnode();
      u = u->right;
    }
  if(u->have_value) failed = true;
  u->v = v;
  u->have_value = true;
}

void remove_tree(Node* u) {
  if(u == NULL) return;
  // 递归析构   
  remove_tree(u->left); 
  remove_tree(u->right);
  delete u;
}

char s[maxn];
bool read_input() {
  failed = false;
  remove_tree(root);
  root = newnode();
  for(;;) {
    if(scanf("%s", s) != 1) return false;
    if(!strcmp(s, "()")) break;
    int v;
    sscanf(&s[1], "%d", &v);
    // strchr()在c字符串中检索字符，返回指向被检索字符的指针，未找到返回NULL
    // 指向字符的指针可以看做是字符串
    addnode(v, strchr(s, ',')+1); 
  }
  return true;
}
// 宽度优先搜索
// https://blog.csdn.net/saltriver/article/details/54428983
bool bfs(vector<int>& ans) {
  queue<Node*> q;
  ans.clear();
  q.push(root);
  while(!q.empty()) {
    Node* u = q.front(); q.pop();
    if(!u->have_value) return false;
    ans.push_back(u->v);
    if(u->left != NULL) q.push(u->left);
    if(u->right != NULL) q.push(u->right);
  }
  return true;
}

int main() {
  vector<int> ans;
  while(read_input()) {
    if(!bfs(ans)) failed = 1;
    if(failed) printf("not complete\n");
    else {
      for(int i = 0; i < ans.size(); i++) {
        if(i != 0) printf(" ");
        printf("%d", ans[i]);
      }
      printf("\n");
    }
  }
  return 0;
}