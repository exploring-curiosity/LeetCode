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
    ListNode* rev(ListNode* node,int val,int right)
    {
        if(val==right)
        {
            return node;
        }
        ListNode* parent = rev(node->next,val+1,right);
        parent->next = node;
        return node;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *leftnode,*leftbefore,*rightnode,*rightafter,*temp,*prev=NULL;
        temp=head;
        for(int i=1;temp!=NULL;i++)
        {
            if(i==left)
            {
                leftbefore=prev;
                leftnode=temp;   
            }
            if(i==right)
            {
                rightnode=temp;
                rightafter=temp->next;
            }
            prev=temp;
            temp=temp->next;
        }
        leftnode = rev(leftnode,left,right);
        if(leftbefore!=NULL)
            leftbefore->next = rightnode;
        else
            head=rightnode;
        leftnode->next = rightafter;
        return head;
    }
};