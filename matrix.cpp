#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    int dl;
    cin >> n >> dl;
    vector<int> a(dl);
    vector<int> b(dl);
    for (int i = 0; i < dl; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < dl; i++)
    {
        cin >> b[i];
    }

    int aa[100][100];
    int bb[100][100];
    int c[100][100];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c[i][j] = 0;
        }
    }
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            aa[i][j] = a[index];
            aa[j][i] = a[index++];
        }
    }
    index = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            bb[i][j] = b[index];
            bb[j][i] = b[index++];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                c[i][j] = c[i][j] + (aa[i][k] * bb[k][j]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}

