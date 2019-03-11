// 分治法：快速选择问题 
// 时间复杂度O(n)
#include <iostream>
using namespace std;
struct RecType
{
    int key;
};
int rk;
void QuickSort(RecType R[], int s, int t, int k)
{
    int i = s, j = t;
    RecType tmp;
    if (s < t)
    {
        tmp = R[s];
        while (i != j)
        {
            while (j > i && R[j].key >= tmp.key)
                j--;
            R[i] = R[j];
            while (i < j && R[i].key <= tmp.key)
                i++;
            R[j] = R[i];
        }
        R[i] = tmp;
        if (k > i)
            QuickSort(R, i + 1, t, k);
        else if (k < i)
            QuickSort(R, s, i - 1, k);
        else
            rk = R[k].key;
    }
    rk = R[k].key;
}
int main()
{
    int s = 1, t, k;
    RecType r[100];
    cin >> t >> k;
    for (int i = 1; i <= t; i++)
        cin >> r[i].key;
    QuickSort(r, s, t, k);
    cout << rk << endl;
}