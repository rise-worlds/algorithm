#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;

        ListNode *p = dummyHead;
        ListNode *q = dummyHead;
        for (int i = 0; i <= n; ++i)
        {
            q = q->next;
        }

        while (q)
        {
            p = p->next;
            q = q->next;
        }

        ListNode *delNode = p->next;
        p->next = delNode->next;
        delete delNode;
        delNode = nullptr;

        ListNode *retNode = dummyHead->next;
        delete dummyHead;
        dummyHead = nullptr;

        return retNode;
    }
};

