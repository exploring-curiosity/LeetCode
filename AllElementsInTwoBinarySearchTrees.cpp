/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> l1,l2;
    void traverse(TreeNode* root,int flag)
    {
        if(root!=NULL)
        {
            traverse(root->left,flag);
            if(flag)
                l1.push_back(root->val);
            else
                l2.push_back(root->val);
            traverse(root->right,flag);
        }
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        traverse(root1,1);
        traverse(root2,0);
        int i=0,j=0;
        vector<int> res;
        while((i<l1.size()) && (j<l2.size()))
        {
            if(l1[i]<l2[j])
                res.push_back(l1[i++]);
            else
                res.push_back(l2[j++]);
        }
        while(i<l1.size())
        {
            res.push_back(l1[i++]);
        }
        while(j<l2.size())
        {
            res.push_back(l2[j++]);
        }
        return res;
    }
};