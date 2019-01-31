#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;
const int coeff[3] = {2, 3, 5};
int main()
{
    priority_queue<long long, vector<long long>, greater<long long> > pq;
    set<long long> s;
    pq.push(1);
    s.insert(1);
    for(size_t i = 1;  ; i++)
    {
        long long x = pq.top();
        pq.pop();
        if (i == 1500) {
            cout << x << endl;
            break;
        }
        for(size_t j = 0; j < 3; j++)
        {
            long long x2 = x * coeff[j];
            if(s.count(x2) == 0)
            {
                s.insert(x2);
                pq.push(x2);
            }
        }
    }
    system("pause");
    return 0;
}
