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
    ListNode (int val)
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

        // construct the linked list
        for (int i = 0; i < n; ++i) {
            int val; cin >> val;
            cur->next = new ListNode(val);
            cur = cur->next;
        }

        // reverse
        ListNode *head = dummy.next;
        ListNode *prev = NULL;
        while (head) {
            ListNode *next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        head = prev;

        // print
        while (head->next) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << head->val << endl;
    }
}