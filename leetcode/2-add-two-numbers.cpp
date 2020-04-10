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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l1cur = l1, *l2cur = l2;
        ListNode *tempList = new ListNode(0);
        ListNode *tempRoot = tempList;
        int tempVal = 0, l1val = 0, l2val = 0;
        while (1) {
            // if (carry) ++tempList->val;
            
            if (l1cur != NULL) {
                l1val = l1cur->val;
            } else {
                l1val = 0;
            }
            if (l2cur != NULL) {
                l2val = l2cur->val;
            } else {
                l2val = 0;
            }
            tempVal = tempList->val + l1val + l2val;
            if (tempVal >= 10) {
                tempVal -= 10;
                tempList->next = new ListNode(1);
            } 
            tempList->val = tempVal;
            if ((l1cur != NULL && l1cur->next != NULL) || (l2cur != NULL && l2cur->next != NULL)) {
                if (tempList->next == NULL)
                    tempList->next = new ListNode(0);
            } else {
                break;
            }
            
            if (l1cur != NULL) {
                l1cur = l1cur->next;
            }
            if (l2cur != NULL) {
                l2cur = l2cur->next;
            }
            tempList = tempList->next;
        }
        
        return tempRoot;
    }
};