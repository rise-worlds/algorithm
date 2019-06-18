/**
 * Definition for singly-linked list.
 */
#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* temp = head;
        ListNode* fast = temp;
        ListNode* slow = temp;
        while (fast != nullptr && slow != nullptr && fast->next != nullptr && slow->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            // 链表有环
            // 从链表头再开始一个遍历，每次头和当前的交汇点(fast)都往前移动一个
            // 当头等于fast时，代表相遇，此时其为环的入口。
            if (fast == slow) {
                ListNode* hh = temp;
                while (temp != fast) {
                    temp = temp->next;
                    fast = fast->next;
                }
                return temp;
            }
        }
        return nullptr;
    }
};

int main()
{
    std::vector<int> data = {3, 2, 0, -4};
    int cycle = 1;
    ListNode *temp = new ListNode(data[0]);
    ListNode *head = temp, *lock = nullptr;
    if (0 == cycle)
        lock = temp;
    for (int i = 1; i < data.size(); ++i)
    {
        temp->next = new ListNode(data[i]);
        temp = temp->next;
        if (i == cycle)
            lock = temp;
    }
    temp->next = lock;
    lock = nullptr;

    //
    Solution solution;
    lock = solution.detectCycle(head);
    if (lock == nullptr) {
        std::cout << "no cycle" << std::endl;
    } else {
        std::cout << "tail connects to node index " << cycle << std::endl;
    }

    return 0;
}