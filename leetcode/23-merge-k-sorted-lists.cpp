#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len = lists.size();
        if (len == 0) {
            return nullptr;
        }    
        // 将n个链表以中间为对称，合并，即合并 
        while(len>1) {
            for (int i=0; i<len/2; i++) {
                lists[i] = mergeTwoLists(lists[i], lists[len-1-i]);
            }
            len = (len+1)/2;
        }
        return lists[0];
    }
    
    // 合并两个链表
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);
        ListNode* p = head;
        while(l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        if (l1 != nullptr) {
            p->next = l1;
        } else if (l2 != nullptr) {
            p->next = l2;
        }
        return head->next;
    }
};

