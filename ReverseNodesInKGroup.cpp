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
    ListNode* revGrp(ListNode* head,int n, int k) {
        if(n<k)
            return head;
        int i=0;
        ListNode *temp,*prev,*node;
        prev=head;
        node=prev->next;
        while(i<k-1)
        {
            temp=node->next;
            node->next=prev;
            prev=node;
            node=temp;
            i++;
        }
        head->next=revGrp(temp,n-k,k);
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1)
            return head;
        int n=0;
        ListNode* temp=head;
        while(temp)n++,temp=temp->next;
        return revGrp(head,n,k);
    }
};