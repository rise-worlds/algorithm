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
    ListNode* reverseKGroup(ListNode* head, int k) {
        //如果为空，或者只有一个节点，直接返回
        if (head == nullptr || head->next == nullptr) return head;
        //给头节点一个前驱，不用单独为头节点考虑了
        ListNode* headHead = new ListNode(-1);
        headHead->next = head;
        ListNode* pPreNode = headHead;
        ListNode* pEndNode = headHead;
        while (pEndNode->next != nullptr){
            //pEndNode移动到末尾
            for (int i = 0; i < k && pEndNode != nullptr; i++) {
                pEndNode = pEndNode->next;
            }
            if (pEndNode == nullptr){
                break;
            }
            ListNode* pStartNode = pPreNode->next;
            ListNode* pNextNode = pEndNode->next;
            pEndNode->next = nullptr;
            //翻转链表，将头连接到上一个链表的末尾
            pPreNode->next = reverse(pStartNode);
            //末尾要连接到下一个连接的pNextNode，
            pStartNode->next = pNextNode;
            pPreNode = pStartNode;
            pEndNode = pStartNode;
        }
        return headHead->next;
    }

    // 反转链表
    ListNode* reverse(ListNode* pStartNode) {
        if (pStartNode == nullptr || pStartNode->next == nullptr){
            return pStartNode;
        }
        ListNode* pHeadNode = pStartNode;
        ListNode* pNext = pStartNode->next;
        while (pNext != nullptr){
            ListNode* pTempNode = pNext->next;
            // 逐个结点反转
            pNext->next = pHeadNode;
            // 更新指针位置
            pHeadNode = pNext;
            pNext = pTempNode;
        }
        pStartNode->next = nullptr;
        // 返回反转后的头结点
        return pHeadNode;
    }

};