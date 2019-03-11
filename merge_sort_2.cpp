#include <iostream>
#include <cstring>
using namespace std;
int T[20];

void merge(int *A, int *T, int x, int y, int m)
{
    int p1 = x, p2 = m + 1, i = x;
    while (p1 <= m && p2 <= y)
    {
        if (A[p1] <= A[p2])
        {
            T[i++] = A[p1++];
        }
        else
        {
            T[i++] = A[p2++];
        }
    }
    while (p1 <= m)
    {
        T[i++] = A[p1++];
    }
    while (p2 <= y)
    {
        T[i++] = A[p2++];
    }
}
void merge_sort(int *A, int x, int y)
{
    if (y == x)
    {
        return;
    }
    int m = x + (y - x) / 2;
    merge_sort(A, x, m);
    merge_sort(A, m + 1, y);
    merge(A, T, x, y, m);
    for (int i = x; i <= y; i++)
    {
        A[i] = T[i];
    }
}

int main()
{
    int A[9] = {1, 3, 2, 5, 3, 9, 7, 8, 6};
    merge_sort(A, 0, 8);
    for (int i = 0; i < 9; i++)
    {
        cout << A[i] << endl;
    }
    system("pause");
    return 0;
}
