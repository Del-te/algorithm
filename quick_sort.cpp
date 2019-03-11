// 分治法：快速排序
#include <iostream>
using namespace std;

int partition(int* A, int first, int end)
{
    int i = first, j = end;
    while (i < j)
    {
        while (i < j && A[i] <= A[j])
        {
            j--;
        }
        if (i < j)
        {
            int t = A[i];
            A[i] = A[j];
            A[j] = t;
            i++;
        }
        while (i < j && A[i] <= A[j])
        {
            i++;
        }
        if (i < j)
        {
            int t = A[i];
            A[i] = A[j];
            A[j] = t;
            j--;
        }
    }
    // 每趟排序最后i = j = 中轴
    return i;
}
void quick_sort(int* A, int first, int end)
{
    int pivot;
    if (first < end)
    {
        // 划分，pivot是轴值咋序列中的位置
        pivot = partition(A, first, end);
        // 求解子问题1，对左侧子序列进行快速排序
        quick_sort(A, first, pivot - 1);
        // 求解子问题2，对右侧子序列进行快速排序
        quick_sort(A, pivot + 1, end);
        // 中轴不需要参加排序
    }
}
int main()
{
    int A[9] = {1, 2, 3, 5, 7, 9, 4, 8, 6};
    quick_sort(A, 0, 8);
    for(size_t i = 0; i < 9; i++)
    {
        cout << A[i] << endl;
    }
    
    system("pause");
    return 0;
}
