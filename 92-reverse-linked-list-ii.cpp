/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *cur = dummy;
        ListNode *pre, *front, *last;
        for (int i = 1; i <= m - 1; ++i) cur = cur->next;
        pre = cur;
        last = cur->next;
        for (int i = m; i <= n; ++i) {
            cur = pre->next;
            pre->next = cur->next;
            cur->next = front;
            front = cur;
        }
        cur = pre->next;
        pre->next = front;
        last->next = cur;
        return dummy->next;
    }
};