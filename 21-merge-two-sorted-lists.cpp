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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy = ListNode(-1);  //  创建栈空间对象即可。
        ListNode* prev = &dummy;   // 注意这里需要取地址&
        while(l1 != NULL && l2 != NULL) {
            if(l1->val <= l2->val) {
                prev->next = l1;
                l1 = l1->next;
            } else {
                prev->next = l2;
                l2 = l2->next;
            }
            prev = prev->next;
        }
        prev->next = l1 != NULL ? l1 : l2;

        return dummy.next;
    }
};