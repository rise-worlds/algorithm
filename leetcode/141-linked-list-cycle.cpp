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

// 利用快慢指针的原理，同样设置两个指针*fast、*slow都指向单链表的头节点，其中*fast的移动速度是*slow的2倍。
// 如果*fast=NULL，说明该单链表以NULL结尾，不是循环链表；如果*fast=*slow，则快指针追上慢指针，说明该链表是循环链表。
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast, *slow;
        fast = slow = head;
        if (fast == nullptr || fast->next == nullptr) {
            return false;
        }
        fast = fast->next->next;
        while (true) {
            if (fast == nullptr || fast->next == nullptr) {
                return false;
            }
            else if (fast == slow || fast->next == slow) {
                return true;
            } else {
                fast = fast->next->next;
                slow = slow->next;
            }
        }
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
    std::cout << std::boolalpha << solution.hasCycle(head) << std::endl;

    return 0;
}