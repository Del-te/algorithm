#include <iostream>
#include <map>
#include <queue>
using namespace std;
const int maxt = 1000 + 10;
int main()
{
    int t, kase = 0;
    while (cin >> t && t != 0)
    {
        cout << "Scenario #" << ++kase << endl;
        // 记录所有人的团队编号;
        // team[x]表示编号为x的人所在的团队编号
        map<int, int> team; 
        for (size_t i = 0; i < t; i++)
        {
            int n, x;
            cin >> n;
            while (n--)
            {
                cin >> x;
                team[x] = i;
            }
        }
        // q是团队的队列，而q2[i]是团队i的成员队列
        queue<int> q, q2[maxt]; 
        // 模拟;
        while (true)
        {
            int x;
            char cmd[10];
            cin >> cmd;
            if (cmd[0] == 'S')
            {
                break;
            }
            else if (cmd[0] == 'D')
            {
                int t = q.front();
                cout << q2[t].front() << endl;
                q2[t].pop();
                if (q2[t].empty())
                {
                    q.pop();
                } // 如果这个团体已经没人了，在团体队列里把他弹出
            }
            else if (cmd[0] == 'E')
            {
                cin >> x;
                // x的编号
                int t = team[x];  
                if (q2[t].empty())
                {
                    q.push(t);
                } // 如果长队中还没有这个队的人，团体队列压入他的队
                q2[t].push(x);
            }
        }
        cout << endl;
    }
    // system("pause");
    return 0;
}
