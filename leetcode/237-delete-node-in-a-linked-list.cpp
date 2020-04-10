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
    void deleteNode(ListNode* node) {
        //把下个节点的值拷贝到当前节点，然后删除下个节点。
        if (node == NULL) return;
        if (node->next == NULL) {
            delete node;
            node = NULL;
            return;
        }
        node->val = node->next->val;
        ListNode *delNode = node->next;
        node->next = delNode->next;
        
        delete delNode;
    }
};