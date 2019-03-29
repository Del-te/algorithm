#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1005;
int a[maxn];
int main()
{
    vector<int> mem;
    int m, n;
    int cnt = 0;
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int j = 0; j < n; j++)
    {
        bool flag = false;
        vector<int>::iterator k = mem.begin();
        for (k = mem.begin(); k != mem.end(); k++)
        {
            if (*k == a[j])
            {
                flag = true;
                break;
            }
        }

        if (mem.size() < 3 || flag == false)
        {

            mem.push_back(a[j]);
            cnt++;
            cout << "*l:" << mem[0] << endl;
            cout << "size:" << mem.size() << endl;
        }

        vector<int>::iterator l = mem.begin();
        if (flag == false)
        {
            mem.erase(l);
            mem.push_back(a[j]);
            cout << "*l:" << *l << endl;
            cout << "size:" << mem.size() << endl;
            cnt++;
        }
    }
    cout << cnt;
    system("pause");
    return 0;
}
