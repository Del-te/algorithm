#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
vector<int> a;
multiset<int> cnt;
set<int> tmp;
vector<int> b;
int main()
{
    bool flag = true;
    int na, nb;
    cin >> na;
    for (int i = 0; i < na; i++)
    {
        int t;
        cin >> t;
        a.push_back(t);
        cnt.insert(a[i]);
    }
    sort(a.begin(), a.end());
    cin >> nb;
    if (na != nb)
    {
        flag = false;
    }
    for (int i = 0; i < nb; i++)
    {
        int t;
        cin >> t;
        b.push_back(t);
    }
    sort(b.begin(), b.end());
    for (int i = 0; i < na; i++)
    {
        if (a[i] != b[i])
        {
            flag = false;
            break;
        }
    }
    if (flag == true)
    {
        cout << "1" << endl;
    }
    else
    {
        cout << "0" << endl;
    }
    for (int i = 0; i < a.size(); i++)
    {
        if (tmp.count(a[i]) < 1)
        {
            cout << a[i] << " " << cnt.count(a[i]) << endl;
            tmp.insert(a[i]);
        }
    }
    system("pause");
    return 0;
}
