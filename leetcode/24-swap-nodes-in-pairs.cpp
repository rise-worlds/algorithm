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
    ListNode* swapPairs(ListNode* head) {
        // ListNode* pCur = head;
        // while (pCur != nullptr && pCur->next != nullptr) {
        //     std::swap(pCur->val, pCur->next->val);
        //     if (pCur->next->next == nullptr) break;
        //     pCur = pCur->next->next;
        // }
        // return head;
        ListNode *ret, **last = &ret, *first, *second;
        while ((first = head) && (second = head->next)) {
            *last = second;			
            last = &first->next;	

            head = second->next;
            second->next = first;
        }
        *last = first;

        return ret;
    }
};