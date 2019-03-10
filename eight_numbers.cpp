// 八数码，使用STL集合（最好写）
// Rujia Liu
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <set>
using namespace std;

typedef int State[9];
const int MAXSTATE = 1000000;
State st[MAXSTATE], goal;
int dist[MAXSTATE];

set<int> vis;
void init_lookup_table() { vis.clear(); }
int try_to_insert(int s)
{
    int v = 0;
    for (int i = 0; i < 9; i++)
        v = v * 10 + st[s][i];
    if (vis.count(v))
        return 0;
    vis.insert(v);
    return 1;
}
void printArray(int *arr)
{
    int i, j;
    for (i = 0; i < 9; i++)
    {
        if (i % 3 == 0)
            printf("\n");
        printf("%d ", arr[i]);
    }
    printf("\n");
}

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int bfs()
{
    init_lookup_table();
    int front = 1, rear = 2;
    while (front < rear)
    {
        // s是当前状态
        State &s = st[front];
        // 如果找到了返回front
        if (memcmp(goal, s, sizeof(s)) == 0)
        {
            printArray(s);
            return front;
        }
        // 找到0
        int z;
        for (z = 0; z < 9; z++)
            if (!s[z])
                break;
        // 0的坐标
        int x = z / 3, y = z % 3;
        // 移动查找
        for (int d = 0; d < 4; d++)
        {
            int newx = x + dx[d];
            int newy = y + dy[d];
            int newz = newx * 3 + newy;
            // 如果移动有效
            if (newx >= 0 && newx < 3 && newy >= 0 && newy < 3)
            {
                State &t = st[rear];
                memcpy(&t, &s, sizeof(s));
                t[newz] = s[z];
                t[z] = s[newz];
                dist[rear] = dist[front] + 1;
                if (try_to_insert(rear))
                    rear++;
            }
        }
        front++;
    }
    return 0;
}

int main()
{
    for (int i = 0; i < 9; i++)
        scanf("%d", &st[1][i]);
    for (int i = 0; i < 9; i++)
        scanf("%d", &goal[i]);
    int ans = bfs();
    if (ans > 0)
        printf("%d\n", dist[ans]);
    else
        printf("-1\n");
    system("pause");
    return 0;
}