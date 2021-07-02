/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* node) {
        if(!node)
            return node;
        ListNode* head=node,*temp;
        if(!node->next)
            return node;
        node=node->next;
        head->next=node->next;
        node->next=head;
        head->next=swapPairs(head->next);
        return node;
    }
};