// 贾立威 201710405130
#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = 105;
int a[maxn];

void _bsearch(int l, int r, int c) {
    int m = l + (r - l) / 2;
    if (l == r - 1 && a[l] != c && a[r] != c) {
        cout << "数据没有找到！" << endl;
        cout << "查找边界为第" << l + 1 << "个元素和第" << r + 1 << "个元素" << endl;
        return;
    }

    if (a[m] == c) {
        cout << "查找的数据为数组中第" << m + 1 << "个元素" << endl;
        return;
    } else if (a[m] < c) {
        _bsearch(m, r, c);
    } else if (a[m] > c) {
        _bsearch(l, m, c);
    }
}

int main() {
    int n, c;
    cout << "请输入待查找有序数组大小: ";
    cin >> n;
    cout << "请逐个输入待查找有序数组的元素：" << endl;
    for (size_t i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    cout << "请输入要查找的数据：";
    cin >> c;
    _bsearch(0, n, c);
    system("pause");
    return 0;
}