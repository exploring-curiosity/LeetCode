class Solution {
public:
    ListNode* merge(ListNode* a,ListNode* b)
    {
        if(!a) return b;
        if(!b) return a;
        if(a->val<b->val)
        {
            a->next=merge(a->next,b);
            return a;
        }
        b->next=merge(a,b->next);
        return b;
    }
    ListNode* merge_sort(vector<ListNode*>& lists,int b,int e)
    {
        if(b==e)
            return lists[b];
        if(b>e) return NULL;
        int m=(b+e)/2;
        return merge(merge_sort(lists,b,m),merge_sort(lists,m+1,e));
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge_sort(lists,0,lists.size()-1);    
    }
};