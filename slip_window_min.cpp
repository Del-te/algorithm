// 滑动窗口的最小值问题
// 使用单调队列（利用双端队列实现）解决
#include <iostream>
#include <queue>
using namespace std;
int main() {
    int a[] = {5, 2, 6, 8, 10, 7, 4};
    int k = 4;
    int n = 7;
    // 实现单调队列
    deque<int> dq;

    for(int i = 0; i < n; i++) {
        if(i >= k) {
            // 输出单调队列队首元素，该元素即为移动前滑动窗口的最小值
            cout << dq.front() << " ";
            // 如果移动到当前滑动窗口位置后，出去的元素恰好是单调队列最小元素，则出队它
            if(a[i - k] == dq.front()) {
                dq.pop_front();
            }
        }
        // 队列不为空且队列中最后的元素大于当前元素
        // 将队列最后元素出队
        // 因为它不可能成为最小元素了
        while(!dq.empty() && dq.back() > a[i]) {
            dq.pop_back();
        }
        // 当前元素入队
        dq.push_back(a[i]);
    }
    cout << dq.front() << endl;
    system("pause");
    return 0;
}