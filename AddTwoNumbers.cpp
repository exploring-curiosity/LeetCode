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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res,*temp;
        int val=0,carry=0;
        val=l1->val+l2->val;
        carry=int(val/10);
        res = new ListNode(val%10);
        l1=l1->next;
        l2=l2->next;
        temp=res;
        while(true){
            val=0;
            if(l1==NULL && l2==NULL)
            {
                break;
            }
            if(l1!=NULL)
            {
                val+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL)
            {
                val+=l2->val;
                l2=l2->next;
            }
            val+=carry;
            carry=int(val/10);
            temp->next=new ListNode(val%10);
            temp=temp->next;
        }
        if(carry>0)
        {
            temp->next=new ListNode(carry);
        }
        return res;
    }
};