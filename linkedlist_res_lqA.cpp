// 翻转链表
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode (int val) // 构造函数
    {
        this->val = val;
        this->next = NULL;
    }
};

int main()
{
    int n;
    while (1) {
        cin >> n;
        if (n == -1) break;
        ListNode dummy(0), *cur = &dummy;
        // 链表初始化
        for (int i = 0; i < n; ++i) {
            int val; cin >> val;
            cur->next = new ListNode(val);
            cur = cur->next;
        }
        // 链表翻转
        ListNode *head = dummy.next;
        ListNode *prev = NULL;
        while (head) {
            ListNode *next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        head = prev;
        // 输出链表
        while (head->next) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << head->val << endl;
    }
}