// 分治法：归并排序
#include <iostream>
using namespace std;
void merge_sort(int *A, int x, int y, int *T)
{
    if (y - x > 1)
    {
        int m = x + (y - x) / 2;
        int p1 = x, p2 = m, i = x;
        merge_sort(A, x, m, T);
        merge_sort(A, m, y, T);
        // 巧用短路表达式
        while (p1 < m || p2 < y)
        {
            if (p2 >= y || (p1 < m && A[p1] <= A[p2]))
            {
                // 复制后移动下标
                // 把左边赋给替换数组
                T[i++] = A[p1++]; 
            }
            else
            {
                // 把右边赋给替换数组
                T[i++] = A[p2++];
            }
        }
        // 把替换数组赋回去
        for (i = x; i < y; i++)
        {
            A[i] = T[i];
        }
    }
}
int main()
{
    int A[10] = {1, 3, 5, 4, 2, 7, 9, 8, 11, 13};
    int T[10];
    merge_sort(A, 1, 10, T);
    for (int i = 0; i < 10; i++)
    {
        cout << A[i] << endl;
    }
    system("pause");
    return 0;
}