#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    // 矩阵宽度
    int n;
    cin >> n;
    int *e = new int[n * n];
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n * n; i++)
        e[i] = i + 1;
    int index = 0;
    int step = n - 1;
    int x = 0, y = 0;
    while (step >= 1)
    {
        for (int i = 0; i < step; i++)
            matrix[x][y++] = e[index++];
        for (int i = 0; i < step; i++)
            matrix[x++][y] = e[index++];
        for (int i = 0; i < step; i++)
            matrix[x][y--] = e[index++];
        for (int i = 0; i < step; i++)
            matrix[x--][y] = e[index++];
        step -= 2;
        x++;
        y++;
    }
    if (n % 2 == 1)
        matrix[x][y] = n * n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%02d ", matrix[i][j]);
        cout << endl;
    }
    system("pause");
    return 0;
}
