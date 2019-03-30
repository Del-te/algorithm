#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1005;
int a[maxn];

// void debug(vector<int> mem)
// {
//     vector<int>::iterator i = mem.begin();
//     for(i = mem.begin(); i != mem.end(); i++)
//     {
//         cout << *i << endl;
//     }
//     cout << "size:" << mem.size() << endl;
// }
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
        // 内存中是否已存在该值
        bool flag = false;
        // 先查一遍有没有a[j]
        if (mem.size() != 0)
        {
            vector<int>::iterator k = mem.begin();
            for (k = mem.begin(); k != mem.end(); k++)
            {
                if (*k == a[j])
                {
                    flag = true;
                    break;
                }
            }
        }
        // 当储存个数小于三个并且a[j]未存入时直接压入
        if (mem.size() < m && flag == false)
        {
            mem.push_back(a[j]);
            cnt++;
            // debug(mem);
        }
        // 储存个数大于三个时如果a[j]未存入
        else if (flag == false)
        {
            vector<int>::iterator l = mem.begin();
            mem.erase(l);
            mem.push_back(a[j]);
            // debug(mem);
            cnt++;
        }
    }
    cout << cnt;
    system("pause");
    return 0;
}
