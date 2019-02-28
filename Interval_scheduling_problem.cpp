// 贪心算法：区间调度问题
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int maxn = 100000;
int N, S[maxn], T[maxn];
// S[i]是任务i的起始时间，T[i]是任务i的结束时间
pair<int, int> itv[maxn]; // 注意pair的语法，pair可以用map头文件引入
int main()
{
    cin >> N;
    for(size_t i = 0; i < N; i++)
    {
        cin >> S[i];
    }
    for(size_t j = 0; j < N; j++)
    {
        cin >> T[j];
    }
    for(size_t k = 0; k < N; k++)
    {
        // 为了让结束时间早的工作排在前面，把T存入first，S存入second
        itv[k].first = T[k]; 
        itv[k].second = S[k];
    }
    // 以结束时间为依据，进行字典序排序
    sort(itv, itv + N);
    // t是最后所选工作的结束时间
    int t = 0;
    // 一共可以进行几个任务
    int ans = 0;
    for(size_t i = 0; i < N; i++)
    {
        if (t < itv[i].second) {
            ans++;
            // 刷新最后所选任务的结束时间
            t = itv[i].first;
        }
    }
    cout << ans << endl;
    system("pause");
    return 0;
}
// 有n项工作，每项工作分别在si开始，ti结束。
// 对每项工作，你都可以选择参加或不参加，
// 但选择了参加某项工作就必须至始至终参加全程参与，
// 即参与工作的时间段不能有重叠(即使开始的时间和结束的时间重叠都不行)。
// 限制条件：
// 1<=n<=100000
// 1<=si<=ti,=109

// 对这个问题，如果使用贪心算法的话，可能有以下几种考虑：
// (1)、每次选取开始时间最早的；
// (2)、每次选取结束时间最早的；
// (3)、每次选取用时最短的；
// (4)、在可选工作中，每次选取与最小可选工作有重叠的部分；
// 对于上面的四种算法，只有算法(2)是正确的，其它的三种都可以找到相应的反例。